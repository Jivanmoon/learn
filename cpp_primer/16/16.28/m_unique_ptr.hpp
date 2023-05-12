#ifndef MY_UNIQUE_PTR_H
#define MY_UNIQUE_PTR_H
#include<memory>
template<typename T, typename D> class my_unique_ptr;

template<typename T, typename D>
void swap(my_unique_ptr<T, D> &lhs, my_unique_ptr<T, D> &rhs) {
	using std::swap;
	swap(lhs.ptr, rhs.ptr);
}

template<typename T, typename D = std::default_delete<T>>
class my_unique_ptr {
	friend void swap<T, D>(my_unique_ptr &, my_unique_ptr &);
public:
	my_unique_ptr() :
		ptr(nullptr), del(D()) { }
	my_unique_ptr(T *);
	my_unique_ptr(T *, const D &);
	my_unique_ptr(const D &);
	my_unique_ptr(my_unique_ptr &&)noexcept;
	my_unique_ptr &operator=(my_unique_ptr &&)noexcept;
	my_unique_ptr &operator=(nullptr_t)noexcept;
	T *release();
	void reset();
	void reset(T *);
	explicit operator bool() const{
		return ptr != nullptr;
	}
	T &operator*() const {
		return *ptr;
	}
	T *operator->() const {
		return ptr;
	}
	T *get() const {
		return ptr;
	}
	void swap(my_unique_ptr &lhs) {
		using std::swap;
		swap(ptr, lhs.ptr);
	}
	~my_unique_ptr();
private:
	T *ptr;
	std::function<void(T *)> del;
};

template<typename T, typename D>
my_unique_ptr<T, D>::my_unique_ptr(T *rhs) :
	ptr(rhs), del(D()) { }

template<typename T, typename D>
my_unique_ptr<T, D>::my_unique_ptr(T *rhs, const D &deleter) :
	ptr(rhs), del(deleter) { }

template<typename T, typename D>
my_unique_ptr<T, D>::my_unique_ptr(const D &deleter) :
	ptr(nullptr), del(deleter) { }

template<typename T, typename D>
my_unique_ptr<T, D>::my_unique_ptr(my_unique_ptr &&rhs) noexcept :
	ptr(rhs.ptr), del(rhs.del) {
	rhs.ptr = nullptr;
}

template<typename T, typename D>
my_unique_ptr<T, D> &my_unique_ptr<T, D>::operator=(my_unique_ptr &&rhs) noexcept {
	if (this != &rhs) {
		reset(rhs.ptr);
		rhs.ptr = nullptr;
	}
	return *this;
}

template<typename T, typename D>
my_unique_ptr<T, D> &my_unique_ptr<T, D>::operator=(nullptr_t) noexcept {
	reset();
	return *this;
}

template<typename T, typename D>
T *my_unique_ptr<T, D>::release() {
	T *ret = ptr;
	ptr = nullptr;
	return ret;
}

template<typename T, typename D>
void my_unique_ptr<T, D>::reset() {
	if (ptr) del(ptr);
	ptr = nullptr;
}

template<typename T, typename D>
void my_unique_ptr<T, D>::reset(T *rhs) {
	if (ptr) del(ptr);
	ptr = rhs;
}

template<typename T, typename D>
my_unique_ptr<T, D>::~my_unique_ptr() {
	if (ptr) del(ptr);
	ptr = nullptr;
}

#endif
