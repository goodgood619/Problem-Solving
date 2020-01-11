#include <cstdio>
#include <algorithm>
#include <string.h>
#include <cstdint>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    int n;
    scanf("%d", &n);
    char* s = new char[n+1];
    scanf("%s", s);
    int length = strlen(s);
    for (int i = 0,j=length-1; i <=length / 2; i++,j--) {
        if (s[i] == '?' && s[j] == '?') {
            s[i] = 'a', s[j] = 'a';
        } 
        else if (s[i] == '?' || s[j] == '?') {
            s[i] == '?' ? s[i] = s[j] : s[j] = s[i];
        }
    }
    printf("%s", s);
    return 0;
}