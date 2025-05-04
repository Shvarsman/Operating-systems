# Modern C++ Singleton with Orthogonal Policies

This project implements a flexible and extensible Singleton pattern using orthogonal strategies as described in Andrei Alexandrescu's book *"Modern C++ Design"*.

## Features

- ✔️ Thread-safe strategy (`StdMutex`)
- ✔️ Thread-unsafe strategy (`NoThreading`)
- ✔️ Creation via `new` or static storage (`CreateUsingNew`, `CreateStatic`)
- ✔️ Customizable lifetime management (`DefaultLifetime`, `NoDestroy`)

## Usage

```cpp
class MyService { /* ... */ };

using MySingleton = singleton::ThreadSafeSingleton<MyService>;
MySingleton::Instance().DoSomething();
```

## Build

```bash
mkdir build && cd build
cmake ..
make
./example
```
