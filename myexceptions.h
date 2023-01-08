#pragma once
#include <exception>

class MyExceptions:public std::exception{
    private:
    std::string exMessage;

    public:
    MyExceptions(std::string em)
    :exMessage{em}
    {}

    const char* what() const noexcept {return exMessage.c_str();}
};