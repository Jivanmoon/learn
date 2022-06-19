#include "Screen.h"

const Screen &Screen::display(std::ostream &out) const {
    do_display(out);
    return *this;
}


Screen &Screen::display(std::ostream &out) {
    do_display(out);
    return *this;
}

void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}