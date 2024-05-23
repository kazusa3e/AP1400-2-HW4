#ifndef UNIQUE_PTR
#define UNIQUE_PTR

#include <iostream>

template <typename T>
class UniquePtr {
public:
    UniquePtr() : p_(nullptr) {}
    explicit UniquePtr(T *ptr) : p_(ptr) {}
    UniquePtr(const UniquePtr &) = delete;
    UniquePtr &operator=(const UniquePtr &) = delete;
    UniquePtr(UniquePtr &&) = delete;
    UniquePtr &operator=(UniquePtr &&) = delete;
    ~UniquePtr();

    inline T *get() const;
    inline T &operator*() const;
    inline T *operator->() const;
    inline operator bool() const;
    void reset();
    void reset(T *ptr);
    T *release();

private:
    T *p_;
};

template <typename T>
inline UniquePtr<T> make_unique(T val);

#include "unique_ptr.hpp"

#endif  // UNIQUE_PTR