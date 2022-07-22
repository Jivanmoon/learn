#include <iostream>
#include <string>
#include<vector>
#include<memory>
#include "Quote.h"
using namespace std;
int main()
{
    vector<shared_ptr<Quote>> vq;
    vq.push_back(make_shared<Bulk_quote>("aaa", 50, 5, 0.1));
    vq.push_back(make_shared<Bulk_quote>("bbb", 50, 5, 0.1));
    vq.push_back(make_shared<Limit_quote>("aaa", 50, 5, 0.1));
    for(auto &q : vq) {
        print_total(cout, *q, 10);
    }
    return 0;
}