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


ll merge(ll a[],ll l,ll m,ll r,ll temp[]) {
    ll n1=m-l+1;
    ll n2=r-m;
    ll i=0,j=0,k=l;
    i=l,j=m+1;
    ll c=0;
    while(i<=m && j<=r) {
        if(a[i]>a[j]) {
            temp[k++]=a[j++];
            c+=(m+1-i);
        }
        else 
            temp[k++]=a[i++];
    }
    while(i<=m) 
        temp[k++]=a[i++];
    while(j<=r)
        temp[k++]=a[j++];
    fi(i,l,r+1)
        a[i]=temp[i];
    return c;
}

ll mergesort(ll s,ll e,ll a[],ll temp[]) {
    ll c=0;
    if(e>s) {
        ll m=(s+e)/2;
        c=mergesort(s,m,a,temp);
        c+=mergesort(m+1,e,a,temp);
        c+=merge(a,s,m,e,temp);
    }
    return c;
}
int main()
{
    ll i,j,k,l,e,n,m,t,f,c;
	inp(t);
	while(t--) {
        inp(n);
        ll a[n];
        fi(i,0,n)
            inp(a[i]);
        ll temp[n];
        c=mergesort(0,n-1,a,temp);
        /*fi(i,0,n)
            cout<<a[i]<<" ";
        cout<<endl;*/
        cout<<c<<endl;
	}
    return 0;
}




