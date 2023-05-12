#ifndef SCREEN_H
#define SCREEN_H
#include<string>
#include<iostream>
class Screen {
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
    char get() const {return contents[cursor];}
    char get(pos ht, pos wd) const;
    Screen &set(pos r, pos col, char ch);
    Screen &set(char ch);
    const Screen &display(std::ostream &) const;
    Screen &display(std::ostream &);
    Screen &move(pos r, pos c);
private:
    void do_display(std::ostream &out) const {out << contents;}

    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline
Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline
char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
} 

inline
Screen &Screen::set(pos r, pos col, char ch) {
    contents[r * width + col] = ch;
    return *this;
}

inline
Screen &Screen::set(char ch) {
    contents[cursor] = ch;
    return *this;
}

inline
const Screen &Screen::display(std::ostream &out) const {
    do_display(out);
    return *this;
}

inline
Screen &Screen::display(std::ostream &out) {
    do_display(out);
    return *this;
}

#endif