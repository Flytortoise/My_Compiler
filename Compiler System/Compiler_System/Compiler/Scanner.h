//2017年10月11日 14点22分
//扫描器：将源文件转化为线性的字符序列

#ifndef SCANNER_H_
#define SCANNER_H_

#include <stdio.h>

#define BUFLEN 80		//缓冲区大小

class Scanner
{
public :
	Scanner();
	char scan1(FILE *file);
	char scan(FILE *file);

private :
	int lineLen;		//缓冲区内的数据长度
	int readPos;		//读取位置
	
	int lineNum;		//行号
	int colNum;			//列号
	char lastch;			//上一个字符
	char line[BUFLEN];		//缓冲区
};

#endif 
