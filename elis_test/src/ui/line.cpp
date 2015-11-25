#include "line.h"

#include <ncurses.h>

Elis::UI::Line::Line(int n, const char *h)
 : number(n), header(h), content(new std::string()) {}

Elis::UI::Line::~Line()
{}

void
Elis::UI::Line::set_content(std::string c)
{
    *content = c;
}

void
Elis::UI::Line::show()
{
    printw(header, number, content->c_str());
}
