import sys
import random


def main():
    if len(sys.argv) < 2:
        upper_limit = input("Enter the Upper limit: ").strip()
    else:
        upper_limit = sys.argv[1]
    try:
        upper_limit = int(upper_limit)
        random_biguint = random.randint(1, upper_limit)
        print(f"Random number between 1 and {upper_limit}: {random_biguint}")
    except:
        print("Please enter a valid upper range.", file=sys.stderr)


if __name__ == "__main__":
    main()
