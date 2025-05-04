// singleton.hpp
#pragma once

#include "threading_models.hpp"
#include "creation_policies.hpp"
#include "lifetime_policies.hpp"

namespace singleton {

template <
    typename T,
    template <typename> class CreationPolicy = CreateUsingNew,
    template <typename> class LifetimePolicy = DefaultLifetime,
    typename ThreadingModel = StdMutex
>
class Singleton {
public:
    static T& Instance() {
        static T* pInstance = nullptr;
        if (!pInstance) {
            typename ThreadingModel::Lock lock;
            if (!pInstance) {
                pInstance = CreationPolicy<T>::Create();
                LifetimePolicy<T>::ScheduleDestruction(pInstance, &DestroySingleton);
            }
        }
        return *pInstance;
    }

private:
    static void DestroySingleton() {
        CreationPolicy<T>::Destroy(pInstance_);
        pInstance_ = nullptr;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static T* pInstance_;
};

// Инициализация статического члена
template <typename T, template <typename> class CP, template <typename> class LP, typename TM>
T* Singleton<T, CP, LP, TM>::pInstance_ = nullptr;

// Алиасы для удобства
template <typename T>
using ThreadSafeSingleton = Singleton<T, CreateUsingNew, DefaultLifetime, StdMutex>;

template <typename T>
using NonThreadSafeSingleton = Singleton<T, CreateUsingNew, DefaultLifetime, NoThreading>;

} // namespace singleton
