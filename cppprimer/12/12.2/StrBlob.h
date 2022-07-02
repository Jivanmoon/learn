#ifndef STR_BLOB_H
#define STR_BLOB_H
#include<string>
#include<vector>
#include<memory>
class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> li);
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
private:
    std::shared_ptr<std::vector<std::string>> data;
    //如果data[i]不合法，抛出一个异常
    void check(size_type i, const std::string &msg) const;
};


#endif