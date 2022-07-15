#include<algorithm>
#include "StrVec.h"
using std::string;
using std::initializer_list;
using std::pair;
using std::allocator;

void StrVec::push_back(const string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string *, string *>
StrVec::alloc_n_copy(const string *b, const string *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if(elements) {
        std::for_each(elements, first_free, [&](string &p){
            alloc.destroy(&p);
        });
        alloc.deallocate(elements, cap - elements);
    }
}

// void StrVec::free() {
//     if(elements) {
//         for(auto p = first_free; p != elements;) {
//             alloc.destroy(--p);
//         }
//         alloc.deallocate(elements, cap - elements);
//     }
// }

StrVec::StrVec(const initializer_list<string> &li) {
    auto newdata = alloc_n_copy(li.begin(), li.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(const StrVec &s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec &&rhs) noexcept: 
elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap) {
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

StrVec::~StrVec() {
    free();
}

StrVec &StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
    if(this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

void StrVec::alloc_n_move(const size_t &n) {
    auto newdata = alloc.allocate(n);
    auto dest = newdata;
    auto elem = elements;
    for(size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + n;
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    alloc_n_move(newcapacity);
}

//分配至少能容纳n个元素的内存空间，只有当n大于size时，reverve才会改变容器大小
void StrVec::reserve(const size_t &n) {
    if(n <= size()) return ;
    alloc_n_move(n);
}

//调整容器大小为n个元素，若n小于size,则多出的元素被丢弃，若必须新添加元素，则对新元素进行值初始化
void StrVec::resize(const size_t &n) {
    resize(n, string());
}
//新添加的元素都初始化为t
void StrVec::resize(const size_t &n, const string &t) {
    if(n > size()) {
        if(n > capacity()) reserve(n * 2);
        for(size_t i = size(); i != n; ++i) {
            alloc.construct(first_free++, t);
        }
    }
    else if(n < size()) {
        int diff = size() - n;
        while(diff--) {
            alloc.destroy(--first_free);
        }
    }
}

bool operator==(const StrVec &lhs, const StrVec &rhs) {
    if(lhs.size() != rhs.size()) return false;
    else {
        auto pl = lhs.begin(), pr = rhs.begin();
        while(pl != lhs.end()) {
            if(*pl != *pr) return false;
            ++pl, ++pr;
        }
    }
    return true;
}

bool operator!=(const StrVec &lhs, const StrVec &rhs) {
    return !(lhs == rhs);
}

bool operator<(const StrVec &lhs, const StrVec &rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());    
}

bool operator>(const StrVec &lhs, const StrVec &rhs) {
    return rhs < lhs;
}