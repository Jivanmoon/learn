#include <iostream>
#include <string>
template<unsigned H, unsigned W> class Screen;

template<unsigned H, unsigned W>
std::ostream &operator<<(std::ostream &, const Screen<H, W> &);

template<unsigned H, unsigned W>
std::istream &operator>>(std::istream &, Screen<H, W> &);

template <unsigned H, unsigned W>
class Screen {
    friend std::ostream &operator<< <H, W>(std::ostream &, const Screen<H, W> &);
    friend std::istream &operator>> <H, W>(std::istream &, Screen &);
public:
    typedef std::string::size_type pos;
    Screen() = default; // 需要，因为Screen有另一个构造函数
    // 游标被其类内初始化程序初始化为0
    Screen(char c) : contents(H * W, c) {}
    char get() const             // 在光标处获取字符
    { return contents[cursor]; } // 隐式内联
    Screen &move(pos r, pos c);  // 能够被后面内联
    

private:
    pos cursor = 0;
    pos height = H, width = W;
    std::string contents;
};

template<unsigned H, unsigned W>
std::ostream &operator<<(std::ostream &os, const Screen<H, W> &c) {
    unsigned int i, j;
    for (i = 0; i < c.height; i++) {
        os << c.contents.substr(0, W) << std::endl;
    }
    return os;
}

template<unsigned H, unsigned W>
std::istream &operator>>(std::istream &is, Screen<H, W> &c) {
    char a;
    is >> a;
    std::string temp(H * W, a);
    c.contents = temp;
    return is;
}

template <unsigned H, unsigned W>
inline Screen<H, W> &Screen<H, W>::move(pos r, pos c) {
    pos row = r * width;
    cursor  = row + c;
    return *this;
}

int main() {
    Screen<5, 5> scr('c');
    Screen<5, 5> scr2;
    // 将src输出到Screen
    std::cout<<scr;
    // 输入connet到src
    std::cin>>scr2;
    // 测试输入
    std::cout<<scr2;
    return 0;   
}