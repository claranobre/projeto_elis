#ifndef _DEL_COMMAND_H
#define _DEL_COMMAND_H

#include <ncurses.h>

#include "../command.h"

namespace Elis
{
    namespace Commands { class DelCommand; }
}

class Elis::Commands::DelCommand : public Elis::Command
{
    public:
        virtual void execute()
        {
            current_line.pop_back();
            addch('\b');
            delch();
        }
};
#endif
