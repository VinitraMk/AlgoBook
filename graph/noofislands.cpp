/* Given a 2D boolean matrix, find the number of islands. A group of connected 1s form an island */

/* Input; 
 * 1 1 0 0 0
 * 0 1 0 0 1
 * 1 0 0 1 1
 * 0 0 0 0 0
 * 1 0 1 0 1
 *
 * Output:
 * 5
 *
 */

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
#define N 100
#define set(n,x) x|=(1<<n)
#define unset(n,x) x&=~(1<<n)
#define chkbit(n,x) (x&(1<<n))!=0
#define m(a,b) (a>b? b : a)
#define M(a,b) (a>b? a : b)
#define mod 1000000007
using namespace std;

ipair coor[8];
void dfs(ll mat[N][N],ll i,ll j,ll n,ll vis[N][N]) {
    vis[i][j]=1;

    fi(k,0,8) {
        ll x=i+coor[k].first;
        ll y=j+coor[k].second;
        if(x>=0 && x<n && y>=0 && y<n && mat[x][y] && !vis[x][y])
            dfs(mat,x,y,n,vis);
    }
}


int main()
{
    ll i,j,k,l,e,n,m,t,f,c;
    coor[0]=mp(-1,-1);
    coor[1]=mp(-1,0);
    coor[2]=mp(-1,1);
    coor[3]=mp(0,-1);
    coor[4]=mp(0,1);
    coor[5]=mp(1,-1);
    coor[6]=mp(1,0);
    coor[7]=mp(1,1);
    inp(n);
    ll mat[N][N];
    fi(i,0,n) {
        fi(j,0,n)
            cin>>mat[i][j];
    }

    ll vis[N][N];
    memset(vis,0,sizeof(vis));
    c=0;
    fi(i,0,n) {
        fi(j,0,n) {
            if(mat[i][j] && !vis[i][j]) {
                dfs(mat,i,j,n,vis);
                c++;
            }
        }
    }
    cout<<"No of islands: "<<c<<endl;
    return 0;
}




