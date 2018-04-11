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

void lcs(string x,string y,ll n,ll m) {
    ll lcs[n+1][m+1];
    ll i,j;
    fi(i,0,n+1) {
        fi(j,0,m+1) {
            if(i==0 || j==0)
                lcs[i][j]=0;
            else if(x[i-1]==y[j-1]) 
                lcs[i][j]=lcs[i-1][j-1]+1;
            else
                lcs[i][j]=M(lcs[i-1][j],lcs[i][j-1]);
            //cout<<lcs[i][j]<<" ";
        }
        //cout<<endl;
    }

    cout<<"The length of the longest common subsequence: "<<lcs[n][m]<<endl;

    ll in=lcs[n][m];
    string res="";
    i=n,j=m;
    while(i>0 && j>0) {
        if(x[i-1]==y[j-1]) {
            res+=x[i-1];
            i--;
            j--;
        }
        else if(lcs[i-1][j] > lcs[i][j-1])
            i--;
        else
            j--;
    }
    reverse(res.begin(),res.end());
    cout<<"LCS of "<<x<<" and "<<y<<" is "<<res<<endl;
}
int main()
{
    ll i,j,k,l,e,n,m,t,f,c;
    string x,y;
    cin>>x;
    cin>>y;
    n=x.length();
    m=y.length();
    lcs(x,y,n,m);
    return 0;
}




