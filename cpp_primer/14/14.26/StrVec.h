#include<string>
#include<memory>
#include <initializer_list>
using std::string;
using std::initializer_list;
using std::pair;
using std::allocator;

class StrVec {
    friend bool operator==(const StrVec &lhs, const StrVec &rhs);
    friend bool operator!=(const StrVec &lhs, const StrVec &rhs);
    friend bool operator<(const StrVec &lhs, const StrVec &rhs);
    friend bool operator>(const StrVec &lhs, const StrVec &rhs);
public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const initializer_list<string> &li);
    StrVec(const StrVec &);
    StrVec &operator=(const StrVec &);
    StrVec(StrVec &&) noexcept;
    StrVec &operator=(StrVec &&rhs) noexcept;
    string &operator[](size_t n) {
        return elements[n];
    }
    const std::string &operator[](size_t n) const {
        return elements[n];
    }
    ~StrVec();
    void push_back(const string &);
    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}
    string *begin() const {return elements;}
    string *end() const {return first_free;}

    std::string& at(size_t pos) { return *(elements + pos); }
    const std::string& at(size_t pos) const { return *(elements + pos); }

    //分配至少能容纳n个元素的内存空间，只有当n大于size时，reverve才会改变容器大小
    void reserve(const size_t &n);
    //调整容器大小为n个元素，若n小于size,则多出的元素被丢弃，若必须新添加元素，则对新元素进行值初始化
    void resize(const size_t &n);
    //新添加的元素都初始化为t
    void resize(const size_t &n, const string &t);
    
private:
    void chk_n_alloc() {
        if(size() == capacity()) reallocate();
    }
    pair<string *, string *> alloc_n_copy(const string *, const string *);
    void alloc_n_move(const size_t &n);
    void free();
    void reallocate();

private:
    allocator<string> alloc;
    string *elements, *first_free, *cap;
};

bool operator==(const StrVec &lhs, const StrVec &rhs);
bool operator!=(const StrVec &lhs, const StrVec &rhs);
bool operator<(const StrVec &lhs, const StrVec &rhs);
bool operator>(const StrVec &lhs, const StrVec &rhs);