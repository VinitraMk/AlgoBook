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

ll findpivot(ll a[],ll b,ll e) {

    if(b>e)
        return -1;
    if(b==e)
        return b;

    ll m=(b+e)/2;

    if(m<e && a[m]>a[m+1])
        return m;
    if(m>b && a[m]<a[m-1])
        return (m-1);

    if(a[b]>=a[m])
        return findpivot(a,b,m-1);
    return findpivot(a,m+1,e);
}

ll binarysearch(ll a[],ll l,ll r,ll k) {
    ll in=-1;
    while(l<=r) {
        ll m=(l+r)/2;
        if(k>a[m])
            l=m+1;
        else if(k<a[m])
            r=m-1;
        else {
            in=m;
            break;
        }
    }
    return in;
}


ll pivotsearch(ll a[],ll n,ll k) {

    ll pivot=findpivot(a,0,n-1);
    if(pivot==-1)
        return binarysearch(a,0,n-1,k);

    if(a[pivot]==k)
        return pivot;
    else if(k>a[pivot])
        return binarysearch(a,0,pivot-1,k);
    else
        return binarysearch(a,pivot+1,n-1,k);
}

int main()
{
    ll i,j,k,l,e,n,m,t,f,c;
    inp(n);
    ll a[n];
    fi(i,0,n)
        inp(a[i]);
    inp(k);
    cout<<"The index of "<<k<<" is: "<<pivotsearch(a,n,k)<<endl;

    return 0;
}




