//2017年10月11日  14点20分
//张岩
//扫描器

#include "Scanner.h"

#include <string.h>

Scanner::Scanner()
{
    memset(line, 0 ,sizeof(line));
	lineLen = 0;		//缓冲区内的数据长度
	readPos = -1;		//读取位置

	lineNum = 1;		//行号
	colNum = 0;			//列号
	lastch = 0;			//上一个字符	
}	

char Scanner::scan(FILE *file)
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

char Scanner::scan1(FILE *file)
{
	char ch;
	if(fscanf(file, "%c" , &ch) == EOF)
	{
		ch = -1;
	}
	return ch;
}



