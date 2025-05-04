// lifetime_policies.hpp
#pragma once

#include <cstdlib>

template <typename T>
struct DefaultLifetime {
    static void ScheduleDestruction(T*, void (*pFun)()) {
        std::atexit(pFun);
    }
};

template <typename T>
struct NoDestroy {
    static void ScheduleDestruction(T*, void (*)()) {}
};
