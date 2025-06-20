#include <iostream>
#include <windows.h>

void printFibonacci(int count) {
    int a = 0, b = 1;
    for (int i = 0; i < count; i++) {
        std::cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
    std::cout << std::endl;
}

int main() {
    const int fibonacciCount = 10;
    printFibonacci(fibonacciCount);
    std::cout << std::endl;
    int a;
    std::cin >> a;
    ExitProcess(0);
}
