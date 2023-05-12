#include<string>
class Account {
    void calculate() {amount += amount * interestRate;}
    static double getRate() {return interestRate;}
    static void setRate(double);
private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate();
};

void Account::setRate(double newRate) {
    interestRate = newRate;
}

double Account::initRate() {
    return 0.2;
}

double Account::interestRate = initRate();