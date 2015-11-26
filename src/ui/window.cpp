#include "window.h"

#include <ncurses.h>

Elis::UI::Window::Window()
{
    window = nullptr;
    lines = new Elis::List<Elis::UI::Line>();
}

Elis::UI::Window::~Window()
{
    delete current_line;
}

void
Elis::UI::Window::show()
{
    window = initscr(); /*Inicializa uma janela ncurses*/

    for (auto itr = lines->begin(); itr != lines->end(); ++itr) /*auto: abreviação para o tipo da variável*/
        (*itr).show();
}

void
Elis::UI::Window::hide()
{
    delwin(window);
    endwin();
}

Elis::UI::Line
Elis::UI::Window::new_line(const char *c)
{
    auto line = Elis::UI::Line(lines->size() + 1);

    line.set_content(std::string(c));
    lines->push_front(line);

    return line;
}
