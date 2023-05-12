/**
 * 
 * 类模板
 * 
 */
#ifndef _STACK3_H_
#define _STACK3_H_

#include<stdexcept>
#include<deque>
using namespace std;

//缺省模板参数
template<typename T, typename CONT = deque<T>>
class Stack3 {
public:
    Stack3() : c_() {}

    ~Stack3() {}

    void Push(const T& elem) {
        c_.push_back(elem);
    }
    
    void Pop() {
        c_.pop_back();
    }

    T& Top() {
        return c_.back();
    }

    const T& Top() const {
        return c_.back();
    }

    bool Empty() const {
        return c_.empty();
    }
private:
    CONT c_;
};
#endif // _STACK3_H_