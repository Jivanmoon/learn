#include<bits/stdc++.h>
using namespace std;


template<typename T, unsigned N>
constexpr T *begin(T (&arr)[N]) {
    return arr;
}

template<typename T, unsigned N>
constexpr T *end(T (&arr)[N]) {
    return arr + N;
}

int main() {
    int a[1] = {0};
    for(auto i = ::begin(a); i != ::end(a); ++i)
        cout << *i << endl;
}