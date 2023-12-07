#include <fmt/core.h>
#include <random>
#include <scn/scn.h>

using fmt::print;

int main(int argc, const char* argv[]) {

    int random_val;
    do {
        if (argc == 1) {
            print("Enter the Upper limit: ");
            auto result = scn::prompt("Write an integer: ", "{}", random_val);
        } else {
            random_val = std::stoi(argv[1]);
        }
        if (random_val == 0 || random_val < 0) {
            print("Upper limit cannot be 0 or less than 0\n");
        }
    } while (random_val == 0 || random_val < 0);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, random_val);

    print("Random Number generated between 1 and {}: {}\n", random_val,
          dis(gen));

    return 0;
}