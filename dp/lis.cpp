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

ll lis[N];
void printlis(ll lis[],ll li,ll a[],ll max) {
    if(max==0)
        return;
    if(lis[li]==max) {
        printlis(lis,li-1,a,max-1);
        cout<<a[li]<<" ";
    }
    else
        printlis(lis,li-1,a,max);

}

ll Lis(ll a[],ll n) {
    ll i,j,m=0;
    fi(i,0,n)
        lis[i]=1;
    fi(i,1,n) {
        fi(j,0,i) {
            if(a[i]>a[j] && lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
        }
    }

    fi(i,0,n) 
        m=M(lis[i],m);

    return m;
}
int main()
{
    ll i,j,k,l,e,n,m,t,f,c;
    inp(n);
    ll a[n];
    fi(i,0,n)
        inp(a[i]);
    m=Lis(a,n);
    cout<<"Length of longest increasing subsequence: "<<m<<endl;
    cout<<"The longest increasing subsequence is: ";
    printlis(lis,n-1,a,m);
    cout<<endl;
    return 0;
}




