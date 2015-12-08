#ifndef _COMMAND_H_
#define _COMMAND_H_

namespace Elis { class Command; }

class Elis::Command
{
    public:
        virtual ~Command() {}
        virtual void execute() = 0;
};

#endif
