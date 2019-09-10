#include <stdio.h>
#include <math.h>
int d(int n) {
    if(n%2==0) return 1;
    else return 0;
}
int main() {
    int a, b, c, q1, q2;
    double p,q;
    scanf("%d %d %d",&a,&b,&c);
    if (b*b - 4 * a*c > 0) {
        q1 = (-b + (int)sqrt(b*b - 4 * a*c)) / (2 * a);
        q2 = (-b - (int)sqrt(b*b - 4 * a*c)) / (2 * a);
        p = ((-b + sqrt(b*b - 4 * a*c)) / (2 * a)) - q1;
        q = ((-b - sqrt(b*b - 4 * a*c)) / (2 * a)) - q2;
        if (p || q) printf("둘다틀렸근"); 
        else if (d((-b + (int)sqrt(b*b - 4 * a*c)) / (2 * a))&&d((-b - (int)sqrt(b*b - 4 * a*c)) / (2 * a))) printf("이수근");
        else printf("정수근");
    }
    else {
        printf("둘다틀렸근");
    }
    return 0;
}
