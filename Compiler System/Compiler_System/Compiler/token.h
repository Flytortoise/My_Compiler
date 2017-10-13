#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include "Common.h"

using namespace std;

//词法记号类

class Token
{
public :
    Tag tag;    //内部标签
    Token( Tag t);
    virtual string toString();
    virtual ~Token();
};

//标识记号
class Id : public Token
{
public :
    string name;
    Id(string n);
    virtual string toString();
};

//数字记号类
class Num : public Token
{
public :
    int val;
    Num(int v);
    virtual string toString();

};

//字符记号类
class Char : public Token
{
public :
    char ch;
    Char(char c);
    virtual string toString();
};

//字符串记号类
class Str : public Token
{
public :
    string str;
    Str(string s);
    virtual string toString();
};

#endif // TOKEN_H
