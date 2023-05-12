#include<memory>
using std::allocator;
using std::pair;
class String {
public:
    String(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
    String(const char *);
    String(const String &);
    String &operator=(const String &);
    ~String();
    void push_back(const char &c);
    size_t size() {return first_free - elements;}
    size_t capacity() {return cap - elements;}
    char *begin() const {return elements;}
    char *end() const {return first_free;}

private:
    void chk_n_alloc() {
        if(size() == capacity()) reallocate();
    }
    void reallocate();
    pair<char *, char *> alloc_copy(const char *b, const char *e);
    void alloc_n_move(const size_t &n);
    void free();

private:
    allocator<char> alloc;
    char *elements, *first_free, *cap;
};

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
    alloc_copy(s, s + sizeof(s));
}

String::String(const String &rhs) {
    auto ret = alloc_copy(rhs.begin(), rhs.end());
    elements = ret.first;
    first_free = cap = ret.second;
}
String &String::operator=(const String &rhs) {
    auto ret = alloc_copy(rhs.begin(), rhs.end());
    free();
    elements = ret.first;
    first_free = cap = ret.second;
    return *this;
}
String::~String() {
    free();
}
void String::push_back(const char &c) {
    chk_n_alloc();
    alloc.construct(first_free++, c);
}
