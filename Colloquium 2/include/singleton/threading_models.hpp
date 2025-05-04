// threading_models.hpp
#pragma once

#include <mutex>

namespace singleton {

struct NoThreading {
    struct Lock { Lock() {} };
};

struct StdMutex {
    static std::mutex mtx;
    struct Lock {
        Lock() { mtx.lock(); }
        ~Lock() { mtx.unlock(); }
    };
};

} // namespace singleton
