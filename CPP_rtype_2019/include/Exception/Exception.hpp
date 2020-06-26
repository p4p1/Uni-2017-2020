#include <exception>
#include <string>
#include <iostream>

class Exception : std::exception
{
    public:
        Exception(const std::string &s) : std::exception(){
            std::cerr << s << std::endl;           
        }
        ~Exception() = default;
};