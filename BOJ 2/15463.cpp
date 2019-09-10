#include <cstdio>
#include <algorithm>
using namespace std;
struct Rect{
	int x1, y1, x2, y2;
};
int go(Rect x, Rect y){
	int diffx = max(0, min(x.x2, y.x2) - max(x.x1, y.x1));
	int diffy = max(0, min(x.y2, y.y2) - max(x.y1, y.y1));
	return diffx*diffy;
}
int main(){
	Rect a,b,t;
	scanf("%d%d%d%d", &a.x1, &a.y1, &a.x2, &a.y2);
	scanf("%d%d%d%d", &b.x1, &b.y1, &b.x2, &b.y2);
	scanf("%d%d%d%d", &t.x1, &t.y1, &t.x2, &t.y2);
	int area1 = (a.x2 - a.x1)*(a.y2 - a.y1);
	int area2 = (b.x2 - b.x1)*(b.y2 - b.y1);
	int no1 = go(a, t);
	int no2 = go(b, t);
	printf("%d\n", area1 + area2 - no1 - no2);
	return 0;
}