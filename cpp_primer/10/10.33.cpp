#include<bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
    ifstream fin(argv[1]);
    ofstream fout1(argv[2]), fout2(argv[3]);
    istream_iterator<int> in_iter(fin), eof;
    ostream_iterator<int> out_iter1(fout1, " "), out_iter2(fout2, " ");
    for_each(in_iter, eof, 
        [&](const int &x) {
            if(x & 1) *out_iter1++ = x;
            else *out_iter2++ = x;
        }
    );
    return 0;
}