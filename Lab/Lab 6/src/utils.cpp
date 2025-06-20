#include "utils.h"

bool isValidString(const std::string& str, char A, char B) {
    for (char c : str) {
        if (c < A || c > B) {
            return false;
        }
    }
    return true;
}

long long multiplyLengths(const std::vector<std::string>& strings) {
    long long result = 1;
    for (const auto& s : strings) {
        result *= static_cast<long long>(s.size());
    }
    return result;
}
