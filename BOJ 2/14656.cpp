#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    scanf("%d",&n);
    int sum = 0;
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        if(num != i+1) sum++;
    }
    printf("%d\n",sum);
    return 0;
}