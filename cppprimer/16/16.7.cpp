#include<bits/stdc++.h>

template<typename T, unsigned N>
constexpr unsigned func(T (&arr)[N]) {
    return N;
}

int main() {
    char c[] = "dasdascxzczx";
    int a = func(c);
    std::cout << a << std::endl;
}

