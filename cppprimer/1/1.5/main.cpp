#include<iostream>
int main() {
    std::cout << "输入两个数：" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << v1;
    std::cout << "和";
    std::cout << v2;
    std::cout << "的乘积为：";
    std::cout << v1 * v2;
    std::cout << std::endl;
    return 0;
}