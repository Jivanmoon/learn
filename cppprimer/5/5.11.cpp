#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c;
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    int spaceCnt = 0, tabCnt = 0, newLineCnt = 0;
    while (cin >> noskipws >> c)
    {
        switch (c)
        {
        case 'a':
        case 'A':
            ++aCnt;
            break;
        case 'e':
        case 'E':
            ++eCnt;
            break;
        case 'i':
        case 'I':
            ++iCnt;
            break;
        case 'o':
        case 'O':
            ++oCnt;
            break;
        case 'u':
        case 'U':
            ++uCnt;
            break;
        case ' ':
            ++spaceCnt;
            break;
        case '\t':
            ++tabCnt;
            break;
        case '\n':
            ++newLineCnt;
            break;
        }
    }
    cout << "a:" << aCnt << endl;
    cout << "e:" << eCnt << endl;
    cout << "i:" << iCnt << endl;
    cout << "o:" << oCnt << endl;
    cout << "u:" << uCnt << endl;
    cout << "空格:" << spaceCnt << endl;
    cout << "制表:" << tabCnt << endl;
    cout << "换行:" << newLineCnt << endl;
    return 0;
}