#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

bool hasZeroInBinary(__int16 num) {
    while (num > 0) {
        if ((num & 1) == 0) {
            return true;
        }
        num >>= 1;
    }
    return false;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Not enough arguments" << std::endl;
        return 1;
    }

    int size = std::atoi(argv[1]);
    std::vector<__int16> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = static_cast<__int16>(std::atoi(argv[i + 2]));
    }

    std::cout << "Positive elements without 0 in binary representation: ";
    for (__int16 num : arr) {
        if (num > 0 && !hasZeroInBinary(num)) {
            std::cout << num << " ";
        }
    }
    std::cout << std::endl;
        std::cout << std::endl;
    int a;
    std::cin >> a;
    return 0;
}
