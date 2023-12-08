#include <boost/multiprecision/cpp_int.hpp>
#include <boost/random.hpp>
#include <boost/random/random_device.hpp>
#include <fmt/core.h>
#include <iostream>
#include <random>

int main(int argc, const char* argv[]) {

    namespace mp = boost::multiprecision;

    mp::cpp_int random_val;
    do {
        if (argc == 1) {
            std::cout << "Enter the Upper limit: ";
            std::cin >> random_val;
        } else {
            std::string random = argv[1];
            random_val = mp::cpp_int(random);
        }
        if (random_val == 0) {
            std::cout << "Upper limit cannot be 0 or less than 0\n";
            return -1;
        }
    } while (random_val == 0 || random_val < 0);

    boost::random::random_device gen;
    boost::random::uniform_int_distribution<mp::cpp_int> ui(1, random_val);

    mp::cpp_int y = ui(gen);
    std::cout << y << "\n";
    return 0;
}
