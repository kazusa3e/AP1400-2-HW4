#ifndef SHARED_PTR
#define SHARED_PTR

#include <cstddef>

template <typename T>
class SharedPtr {
public:
    struct ReferenceCounter {
        std::size_t ref_count;
        T *resource;
    };

    SharedPtr();
    SharedPtr(const SharedPtr &other);
    ~SharedPtr();
    explicit SharedPtr(T *ptr);
    SharedPtr &operator=(const SharedPtr &other);
    inline operator bool() const;

    std::size_t use_count() const;
    T *get() const;
    inline T &operator*() const;
    inline T *operator->() const;
    void reset();
    void reset(T *ptr);

private:
    ReferenceCounter *rc_;
};

#include "shared_ptr.hpp"

template <typename T>
SharedPtr<T> make_shared(T val);

#endif  // SHARED_PTR