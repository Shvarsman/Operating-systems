#include <iostream>
#include "singleton/singleton.hpp"

class MyService {
public:
    void DoSomething() {
        std::cout << "Doing something!" << std::endl;
    }
};

using MySingleton = singleton::ThreadSafeSingleton<MyService>;

int main() {
    MySingleton::Instance().DoSomething();
    return 0;
}
