//2017年10月11日 14点22分
//扫描器，关键字表

#ifndef SCANNER_H_
#define SCANNER_H_

#include <stdio.h>
#include <string>
#include <ext/hash_map>

#include "Common.h"


using namespace std;
using namespace __gnu_cxx;

//扫描器：将源文件转化为线性的字符序列
class Scanner
{
public :
    Scanner(char *name);
    ~Scanner();

    //扫描
    char scan1();
    char scan();

    //外部接口
    char *getFile();    //获取文件名
    int getline();      //获取行号
    int getCol();       //获取列号

private :

    char *fileName;     //文件名
    FILE *file;         //文件指针

    //内部状态
    static const int BUFLEN = 80; //缓冲区大小

	int lineLen;		//缓冲区内的数据长度
	int readPos;		//读取位置
	
	int lineNum;		//行号
	int colNum;			//列号
	char lastch;			//上一个字符
	char line[BUFLEN];		//缓冲区

    void showChar(char ch);

};


//关键字表
class Keywords
{
public :
    Keywords(); //关键字列表初始化
    Tag getTag(string name);    //检测是否位关键字

private :
    //hash函数
    struct string_hash{
        size_t operator()(const string &str) const{
            return __stl_hash_string(str.c_str());
        }
    };

    hash_map<string, Tag, string_hash> keywords;

};

#endif 
