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
#include<deque>
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
deque<ll> l,r;
ll sz=0;
void zigzag(vector<ll> adj[],ll f,ll n) {
    while(sz<n) {
        while(f==0 && !l.empty()) {
            ll in=l.front();
            cout<<(in+1)<<" ";
            sz++;
            l.pop_front();
            for(ll i=0;i<(ll)adj[in].size();i++)
                r.push_back(adj[in][i]);
        }
        while(f==1 && !r.empty()) {
            ll in=r.back();
            cout<<(in+1)<<" ";
            sz++;
            r.pop_back();
            for(ll i=(ll)adj[in].size()-1;i>=0;i--) 
                l.push_front(adj[in][i]);

        }
        (f==0)?f=1:f=0;
    }
}


int main()
{
    ll i,j,k,e,n,m,t,f,c;
    inp(n);
    vector<ll> a[n];
    inp(m);
    fi(i,0,m) {
        inp(e);inp(c);
        a[e-1].push_back(c-1);
    }
    l.push_front(0);
    zigzag(a,0,n);
    cout<<endl;
    return 0;
}




