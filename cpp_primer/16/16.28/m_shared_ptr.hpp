#ifndef _M_SHARED_PTR_H
#define _M_SHARED_PTR_H

#include<functional>

template<class T> class m_shared_ptr;

template<class T>
void swap(m_shared_ptr<T> &, m_shared_ptr<T> &);

template<class T>
class m_shared_ptr {
    friend void swap<T>(m_shared_ptr<T> &, m_shared_ptr<T> &);
public:
    m_shared_ptr() : ptr(nullptr), del(nullptr), count(new size_t(1)) {}
    explicit m_shared_ptr(T *p) : ptr(p), del(nullptr), count(new size_t(1)) {}
    m_shared_ptr(T *p, std::function(void(T *)) &d) : ptr(p), del(d), count(new size_t(1)) {}    
    m_shared_ptr(const m_shared_ptr &q) : ptr(q.ptr), del(q.del), count(q.count) { ++*count; }

    ~m_shared_ptr() {
        decrement_and_destroy();
    }
    
    m_shared_ptr &operator=(const m_shared_ptr &rhs) {
        if(this != &rhs) {
            ++*rhs.count;
            decrement_and_destroy();
            ptr = rhs.ptr;
            count = rhs.count;
            del = rhs.del;
        }
        return *this;
    }

    void swap(m_shared_ptr &rhs) {
        ::swap(*this, rhs);
    }

    explicit operaotr bool() const {
        return ptr != nullptr;
    }

    T &operator*() {
        return *ptr;
    }

    const T&operator*() const {
        return *ptr;
    }

    T *operator->() {
        return ptr;
    }

    const T *operator->() const {
        return ptr;
    }

    T *get() {
        return ptr;
    }

    bool unique() {
        if((*count) == 1) return true;
        else return false;
    }

    size_t use_count() {
        return *count;
    }

    void reset() {
        decrement_and_destroy();
    }

    void reset(T *q) {
        decrement_and_destroy();
        ptr = q;
        count = new size_t(1);
        del = nullptr;
    }

    void reset(T *q, std::function<void(T *)> &d) {
        decrement_and_destroy();
        ptr = q;
        count = new size_t(1);
        del = d;
    }

private:
    T *ptr;
    std::function<void(T *)> del;
    size_t *count;
    void decrement_and_destroy() {
        if(ptr && 0 == --*count) {
            del ? del(ptr) : delete ptr;
            delete count;
        }
        else if(!ptr) {
            delete count;
        }
        count = nullptr;
        ptr = nullptr;
        del = nullptr;
    }
};

template<class T>
inline void swap(m_shared_ptr<T> &lsh, m_shared_ptr<T> &rhs) {
    using std::swap;
    swap(lhs.ptr, rhs.ptr);
    swap(lhs.del, rhs.del);
    swap(lhs.count, rhs.count);
}

#endif