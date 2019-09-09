#include<stdio.h>
#include<algorithm>

using namespace std;

typedef long long int lld;

struct Point{
    lld x, y;
    bool operator <(const Point a)const{
        return x==a.x?y<a.y:x<a.x;
    }
    Point operator -(const Point a)const{
        return {x-a.x,y-a.y};
    }
    bool operator ==(const Point a)const{
        return x==a.x&&y==a.y;
    }
}rect[5];

int ccw(Point A,Point B)
{
    lld t = A.x*B.y-A.y*B.x;
    return t<0?-1:t>0;
}
int ccw(Point A,Point B,Point C){
    return ccw(B-A,C-A);
}

bool iscross(Point A,Point B,Point C,Point D)
{
    int ab = ccw(A,B,C)*ccw(A,B,D);
    int cd = ccw(C,D,A)*ccw(C,D,B);

    if(ab==0&&cd==0){
        if(B<A)swap(A,B);
        if(D<C)swap(C,D);
        if(B<C&&A<C||D<A&&C<A)return false;
    }
    return ab<=0&&cd<=0;
}
bool iscross_opt(Point A,Point B,Point C,Point D){
    int ab = ccw(A,B,C)*ccw(A,B,D);
    int cd = ccw(C,D,A)*ccw(C,D,B);
    return ab<0&&cd<=0;
}
bool iscross_opt2(Point A,Point B,Point C,Point D){
    int ab = ccw(A,B,C)*ccw(A,B,D);
    int cd = ccw(C,D,A)*ccw(C,D,B);
    return ab==0&&cd<=0;
}

bool isoverlap(Point A,Point B,Point C,Point D){
    if(!iscross(A,B,C,D))return false;
    if(ccw(A,B,C)!=0||ccw(A,B,D)!=0)return false;

    if(B<A)swap(A,B);
    if(D<C)swap(C,D);
    return A<C&&C<B||C<A&&A<D||A<D&&D<B||C<B&&B<D||A==C&&B==D;
}

int main()
{
    int t,i,j;
    scanf("%d",&t);

    for(int tt=1;tt<=t;tt++)
    {
        scanf("%lld%lld%lld%lld",&rect[0].x,&rect[0].y,&rect[2].x,&rect[2].y);
        rect[1] = {rect[0].x,rect[2].y};
        rect[3] = {rect[2].x,rect[0].y};
        rect[4] = {rect[0].x,rect[0].y};
        Point a,b;
        scanf("%lld%lld%lld%lld",&a.x,&a.y,&b.x,&b.y);
        if(b<a)swap(a,b);
        //1. 교점 없음
        for(i=0;i<4;i++)
        {
            if(iscross(a,b,rect[i],rect[i+1]))
                break;
        }
        if(i==4)
        {
            puts("0");
            continue;
        }
        //2. 교점 무한
        for(i=0;i<4;i++)
        {
            if(isoverlap(a,b,rect[i],rect[i+1]))
                break;
        }
        if(i!=4)
        {
            puts("4");
            continue;
        }
        //3. 교점 개수 세기
        // - 사각형의 선분과 교차
        // - 사각형의 꼭지점과 교차
        int cnt = 0,cnt2 = 0;
        for(i=0;i<4;i++)
        {
            if(iscross_opt(a,b,rect[i],rect[i+1]))cnt++;
            if(iscross_opt2(a,b,rect[i],rect[i+1]))cnt2++;
        }
        printf("%d\n",cnt+cnt2/2);
    }
    return 0;
}