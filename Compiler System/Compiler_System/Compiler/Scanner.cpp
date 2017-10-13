//2017年10月11日  14点20分
//张岩
//扫描器，关键字表

#include "Scanner.h"
#include <assert.h>

#include <string.h>


//扫描器
Scanner::Scanner(char *name)
{
    file = fopen(name,"r"); //打开指定扫描文件

    file = fopen(name,"r");

    assert(file != NULL);   //

    fileName = new char[strlen(name) + 1]();
    strcpy(fileName,name);

    memset(line, 0 ,sizeof(line));
	lineLen = 0;		//缓冲区内的数据长度
	readPos = -1;		//读取位置

	lineNum = 1;		//行号
	colNum = 0;			//列号
	lastch = 0;			//上一个字符	
}	

Scanner::~Scanner()
{

}

void Scanner::showChar(char ch)
{
    if(ch == -1) printf("EOF");
    else if(ch == '\n') printf("\\n");
    else if(ch == '\t') printf("\\t");
    else if(ch == ' ') printf("<blank>");
    else printf("%c",ch);
    printf("\t\t<%d>\n",ch);
}


char Scanner::scan()
{
	if( !file ){
		return -1;		//没有文件
	}

	if(readPos == lineLen - 1){					//缓冲区读取完毕
		lineLen = fread(line, 1, BUFLEN,file);	//重新加载缓冲区数据
		if(lineLen == 0){						//没有数据了
			lineLen = 1;						//数据长度位1
			line[0] = -1;						//文件结束标记
		}
		readPos = -1;							//回复读取位置

	}
   // printf("line : %s\n",line);
	readPos++;									//移动读取点
	char ch = line[readPos];					//获取新的字符

	if(lastch == '\n'){							//新行
		lineNum++;								//行号累加
		colNum = 0;								//列号清空
	}

	if(ch == -1){								//文件结束，自动关闭
		fclose(file);
		file = NULL;
	}
	else if(ch != '\n'){						//不是换行
		colNum++;								//列号递增
	}

	lastch = ch;

	return ch;									//返回字符

}

char Scanner::scan1()
{
	char ch;
	if(fscanf(file, "%c" , &ch) == EOF)
	{
		ch = -1;
	}
	return ch;
}

char *Scanner::getFile()
{
    return fileName;
}

int Scanner::getline()
{
    return lineNum;
}

int Scanner::getCol()
{
    return colNum;
}


