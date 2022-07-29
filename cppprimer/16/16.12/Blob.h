#ifndef _BLOB_H_
#define _BLOB_H_

#include<string>
#include<vector>
#include<memory>
#include <initializer_list>

template<class> class BlobPtr;

template<class> class Blob;

template<class T>
bool operator==(const Blob<T> &, const Blob<T> &);

template<class T>
bool operator!=(const Blob<T> &, const Blob<T> &);

template<class T>
bool operator<(const Blob<T> &lhs, const Blob<T> &rhs);

template<class T>
bool operator>(const Blob<T> &lhs, const Blob<T> &rhs);

template<class T>
class Blob {
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob &, const Blob &);
    friend bool operator!=<T>(const Blob &, const Blob &);
    friend bool operator< <T>(const Blob &lhs, const Blob &rhs);
    friend bool operator> <T>(const Blob &lhs, const Blob &rhs);
public:
    typedef typename std::vector<T>::size_type size_type;
    Blob();
    Blob(std::initializer_list<T> li);
    Blob(const Blob &rhs);

    Blob &operator=(const Blob &rhs);

    T &operator[](size_type i);
    const T &operator[](size_type i) const;

    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}

    //添加和删除元素
    void push_back(const T &s) {data->push_back(s);}
    void pop_back();  

    //元素访问
    //常量对象只能调用常量成员函数
    T &front();
    const T &front() const;
    T &back();
    const T &back() const;

    BlobPtr<T> begin();
    BlobPtr<T> end();

private:
    std::shared_ptr<std::vector<T>> data;
    //如果data[i]不合法，抛出一个异常
    void check(size_type i, const std::string &msg) const;
};

template<class T>
bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);
template<class T>
bool operator!=(const BlobPtr<T> &, const BlobPtr<T> &);
template<class T>
bool operator<(const BlobPtr<T> &, const BlobPtr<T> &);
template<class T>
bool operator>(const BlobPtr<T> &, const BlobPtr<T> &);
template<class T>

class BlobPtr {
    friend bool operator==<T>(const BlobPtr &, const BlobPtr &);
    friend bool operator!=<T>(const BlobPtr &, const BlobPtr &);
    friend bool operator< <T>(const BlobPtr &, const BlobPtr &);
    friend bool operator> <T>(const BlobPtr &, const BlobPtr &);
public:
    BlobPtr(): curr(0) {}
    BlobPtr(Blob<T> &a, size_t sz = 0): wptr(a.data), curr(sz) {}
    T &deref() const;

    T &operator[](size_t n) {
        check(n, "n is an invalid arguement");
        return (*wptr.lock())[n];
    }

    const T &operator[](size_t n) const {
        check(n, "n is an invalid arguement");
        return (*wptr.lock())[n];
    }

    BlobPtr &operator++();
    BlobPtr &operator--();
    BlobPtr operator++(int);
    BlobPtr operator--(int);

    BlobPtr &operator+=(int n);
    BlobPtr &operator-=(int n);
    BlobPtr operator+(int n) const;
    BlobPtr operator-(int n) const;

    T &operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    T *operator->() const {
        return &(this->operator*());
    }

private:
    std::shared_ptr<std::vector<T>>
        check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};



// Blob
template <class T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {}

template <class T>
Blob<T>::Blob(std::initializer_list<T> li) : data(std::make_shared<std::vector<T>>(li)) {}

template <class T>
Blob<T>::Blob(const Blob &rhs) : data(std::make_shared<std::vector<T>>(*rhs.data)) {}

template <class T>
Blob<T> &Blob<T>::operator=(const Blob &rhs) {
    data = std::make_shared<std::vector<T>>(*rhs.data);
    return *this;
}

template <class T>
T &Blob<T>::operator[](size_type i) {
    check(i, "n is an invalid arguement");
    return (*data)[i];
}

template <class T>
const T &Blob<T>::operator[](size_type i) const {
    check(i, "n is an invalid arguement");
    return (*data)[i];
}

template <class T>
void Blob<T>::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template <class T>
T &Blob<T>::back() {
    check(0, "back on emtpy Blob");
    return data->back();
}

template <class T>
const T &Blob<T>::back() const {
    check(0, "back on emtpy Blob");
    return data->back();
}

template <class T>
T &Blob<T>::front() {
    check(0, "front on emtpy Blob");
    return data->front();
}

template <class T>
const T &Blob<T>::front() const {
    check(0, "front on emtpy Blob");
    return data->front();
}

template <class T>
void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <class T>
BlobPtr<T> Blob<T>::begin() { return BlobPtr<T>(*this); }

template<class T>
BlobPtr<T> Blob<T>::end() {
    auto ret = BlobPtr<T>(*this, data->size());
    return ret;
}

template<class T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
    return *(lhs.data) == *(rhs.data);
}

template<class T>
bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs) {
    return !(lhs == rhs);
}

template<class T>
bool operator<(const Blob<T> &lhs, const Blob<T> &rhs) {
    return *(lhs.data) < *(rhs.data);
}

template<class T>
bool operator>(const Blob<T> &lhs, const Blob<T> &rhs) {
    return *(rhs.data) < *(lhs.data);
}

// BlobPtr
template<class T>
std::shared_ptr<std::vector<T>>
BlobPtr<T>::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound BlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

template<class T>
T &BlobPtr<T>::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

template<class T>
BlobPtr<T> &BlobPtr<T>::operator++() {
    check(curr, "increment past end of BlobPtr");
    ++curr;
    return *this;
}

template<class T>
BlobPtr<T> &BlobPtr<T>::operator--() {
    --curr;
    check(curr, "decrement past begin of BlobPtr");
    return *this;
}

template<class T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template<class T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
    BlobPtr ret = *this;
    --*this;
    return ret;
}

template<class T>
BlobPtr<T> &BlobPtr<T>::operator+=(int n) {
    curr += n;
    check(curr, "out of range");
    return *this;
}

template<class T>
BlobPtr<T> &BlobPtr<T>::operator-=(int n) {
    curr -= n;
    check(curr, "out of range");
    return *this;
}

template<class T>
BlobPtr<T> BlobPtr<T>::operator+(int n) const {
    BlobPtr ret = *this;
    ret += n;
    return ret;
}

template<class T>
BlobPtr<T> BlobPtr<T>::operator-(int n) const {
    BlobPtr ret = *this;
    ret -= n;
    return ret;
}

template<class T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    if (lhs.wptr.lock() != rhs.wptr.lock()) {
		throw std::runtime_error("ptrs to different Blobs!");
	}
    return lhs.curr == rhs.curr;
}

template<class T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return !(lhs == rhs);
}

template<class T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    if (lhs.wptr.lock() != rhs.wptr.lock()) {
		throw std::runtime_error("ptrs to different Blobs!");
	}
    return lhs.curr < rhs.curr;
}

template<class T>
bool operator>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return rhs < lhs;
}


#endif