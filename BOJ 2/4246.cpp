#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int n;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;
 
        string str;
        cin >> str;
    
        int len = str.size();
 
        for (int mul = 1; n * mul < len; mul+=2)
            reverse(str.begin() + n * mul, str.begin() + n * (mul + 1));
 
        for (int start = 0; start < n; start++)
            for (int pos = start; pos < len; pos += n)
                cout << str[pos];
        cout << endl;
    }
 
    return 0;
}