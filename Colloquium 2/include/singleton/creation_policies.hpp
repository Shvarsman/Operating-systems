// creation_policies.hpp
#pragma once

template <typename T>
struct CreateUsingNew {
    static T* Create() {
        return new T();
    }
    static void Destroy(T* pObj) {
        delete pObj;
    }
};

template <typename T>
struct CreateStatic {
    union MaxAlign {
        char data[sizeof(T)];
        long double align_;
    };

    static T* Create() {
        static MaxAlign storage;
        return new (&storage) T();
    }

    static void Destroy(T* pObj) {
        pObj->~T();
    }
};
