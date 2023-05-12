#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<unsigned> grades;

    unsigned i;
	while (cin >> i)
		grades.push_back(i);

    for (auto grade : grades) {
		string finalgrade = (grade > 90) ? "high pass" : (grade > 75) ? "pass" : (grade > 60) ? "low pass" : "fail";

		cout << grade << " " + finalgrade << endl;
	}

    //if语句版本的省略
    return 0;
}


