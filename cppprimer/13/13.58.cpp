#include<bits/stdc++.h>
using namespace std;

class Foo {
public:
    Foo sorted() && {
        sort(data.begin(), data.end());
        cout << "&&" << endl;
        return *this;
    }

    Foo sorted() const & {
        cout << "const &" << endl;
        return Foo(*this).sorted();
    }
private:
    vector<int> data;
};

int main() {
    Foo().sorted();
    Foo f;
    f.sorted();
}