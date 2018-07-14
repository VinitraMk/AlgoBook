/*Application of getting a median in a sliding window on an array*/
/*Problem link: https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem */
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

ll find(ll b[],ll d) {
    ll c=0;
    ll i,mi=0;
    fi(i,0,201) {
        c+=b[i];
        if(c>=d) {
            mi=i;
            break;
        }

    }
    return mi;

}
int main()
{
    ll i,j,k,l,e,n,m,t,f,c;
    inp(n);inp(k);
    vector<ll> v;
    ll a[n];
    ll b[201]={0};
    fi(i,0,n) 
        inp(a[i]);
    c=0;
    fi(i,0,n) {
        if(i>=k) {
            ll d=(k/2)+(k%2);
            f=find(b,d);
            if(k%2==0) {
                e=find(b,k/2+1);
                if(a[i]>=(e+f))
                    c++;
            }
            else {
                if(a[i]>=2*f)
                    c++;
            }
        }
        b[a[i]]++;
        if(i>=k) 
            b[a[i-k]]--;
    }
    cout<<c<<endl;
    return 0;
}




