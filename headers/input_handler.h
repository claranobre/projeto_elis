#ifndef _INPUT_HANDLER_H_
#define _INPUT_HANDLER_H_

#include "command.h"

namespace Elis { class InputHandler; }

class Elis::InputHandler
{
    public:
        void handle_input();

    private:
        Elis::Command *del;
};
#endif
