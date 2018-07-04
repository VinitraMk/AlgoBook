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
/*No of ordered pairs with sum divisible by k*/
int main()
{
    ll i,j,k,l,e,n,m,t,f,c;
    inp(n);inp(m);
    ll a[n];
    ll freq[101];
    fill_n(freq,101,0);
    fi(i,0,n)
        inp(a[i]);

    c=0;
    for(i=n-1;i>=0;i--) {
        //freq[a[i]%m]++;
        if(i<=n-2) {
            e=a[i]%m;
            l=m-e;
            if(e==0)
                c+=freq[0];
            else if(e==l) 
                c+=freq[e];
            else
                c+=freq[l];
        }
        freq[a[i]%m]++;
    }
    cout<<c<<endl;
    return 0;
}




