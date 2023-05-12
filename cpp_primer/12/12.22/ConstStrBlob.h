#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>
using namespace std;
class ConstStrBlobPtr;//新添加的
class StrBlob {
public:
    using size_type = vector<string>::size_type;
    friend class ConstStrBlobPtr;

    ConstStrBlobPtr begin() const; // 应该添加 const
    ConstStrBlobPtr end() const; // 应该添加 const

    StrBlob():data(make_shared<vector<string>>()) { }
    StrBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)) { }

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string &t) { data->push_back(t); }
    void pop_back() {
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    }

    string& front() {
        check(0, "front on empty StrBlob");
        return data->front();
    }

    string& back() {
        check(0, "back on empty StrBlob");
        return data->back();
    }

    const string& front() const {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    const string& back() const {
        check(0, "back on empty StrBlob");
        return data->back();
    }

private:
    void check(size_type i, const string &msg) const {
        if (i >= data->size()) throw out_of_range(msg);
    }

private:
    shared_ptr<vector<string>> data;
};

class ConstStrBlobPtr {//对应位置修改
public:
    ConstStrBlobPtr():curr(0) { }
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0):wptr(a.data), curr(sz) { }

    bool operator!=(const ConstStrBlobPtr& p) const { return p.curr != curr; }

    const string& deref() const {//返回值添加const
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    ConstStrBlobPtr& incr() {// 前缀递增
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }

private:
    // 若检查成功，check返回一个指向vector的shared_ptr.
    shared_ptr<vector<string>> check(size_t i, const string &msg) const {
        auto ret = wptr.lock();
        if (!ret) throw runtime_error("unbound StrBlobPtr");
        if (i >= ret->size()) throw out_of_range(msg);
        return ret;
    }
    weak_ptr<vector<string>> wptr;// 保存一个weak_ptr，意味着vector有可能被销毁。
    size_t curr;// 在数组中当前的位置
};
// begin()和end()函数的定义必须在ConstStrBlobPtr类定义之后，否则会报错(StrBlobPtr是不完全类型)
ConstStrBlobPtr StrBlob::begin() const // 应该添加 const
{
    return ConstStrBlobPtr(*this);
}
ConstStrBlobPtr StrBlob::end() const // 应该添加 const
{
    return ConstStrBlobPtr(*this, data->size());
}