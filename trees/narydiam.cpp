/* N-ary tree diameter */
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

ll getheight(vector<ll> a[],ll in) {

    if(a[in].size()==0)
        return 0;
    ll h=-inf;
    for(auto it=a[in].begin();it!=a[in].end();it++) 
        h=M(h,getheight(a,*it));
    return (h+1);
}

ll diameter(vector<ll> a[],ll in) {

    if(a[in].size()==0)
        return 0;
    
    ll h1=-inf,h2=-inf;
    for(auto it=a[in].begin();it!=a[in].end();it++) {
        ll h=getheight(a,*it);
        if(h>h1) {
            h2=h1;
            h1=h;
        }
        else if(h>h2) 
            h2=h;
    }

    ll maxd=-inf;
    for(auto it=a[in].begin();it!=a[in].end();it++) 
        maxd=M(maxd,diameter(a,*it));
    return M(maxd,h1+h2+1);
}


int main()
{
    ll i,j,k,l,e,n,m,t,f,c;
    inp(n);inp(m);
    vector<ll> a[n];
    fi(i,0,m) {
        inp(e);inp(c);
        a[e-1].pb(c-1);
    }
    cout<<"Diameter of the N-ary tree is: "<<diameter(a,0)<<endl;

    return 0;
}




