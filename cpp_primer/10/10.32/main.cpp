#include "Sales_item.h"
#include<bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

bool isbn_unsame(const Sales_item &x, const Sales_item &y) {
    return x.isbn() != y.isbn();
}

int main() {
    istream_iterator<Sales_item> in_iter(cin), eof;
    ostream_iterator<Sales_item> out_iter(cout, "\n");
    vector<Sales_item> vs;
    copy(in_iter, eof, back_inserter(vs));
    sort(vs.begin(), vs.end(), compareIsbn);
    for(auto beg = vs.cbegin(), end = beg; beg != vs.cend(); beg = end) {
        end = find_if(beg, vs.cend(), [beg](const Sales_item &item){ return item.isbn() != beg->isbn(); });
        *out_iter++ = accumulate(beg, end, Sales_item(beg->isbn()));
    }
    return 0;
}