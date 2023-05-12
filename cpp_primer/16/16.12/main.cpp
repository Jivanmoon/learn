#include<iostream>
#include "Blob.h"

int main() {
    // Blob<int> v;
    // for(int i = 0; i < 10; ++i)
    //     v.push_back(i);
    // for(auto &t : v) {
    //     std::cout << t << std::endl;
    // }
    std::vector<int> v{1,2,3,45};
    Blob<double> vd(v.begin(), v.end());
    for(auto &t : vd) {
        std::cout << t << std::endl;
    }
}