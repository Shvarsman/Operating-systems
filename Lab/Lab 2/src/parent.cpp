#include <windows.h>
#include <iostream>
#include <string>
#include <vector>

int main() {
    setlocale(LC_ALL, "ru");
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    std::vector<int> arr(size);
    std::cout << "Введите элементы: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    std::string commandLine = "Child.exe " + std::to_string(size);
    for (int num : arr) {
        commandLine += " " + std::to_string(num);
    }

    std::wstring commandLineW(commandLine.begin(), commandLine.end());

    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (CreateProcessW(NULL, const_cast<wchar_t*>(commandLineW.c_str()), NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)) {
        SetConsoleTitleW(L"Мой новый заголовок окна");

        std::string commandLine = "Count.exe " + std::to_string(size);
        for (int num : arr) {
            commandLine += " " + std::to_string(num);
        }

        std::wstring commandLineW(commandLine.begin(), commandLine.end());

        STARTUPINFO siCount;
        PROCESS_INFORMATION piCount;
        ZeroMemory(&siCount, sizeof(siCount));
        siCount.cb = sizeof(siCount);
        ZeroMemory(&piCount, sizeof(piCount));

        if (CreateProcessW(NULL, const_cast<wchar_t*>(commandLineW.c_str()), NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &siCount, &piCount)) {
            SetConsoleTitleW(L"Мой новый заголовок окна");

            WaitForSingleObject(piCount.hProcess, INFINITE);

            //TerminateProcess(pi.hProcess, 0);

            CloseHandle(piCount.hProcess);
            CloseHandle(piCount.hThread);
        }
        else {
            std::cerr << "Ошибка создания процесса" << std::endl;
        }
    
        WaitForSingleObject(pi.hProcess, INFINITE);

        //TerminateProcess(pi.hProcess, 0);

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    else {
        std::cerr << "Ошибка создания процесса" << std::endl;
    }

    ExitProcess(0);
}
