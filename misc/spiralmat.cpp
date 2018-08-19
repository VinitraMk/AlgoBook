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
    inp(n);inp(m);
    ll mat[n][m];
    e=n,c=m;
    i=0,j=0,k=0;
    f=1;
    while(i<n && j<m) {
        for(k=j;k<m;k++,f++)
            mat[i][k]=f;
        i++;
        for(k=i;k<n;k++,f++)
            mat[k][m-1]=f;
        m--;

        if(i<n) {
            for(k=m-1;k>=j;k--,f++)
                mat[n-1][k]=f;
            n--;
        }

        if(j<m) {
            for(k=n-1;k>=i;k--,f++)
                mat[k][j]=f;
            j++;
        }
                
    }
    fi(i,0,e) {
        fi(j,0,c)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}




