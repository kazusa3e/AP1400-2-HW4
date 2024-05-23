#include "shared_ptr.h"
template <typename T>
SharedPtr<T>::SharedPtr() {
    rc_ = new ReferenceCounter;
    rc_->ref_count = 1;
    rc_->resource = nullptr;
}

template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr &other) {
    rc_ = other.rc_;
    rc_->ref_count += 1;
}

template <typename T>
SharedPtr<T>::~SharedPtr() {
    rc_->ref_count -= 1;
    if (rc_->ref_count == 0) {
        delete rc_->resource;
        rc_->resource = nullptr;
    }
}

template <typename T>
SharedPtr<T>::SharedPtr(T *ptr) {
    rc_ = new ReferenceCounter;
    rc_->ref_count = 1;
    rc_->resource = ptr;
}

template <typename T>
SharedPtr<T> &SharedPtr<T>::operator=(const SharedPtr &other) {
    if (this == &other) return *this;
    rc_->ref_count -= 1;
    if (rc_->ref_count == 0) {
        delete rc_->resource;
        rc_->resource = nullptr;
    }
    rc_ = other.rc_;
    rc_->ref_count += 1;
    return *this;
}

template <typename T>
std::size_t SharedPtr<T>::use_count() const {
    return rc_->ref_count;
}

template <typename T>
T *SharedPtr<T>::get() const {
    return rc_->resource;
}

template <typename T>
inline T &SharedPtr<T>::operator*() const {
    return *(rc_->resource);
}

template <typename T>
inline T *SharedPtr<T>::operator->() const {
    return rc_->resource;
}

template <typename T>
void SharedPtr<T>::reset() {
    rc_->ref_count -= 1;
    if (rc_->ref_count == 0) {
        delete rc_->resource;
        rc_->resource = nullptr;
    }
}

template <typename T>
void SharedPtr<T>::reset(T *ptr) {
    rc_->ref_count -= 1;
    if (rc_->ref_count == 0) {
        delete rc_->resource;
        rc_->resource = nullptr;
    }
    rc_->resource = ptr;
    rc_->ref_count = 1;
}

template <typename T>
SharedPtr<T> make_shared(T val) {
    return SharedPtr<T>{new T{val}};
}

template <typename T>
inline SharedPtr<T>::operator bool() const {
    return !!(rc_->resource);
}