#include <iostream>

#include "Scanner.h"

using namespace std;

int main()
{
    Scanner scanner;
    char ch;

    FILE *fp = fopen("test.txt","a+");

    do{
        ch = scanner.scan(fp);
        cout << ch;
    }while(ch != -1);

    return 0;
}

