#include <windows.h>
#include <iostream>
#include <vector>
#include <ctime>

CRITICAL_SECTION cs;
HANDLE event1, event2;

std::vector<long> arr;
std::vector<long> resultArr;
int K = 0;
int sleepInterval = 0;

bool isPrime(long num) {
    if (num < 2) return false;
    for (long i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

DWORD WINAPI CountElementThread(LPVOID) {
    K = 0;
    for (auto val : arr) {
        if (val > 0) K++;
    }

    SetEvent(event1);
    SetEvent(event2);
    return 0;
}

DWORD WINAPI WorkThread(LPVOID) {
    WaitForSingleObject(event1, INFINITE);

    resultArr.resize(arr.size(), 1);
    int index = 0;

    for (auto val : arr) {
        if (isPrime(val)) {
            if (index < K) {
                resultArr[index++] = val;
            }
        }
        Sleep(sleepInterval);
    }

    EnterCriticalSection(&cs);
    std::cout << "\n[work] Результат обработки (простые числа): ";
    for (auto val : resultArr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    LeaveCriticalSection(&cs);

    return 0;
}

int main() {
    setlocale(LC_ALL, "ru");
    InitializeCriticalSection(&cs);

    srand((unsigned)time(NULL));

    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    arr.resize(size);
    for (auto& val : arr) {
        val = rand() % 100 - 50;
    }

    std::cout << "Исходный массив: ";
    for (auto val : arr) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "Введите интервал сна (мс) после обработки одного элемента: ";
    std::cin >> sleepInterval;

    event1 = CreateEvent(NULL, FALSE, FALSE, NULL);
    event2 = CreateEvent(NULL, FALSE, FALSE, NULL);

    HANDLE hThreadCount = CreateThread(NULL, 0, CountElementThread, NULL, 0, NULL);
    HANDLE hThreadWork = CreateThread(NULL, 0, WorkThread, NULL, 0, NULL);

    WaitForSingleObject(event2, INFINITE);
    std::cout << "[main] Кол-во положительных элементов: " << K << std::endl;

    WaitForSingleObject(hThreadCount, INFINITE);
    WaitForSingleObject(hThreadWork, INFINITE);

    CloseHandle(event1);
    CloseHandle(event2);
    CloseHandle(hThreadCount);
    CloseHandle(hThreadWork);
    DeleteCriticalSection(&cs);

    return 0;
}
