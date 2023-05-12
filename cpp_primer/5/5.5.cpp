#include<bits/stdc++.h>
using namespace std;

int main() {
    int grade;
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    string lettergrade;
    while(cin >> grade) {
        if(grade < 60)
            lettergrade = scores[0];
        else {
            lettergrade = scores[(grade - 50) / 10];
            if(grade % 10 > 7) lettergrade += '+';
            else if(grade % 10 < 3) lettergrade += '-';
        }
        cout << lettergrade << endl;
    }
    return 0;
}