#ifndef NOFILEFOUNDEXCEPTION_H
#define NOFILEFOUNDEXCEPTION_H
#include<iostream>
#include<string>
class NoFileFoundException
{

    std::string error;
    public:
        NoFileFoundException(std::string);
        std::string getError() const;
};

#endif // NOFILEFOUNDEXCEPTION_H
