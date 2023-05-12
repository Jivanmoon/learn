#ifndef STR_BLOB_H
#define STR_BLOB_H
#include<string>
#include<vector>
#include<memory>
class StrBlobPtr;
class StrBlob {
    friend class StrBlobPtr;
    friend bool operator==(const StrBlob &, const StrBlob &);
    friend bool operator!=(const StrBlob &, const StrBlob &);
    friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator>(const StrBlob &lhs, const StrBlob &rhs);

public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> li);
    StrBlob(const StrBlob &rhs);

    StrBlob &operator=(const StrBlob &rhs);
    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}
    //添加和删除元素
    void push_back(const std::string &s) {data->push_back(s);}
    void pop_back();   
    //元素访问
    std::string &front();
    //常量对象只能调用常量成员函数
    const std::string &front() const;
    std::string &back();
    const std::string &back() const;
    StrBlobPtr begin();
    StrBlobPtr end();
private:
    std::shared_ptr<std::vector<std::string>> data;
    //如果data[i]不合法，抛出一个异常
    void check(size_type i, const std::string &msg) const;
};
bool operator==(const StrBlob &, const StrBlob &);
bool operator!=(const StrBlob &, const StrBlob &);
bool operator<(const StrBlob &lhs, const StrBlob &rhs);
bool operator>(const StrBlob &lhs, const StrBlob &rhs);


class StrBlobPtr {
    friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
public:
    StrBlobPtr(): curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
    std::string &deref() const;
    StrBlobPtr &incr();
    bool equal(const StrBlobPtr &) const;

private:
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};
bool operator==(const StrBlobPtr &, const StrBlobPtr &);
bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
bool operator<(const StrBlobPtr &, const StrBlobPtr &);
bool operator>(const StrBlobPtr &, const StrBlobPtr &);


#endif