#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int gox[4] = {-1,1,0,0};
int goy[4] = {0,0,-1,1};
int origin;
void go(int n) {
    if (n == 0) {
        printf("No more bottles of beer on the wall, no more bottles of beer.\n");
        printf("Go to the store and buy some more, %d bottles of beer on the wall.", origin);
        return;
    }
    else if (n == 1) {
        printf("%d bottle of beer on the wall, %d bottle of beer.\n", n, n);
        printf("Take one down and pass it around, no more bottles of beer on the wall.\n\n");
        go(n - 1);
    }
    else {
        if (n - 1 > 1) {
            printf("%d bottles of beer on the wall, %d bottles of beer.\n", n, n);
            printf("Take one down and pass it around, %d bottles of beer on the wall.\n\n", n - 1);
        }
        else {
            printf("%d bottles of beer on the wall, %d bottles of beer.\n", n, n);
            printf("Take one down and pass it around, %d bottle of beer on the wall.\n\n", n - 1);
        }
        go(n - 1);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("1 bottle of beer on the wall, 1 bottle of beer.\n");
        printf("Take one down and pass it around, no more bottles of beer on the wall.\n\n");
        printf("No more bottles of beer on the wall, no more bottles of beer.\n");
        printf("Go to the store and buy some more, 1 bottle of beer on the wall.");
        return 0;
    }
    origin = n;
    go(n);
    return 0;
}