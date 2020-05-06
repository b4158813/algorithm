#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long x,y;
long long gcd(long long a,long long b){return b==0?a:gcd(b,a%b);}
void exgcd(long long a,long long b)
{
    if(b==0)
    {
        x=1,y=0;
        return;
    }
    exgcd(b,a%b);
    long long t=x;
    x=y;
    y=t-a/b*y;
}
long long t,a,b,c,g,minx,miny,maxx,maxy,num;
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        g=gcd(a,b);
        if(c%g)
        {
            printf("-1\n");
            continue;
        }
        a/=g,b/=g,c/=g;
        exgcd(a,b);
        x*=c,y*=c;
        minx=(x%b+b)%b;
        if(!minx) minx+=b;
        miny=(y%a+a)%a;
        if(!miny) miny+=a;
        maxx=(c-(b*miny))/a;
        maxy=(c-(a*minx))/b;
        num=(maxx-minx)/b+1;
        if(num) printf("%lld %lld %lld %lld %lld\n",num,minx,miny,maxx,maxy);
        else printf("%lld %lld\n",minx,miny);
    }
    return 0;
}
