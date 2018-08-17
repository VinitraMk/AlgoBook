/* Given n, print all combinations of balanced parenthesis having n pairs of parenthesis */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<utility>
#include<queue>
#include<bitset>
#include<numeric>
#define ll long long
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define ipair pair<ll,ll>
#define inp(a) scanf("%lld",&a)
#define out(a) printf("%lld\n",a)
#define allv(a) a.begin(),a.end()
#define alla(a,n) a,a+n
#define fi(i,a,b) for(ll i=a;i<b;i++)
#define N 100000
#define set(n,x) x|=(1<<n)
#define unset(n,x) x&=~(1<<n)
#define chkbit(n,x) (x&(1<<n))!=0
#define m(a,b) (a>b? b : a)
#define M(a,b) (a>b? a : b)
#define mod 1000000007
using namespace std;

void parenbal(ll in,ll n,ll o,ll c) {
    static char str[N];
    if(c==n) 
        printf("%s\n",str);
    else {
        if(o>c) {
            str[in]='}';
            parenbal(in+1,n,o,c+1);
        }
        if(o<n){
            str[in]='{';
            parenbal(in+1,n,o+1,c);
        }
    }
}


int main()
{
    ll i,j,k,l,e,n,m,t,f,c;
    inp(n);
    if(n>0)
        parenbal(0,n,0,0);
    return 0;
}




