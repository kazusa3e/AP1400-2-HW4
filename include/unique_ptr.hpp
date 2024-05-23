template <typename T>
inline UniquePtr<T> make_unique(T val) {
    return UniquePtr<T>{new T(val)};
}

template <typename T>
UniquePtr<T>::~UniquePtr() {
    if (p_ != nullptr) delete p_;
    p_ = nullptr;
}

template <typename T>
inline T* UniquePtr<T>::get() const {
    return p_;
}

template <typename T>
inline T &UniquePtr<T>::operator*() const {
    return *p_;
}

template <typename T>
inline T *UniquePtr<T>::operator->() const {
    return p_;
}

template <typename T>
inline UniquePtr<T>::operator bool() const {
    return !!(p_);
}

template <typename T>
void UniquePtr<T>::reset() {
    if (p_ != nullptr) delete p_;
    p_ = nullptr;
}

template <typename T>
void UniquePtr<T>::reset(T *ptr) {
    if (p_ != nullptr) delete p_;
    p_ = ptr;
}

template <typename T>
T *UniquePtr<T>::release() {
    T* ret = p_;
    p_ = nullptr;
    return ret;
}