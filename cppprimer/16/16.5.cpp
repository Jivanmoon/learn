#include<iostream>

// template<typename T, unsigned N>
// void print(T (&arr)[N]) {
//     for(const auto &elem : arr)
//         std::cout << elem << " ";
// }

template<typename T>
void print(T &arr) {
    for(const auto &elem : arr)
    std::cout << elem << " ";
}

int main() {
    int a[10] = {1,2,3,4};
    print(a);
    std::cout << std::endl;
}
