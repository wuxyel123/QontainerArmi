#include "nofilefoundexception.h"

NoFileFoundException::NoFileFoundException(std::string w):error(w){}

std::string NoFileFoundException::getError() const{
    return error;
}

