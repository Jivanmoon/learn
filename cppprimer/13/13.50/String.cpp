#include "String.h"
#include<cstring>

pair<char *, char *>
String::alloc_copy(const char *b, const char *e) {
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void String::free() {
    if(elements) {
        for(auto p = first_free; p != elements;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

void String::alloc_n_move(const size_t &n) {
    auto newdata = alloc.allocate(n);
    auto dest = newdata;
    auto elem = elements;
    for(size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = newdata + n;
}

void String::reallocate() {
    size_t newcapacity = size() ? size() * 2 : 1;
    alloc_n_move(newcapacity);
}

String::String(const char *s) {
    auto data = alloc_copy(s, s + strlen(s));
    elements = data.first;
    first_free = cap = data.second;
}

String::String(const String &rhs) {
    std::cout << "String::String(const String &rhs)" << std::endl;
    auto ret = alloc_copy(rhs.begin(), rhs.end());
    elements = ret.first;
    first_free = cap = ret.second;
}

String::String(String &&rhs) noexcept:
elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap) {
    std::cout << "String::String(String &&rhs) noexcept" << std::endl;
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

String &String::operator=(const String &rhs) {
    std::cout << "String &String::operator=(const String &rhs)" << std::endl;
    auto ret = alloc_copy(rhs.begin(), rhs.end());
    free();
    elements = ret.first;
    first_free = cap = ret.second;
    return *this;
}

String &String::operator=(String &&rhs) noexcept {
    std::cout << "String &String::operator=(String &&rhs) noexcept" << std::endl;
    if(this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}


String::~String() {
    free();
}
void String::push_back(const char &c) {
    chk_n_alloc();
    alloc.construct(first_free++, c);
}
