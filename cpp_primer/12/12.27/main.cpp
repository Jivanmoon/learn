#include "TextQuery.h"
using namespace std;

int main() {
    ifstream infile("data");
    TextQuery tq(infile);
    while(true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if(!(cin >> s) || s == "q") break;
        print(cout, tq.query(s));
    }
    return 0;
}