#ifndef PERSON_H
#define PERSON_H

#include<string>
#include<iostream>
struct Person {
    std::string name;
    std::string address;

    std::string getName() const {return name;}
    std::string getAddr() const {return address;}
};

std::istream &read(std::istream &, Person &);
std::ostream &print(std::ostream &, const Person &);

#endif