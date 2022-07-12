#include<memory>
#include<iostream>
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
    const char *c_str() const {return elements;}
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