#ifndef _LINE_H_
#define _LINE_H_

#include <iostream>

namespace Elis
{
    namespace UI { class Line; }
}

class Elis::UI::Line
{
    public:
        Line(int n = 1, const char *h = "%i> %s");
        ~Line();

        void show();
        void set_content(std::string);

    private:
        int number;
        const char *header;
        std::string *content;
};

#endif
