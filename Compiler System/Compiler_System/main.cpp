#include <iostream>

#include "Scanner.h"

using namespace std;

int main()
{
    Scanner scanner("test.txt");
    char ch;
    do{
        ch = scanner.scan();
        cout << ch;
    }while(ch != -1);

    return 0;
}

