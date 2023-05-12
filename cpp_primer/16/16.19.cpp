#include <iostream>
#include <vector>
#include <list>
// ex16.19
template<typename Container>
std::ostream& print(Container const& container, std::ostream& os)
{
    for(typename Container::size_type i = 0; i != container.size(); ++ i)
        os << container[i] << " ";
    return os;
}
// ex16.20
template<typename Container>
std::ostream& print2(Container const& container, std::ostream &os)
{
    for(auto curr = container.cbegin(); curr != container.cend(); ++curr)
        os << *curr << " ";
    return os;
}
int main()
{
    std::vector<int> v = { 1, 23, 6, 4, 5, 7, 4 };
    std::list<std::string> l = { "ss", "sszz", "saaas", "s333s", "ss2"," sss" };
    print2(v, std::cout) << std::endl;
    print2(l, std::cout) << std::endl;

    return 0;
}
