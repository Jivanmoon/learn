#include<iostream>
#include "Blob.h"

int main() {
    Blob<int> v;
    for(int i = 0; i < 10; ++i)
        v.push_back(i);
    for(auto &t : v) {
        std::cout << t << std::endl;
    }
}