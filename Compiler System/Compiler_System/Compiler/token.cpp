#include "token.h"
#include <sstream>
//词法记号名字

const char *tokenName[] = {
    "error",                       //错误
    "文件结尾",                     //文件结束符
    "标识符",                       //标识符
    "int","char","void",           //数据类型
    "extern",                      //extern
    "数字","字符","字符串",          //常量
    "!","&",                       //单目运算符
    "+","-","*","/","%",           //算数运算符
    "++","--",                     //自加，自减
    ">",">=","<","<=","==","!=",   //比较运算符
    "&&","||",                     //逻辑运算符
    "(",")",
    "[","]",
    "{","}",
    ",",":",";",
    "=",
    "if","else",
    "switch","case","default",
    "while","do","for",
    "break","continue","return"
};



//Token

Token::Token(Tag t) : tag(t)
{
}

string Token::toString()
{
    return tokenName[tag];
}

Token::~Token()
{}


//标识符
Id::Id(string n) : Token(ID), name(n)
{}

string Id::toString()
{
    return Token::toString() + name;
}

//数字记号类
Num::Num(int v) : Token(NUM),val(v)
{}

string Num::toString()
{
    stringstream ss;    //对流进行输入输出操作
    ss << val;            //将v的值，转换成string类型
                        // int a; ss >> a;
                        // a的值会和v的值相同，直接将string转换成int
                        // 注意头文件sstream
    return string("[") + Token::toString() + "]:" + ss.str();
}


//字符记号
Char::Char(char c) : Token(CH), ch(c)
{}

string Char::toString()
{
    stringstream ss;
    ss << ch;
    return string("[") + Token::toString() + "]:" + ss.str();
}


//字符串
Str::Str(string s) : Token(STR), str(s)
{}

string Str::toString()
{
    return string("[") + Token::toString() + "]" + str;
}
