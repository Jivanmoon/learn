#include<string>
#include<iostream>
class Book 
{
    friend std::ostream& operator<<(std::ostream &in, const Book &book);
    friend std::istream &operator>>(std::istream &in, Book &book);
public:
    Book(const std::string &isbn = std::string(), const std::string &name = std::string(), const std::string &author = std::string(), const std::string &pubdate = std::string())
        :isbn_(isbn), name_(name), author_(author), pubdate_(pubdate)
    { }

    explicit Book(std::istream &in) 
    { 
        in >> *this;
    }


private:
    std::string isbn_;
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
    if(!in)
        book = Book();
    return in;
}