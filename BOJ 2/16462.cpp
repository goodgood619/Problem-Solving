#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int gox[4] = {-1,1,0,0};
int goy[4] = {0,0,-1,1};
int main()
{
    int n;
    scanf("%d", &n);
    double avg = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.size() == 3) {
            avg += 100;
            continue;
        }
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '0' || s[j] == '6' || s[j] == '9') {
                s[j] = '9';
            }
        }
        avg += stoi(s);
    }
    avg /= n;
    if (avg - (int)avg>=0.5) {
        printf("%d\n", (int)avg + 1);
    }
    else printf("%d\n", (int)avg);
    return 0;
}