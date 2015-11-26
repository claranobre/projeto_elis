#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

namespace Elis { class Exception; }

class Elis::Exception : public std::exception
{
    public:
        Exception(const char* m)
         : message(m) {}

        ~Exception() {}

        virtual const char* what() const throw()
        {
            return message;
        }

    private:
        const char* message;
};
#endif
