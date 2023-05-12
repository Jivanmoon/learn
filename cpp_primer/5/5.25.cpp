#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        try
        {
            if (b == 0)
                throw runtime_error("除数不能为0");
            cout << a / b << endl;
        }
        catch (const runtime_error &e)
        {
            cerr << e.what() << '\n';
            cout << "Try Again? Entry y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
        }
    }
    return 0;
}