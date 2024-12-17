package main

import (
	"crypto/rand"
	"fmt"
	"math/big"
	"os"
)

func main() {
	var arg string

	if len(os.Args) >= 2 {
		arg = os.Args[1]
	} else {
		fmt.Printf("Enter the Upper limit: ")
		fmt.Scanf("%s", &arg)
	}

	arg_num, ok := new(big.Int).SetString(arg, 10)

	if !ok {
		fmt.Println("Please enter a number")
		os.Exit(1)
	}
	randInt, err := rand.Int(rand.Reader, arg_num)
	if err != nil {
		_ = fmt.Errorf("An error occured while reading the input")
		os.Exit(1)
	}
	ans := new(big.Int)
	ans = ans.Add(randInt, big.NewInt(1))
	fmt.Printf("Random number between 1 and %s: %v\n", arg, ans)
}
