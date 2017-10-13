#ifndef COMMON_H
#define COMMON_H

//词法记号
//关键字标签，都是以KW_开头

#include <stdio.h>
#include <vector>
#include <list>
#include <string>

using namespace std;

enum Tag{
    ERR,                        //错误，异常
    END,                        //文件结束标记
    ID,                         //标识符
    KW_INT,KW_CHAR,KW_VOID,     //数据类型
    KW_EXTERN,                  //extern
    NUM,CH,STR,                 //常量
    NOT,LEA,                    //单目运算 ! &
    ADD,SUB,MUL,DIV,MOD,        //算数运算符
    INC,DEC,                    //自加，自减
    GT,GE,LT,LE,EQU,NEQU,       //比较运算符
    AND,OR,                     //逻辑运算符，与，或
    LPAREN,RPAREN,              //()
    LBRACK,RBRACK,              //[]
    LBRACE,RBRACE,              //{}
    COMMA,COLON,SEMICON,        //逗号，冒号，分号
    ASSIGN,                     //赋值
    KW_IF,KW_ELSE,              //if-else
    KW_SWITCH,KW_CASE,KW_DEFAULT,      //switch-case_default
    KW_WHILE,KW_DO,KW_FOR,      //while-do-for
    KW_BREAK,KW_CONTINUE,KW_RETURN      //break-continue-return
};


#endif // COMMON_H
