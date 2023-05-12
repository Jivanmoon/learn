#include<iostream>
#include<memory>

class DebugDelete {
public:
    DebugDelete(std::ostream &s = std::cerr) : os(s) {}
    template<class T>
    void operator() (T *p) const {
        os << "deleting unique_ptr" << std::endl;
        delete p;
    }
private:
    std::ostream &os;
};

int main() {
    std::unique_ptr<int, DebugDelete> p(new int, DebugDelete());
}