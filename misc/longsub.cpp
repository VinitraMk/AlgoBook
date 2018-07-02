/*Longest subarray having sum of elements atmost k*/


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

int main()
{
    ll i,j,k,l,e,n,m,t,f,c;
    inp(n);inp(k);
    ll a[n];
    fi(i,0,n)
        inp(a[i]);
    l=0;
    maxl=0;
    c=0;
    fi(i,0,n) {
        if(c+a[i]<=k) {
            c+=a[i];
            l++;
        }
        else if(c!=0) 
            c=c-a[i-l]+a[i];
    }
    maxl=M(maxl,l);
    cout<<maxl<<endl;
    return 0;
}




