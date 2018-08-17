/* Print connected components in a graph: Adjacency list */
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
void dfs(vector<ll> adj[],ll node,ll n,ll vis[]) {
    vis[node]=1;
    cout<<node<<" ";

    for(auto it=adj[node].begin();it!=adj[node].end();it++) {
        ll in=*it;
        if(vis[in]==0)
            dfs(adj,in,n,vis);
    }
}
int main()
{
    ll i,j,k,l,e,n,m,t,f,c;
    //No of nodes
    inp(n);
    //No of edges
    inp(m);
    vector<ll> adj[n];
    fi(i,0,m) {
        inp(e);inp(c);
        adj[e].pb(c);
        adj[c].pb(e);
    }
    c=0;
    ll vis[n]={0};
    fi(i,0,n) {
        if(vis[i]==0){
            dfs(adj,i,n,vis);
            cout<<endl;
            c++;
        }
    }

    cout<<"Therefore no of components are: "<<c<<endl;
    
    return 0;
}




