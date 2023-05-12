#include "StrBlob.h"

//StrBlob
StrBlob::StrBlob(): data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> li): data(std::make_shared<std::vector<std::string>>(li)) {}
StrBlob::StrBlob(const StrBlob &rhs): data(std::make_shared<std::vector<std::string>>(*rhs.data)) {}

StrBlob &StrBlob::operator=(const StrBlob &rhs) {
    data = std::make_shared<std::vector<std::string>>(*rhs.data);
    return *this;
}

void StrBlob::check(size_type i, const std::string &msg) const {
    if(i >= data->size())
        throw std::out_of_range(msg);
}

std::string &StrBlob::back() {
    check(0, "back on emtpy StrBlob");
    return data->back();
}

const std::string &StrBlob::back() const {
    check(0, "back on emtpy StrBlob");
    return data->back();
}

std::string &StrBlob::front() {
    check(0, "front on emtpy StrBlob");
    return data->front();
}

const std::string &StrBlob::front() const {
    check(0, "front on emtpy StrBlob");
    return data->front();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

StrBlobPtr StrBlob::begin() {return StrBlobPtr(*this);}
StrBlobPtr StrBlob::end() {
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
    return *(lhs.data) == *(rhs.data);
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
    return *(lhs.data) < *(rhs.data);
}
bool operator>(const StrBlob &lhs, const StrBlob &rhs) {
    return *(rhs.data) < *(lhs.data);
}


//StrBlobPtr
std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if(!ret) 
        throw std::runtime_error("unbound StrBlobPtr");
    if(i >= ret->size()) 
        throw std::out_of_range(msg);
    return ret;
}

std::string &StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::operator++() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr &StrBlobPtr::operator--() {
    --curr;
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int) {
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

StrBlobPtr StrBlobPtr::operator--(int) {
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

StrBlobPtr &StrBlobPtr::operator+=(int n) {
    curr += n;
    check(curr, "out of range");
    return *this;
}

StrBlobPtr &StrBlobPtr::operator-=(int n) {
    curr -= n;
    check(curr, "out of range");
    return *this;
}

StrBlobPtr StrBlobPtr::operator+(int n) const {
    StrBlobPtr ret = *this;
    ret += n;
    return ret;
}

StrBlobPtr StrBlobPtr::operator-(int n) const {
    StrBlobPtr ret = *this;
    ret -= n;
    return ret;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    
    return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.curr < rhs.curr;
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return rhs < lhs;
}



