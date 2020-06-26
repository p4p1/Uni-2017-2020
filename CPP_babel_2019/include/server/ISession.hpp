#pragma once

#include <string>

using namespace std;

class ISession
{
public:
    virtual ~ISession() = default;
protected:
    virtual void write_some(const string &message, const string &flag="") = 0;
    virtual void read_some() = 0;
    virtual void command_id(string content) = 0;
    virtual void command_pwd(string content) = 0;
    virtual void command_createroom(string content) = 0;
    virtual void command_joinroom(string content) = 0;
    virtual void command_request(string content) = 0;
    virtual void command_exit(string content) = 0;
};