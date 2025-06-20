#include "functions.h"

std::vector<int> getMultiplesOfFive(const int* arr, int size) {
    std::vector<int> result;
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 5 == 0) {
            result.push_back(arr[i]);
        }
    }
    return result;
}
