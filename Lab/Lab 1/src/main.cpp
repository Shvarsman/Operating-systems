#include <windows.h>
#include <iostream>
#include "functions.h"
using namespace std;

struct structure { 
    int* arr;
    int size;
};

DWORD WINAPI f(LPVOID lpParam) { 
    structure* s = (structure*)lpParam; 
    vector<int> multiples = getMultiplesOfFive(s->arr, s->size);
    cout << "Elements kratnye 5: ";
    for (int num : multiples) {
        cout << num << " ";
    }
    cout << endl;
    return 0; 
}

int main(){ 
    int size;
    cout << "Enter massive size: ";
    cin >> size;
    cout << "Enter " << size << " numbers: ";
    int* arr = new int[size];
    for (int i = 0; i < size; i++) cin >> arr[i];
    cout<<"Enter time for suspend: ";
    int time;
    cin >> time;

    structure* s = new structure;
    s->arr = arr;
    s->size = size;

    HANDLE worker;
    DWORD IDThread;
    worker = CreateThread(NULL,0, f,(LPVOID)s,0,&IDThread);   

    Sleep(time);
    SuspendThread(worker);
    ResumeThread(worker);
    cout << "bbbbb" << endl;
    WaitForSingleObject(worker, INFINITE);

    delete[] arr;
    delete s;
    CloseHandle(worker);
    return 0;
}
