#include<bits/stdc++.h>
using namespace std;

class Employee {
public:
    Employee(): emp_id(num++) {}
    Employee(string name): emp_name(name), emp_id(++num) {}
private:
    string emp_name;
    unsigned emp_id;
    static int num;
};
int Employee::num = 1;