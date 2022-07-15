#include<memory>
#include<iostream>
using std::allocator;
using std::pair;

class String {
    friend std::ostream &operator<<(std::ostream &, const String &);
public:
    String() {
        auto data = alloc.allocate(1);
        elements = data;
        alloc.construct(data++, '\0');
        first_free = cap = data;
    }
    String(const char *);
    String(const String &);
    String(String &&) noexcept;
    String &operator=(const String &);
    String &operator=(String &&) noexcept;
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
std::ostream &operator<<(std::ostream &, const String &);
