#include<string>
#include<iostream>
class Book 
{
    friend std::ostream& operator<<(std::ostream &in, const Book &book);
    friend std::istream &operator>>(std::istream &in, Book &book);
public:
    Book(unsigned isbn, std::string const& name, std::string const& author, std::string const& pubdate)
        :isbn_(isbn), name_(name), author_(author), pubdate_(pubdate)
    { }

    explicit Book(std::istream &in) 
    { 
        in >> *this;
    }


private:
    unsigned isbn_;
    std::string name_;
    std::string author_;
    std::string pubdate_;
};

std::ostream& operator<<(std::ostream &out, const Book &book) {
    out << book.author_ << " " << book.isbn_ << " " << book.name_ << " " << book.pubdate_;
    return out;
}

std::istream &operator>>(std::istream &in, Book &book) {
    in >> book.isbn_ >> book.name_ >> book.author_ >> book.pubdate_;
    return in;
}