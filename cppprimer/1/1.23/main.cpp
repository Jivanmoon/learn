#include<iostream>
#include "Sales_item.h"
using namespace std;

int main() {
    Sales_item curBook, book;
    if(cin >> curBook) {
        int cnt = 1;
        while(cin >> book) {
            if(book.isbn() == curBook.isbn()) {
                ++cnt;
            }
            else {
                cout << curBook.isbn() << ":" << cnt << endl;
                curBook = book;
                cnt = 1;
            }
        }
        cout << curBook.isbn() << ":" << cnt << endl;
    }
    return 0;
}