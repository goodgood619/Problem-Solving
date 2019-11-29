#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int *a = new int[10];
    int *b = new int[10];
    for(int i=0;i<10;i++) scanf("%d",&a[i]);
    for(int i=0;i<10;i++) scanf("%d",&b[i]);
    int A=0 ,B=0;
    for(int i=0;i<10;i++){
        if(a[i]>b[i]) A++;
        else if(a[i]<b[i]) B++;
    }
    if(A>B) printf("A\n");
    else if(A<B) printf("B\n");
    else printf("D");
    delete[] a,b;
    return 0;
}