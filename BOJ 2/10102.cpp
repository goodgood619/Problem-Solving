#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    scanf("%d",&n);
    int a=0,b=0;
    for(int i=0;i<n;i++){
        char c;
        scanf(" %c",&c);
        c == 'A' ? a++ : b++;
    }
    if(a>b) printf("A");
    else if(a<b) printf("B");
    else printf("Tie");
    return 0;
}