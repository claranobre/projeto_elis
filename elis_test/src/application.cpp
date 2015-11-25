#include "application.h"

#include <fstream>

#include "keys.h"

/*Construtor*/
Elis::Application::Application()
 : filename("noname.txt"), window(new Elis::UI::Window()) {}

Elis::Application::~Application()
{}

void
Elis::Application::initialize(int argc, char const *argv[])
{
    parse_command_line(argc, argv);
}

void
Elis::Application::run()
{
    char key;
    Elis::UI::Line line;

    window->new_line();
    window->show();

    configure_ncurses();

    while(true) /*laço infinito*/
    {
        key = getch(); /*ler caractere*/

        if (key == Elis::Keys::QUIT)
            break;

        switch(key)
        {
            case Elis::Keys::DELETE:
            case Elis::Keys::BACKSPACE:
                current_line.pop_back(); /*Remove o último caractere*/
                addch('\b');
                delch();
                break;
            case Elis::Keys::ENTER:
                line = window->new_line();
                current_line.push_back('\n'); /*Nova linha*/

                printw("\n");
                line.show();

                break;
            case Elis::Keys::ESCAPE:
                printw("\n: "); /*Ler o que será digitado*/

                while (true)
                {
                    key = getch();

                    addch(key);

                    if (key == Elis::Keys::QUIT)
                        break;
                    else if (key == 'W' || key == 'w')
                    {
                        std::string s;

                        while((key = getch()) != Elis::Keys::ENTER)
                        {
                            s.push_back(key);
                            addch(key);
                        }

                        //s.erase( std::remove(s.begin(), s.end(), ' '), s.end() );

                        if (!s.empty())
                            filename = s;

                        std::ofstream file;

                        file.open(filename);
                        file << current_line;
                        file.close();
                        break;
                    }
                }
                break;
            default:
                current_line.push_back(key);
                addch(key);
        }

        refresh();
    }

    window->hide();
}

void
Elis::Application::parse_command_line(int argc, char const *argv[])
{
    if (argc < 2)
        return;

    filename = argv[1]; /*argv = { “./elis”, “texto.txt”};*/
}

void
Elis::Application::configure_ncurses()
{
    raw();
    noecho(); 
}
