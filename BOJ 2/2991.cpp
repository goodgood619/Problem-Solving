#include <bits/stdc++.h>
using namespace std;
int main() {
   int a,b,c,d,p,m,n;
   scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&p,&m,&n);
   int a1 =0 ,a2 =0 ,a3 =0;
   if(p %(a+b) != 0 && p %(a+b)<=a) a1++;
   if(p %(c+d) !=0 && p%(c+d)<=c) a1++;
   if(m %(a+b) !=0 && m%(a+b)<=a) a2++;
   if(m%(c+d) !=0 && m%(c+d)<=c) a2++;
   if(n%(a+b)!=0 && n%(a+b)<=a) a3++;
   if(n%(c+d)!=0 && n%(c+d)<=c) a3++;
   printf("%d\n%d\n%d\n",a1,a2,a3);
   return 0;
}