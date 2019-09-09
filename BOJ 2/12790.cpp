#include <stdio.h>
#include <algorithm>
using namespace std;
int hp,mp,at,de,bhp,bmp,bat,bde;
int main()
{
	int t;
	scanf("%d",&t);
	int realhp,realmp,realat,realde;
	while(t--){
	scanf("%d %d %d %d %d %d %d %d",&hp,&mp,&at,&de,&bhp,&bmp,&bat,&bde);
	realhp=hp+bhp;
	realmp=mp+bmp;
	realat=at+bat;
	realde=de+bde;
	if(realhp<1)
	realhp=1;
	if(realmp<1)
	realmp=1;
	if(realat<0)
	realat=0;
	long long battle=(realhp*1)+(realmp*5)+(realat*2)+(realde*2);
	printf("%lld\n",battle);
	}
	return 0;
}