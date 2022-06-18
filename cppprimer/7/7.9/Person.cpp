#include "Person.h"

std::istream &read(std::istream &in, Person &p) {
    in >> p.name >> p.address;
    return in;
}
std::ostream &print(std::ostream &out, const Person &p) {
    out << p.name << " " << p.address;
    return out;
}
