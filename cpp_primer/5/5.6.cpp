#include<bits/stdc++.h>
using namespace std;

int main() {
    int grade;
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    string lettergrade;
    while(cin >> grade) {
        (grade < 60) ? lettergrade = scores[0] : lettergrade = scores[(grade - 50) / 10];
        lettergrade += (grade == 100 || grade < 60) ? "" : (grade % 10 > 7) ? "+" : (grade % 10 < 3) ? "-" : "";
        cout << lettergrade << endl;
    }
    return 0;
}