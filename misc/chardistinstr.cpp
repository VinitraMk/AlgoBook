/* Given a string and 2 characters find the minimum distance between the 2 characters in the string */
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
    string s;
    cin>>s;
    char ch1,ch2;
    cin>>ch1>>ch2;
    n=s.length();
    e=inf;
    c=inf;
    f=0,t=0;
    char p='\0';
    fi(i,0,n) {
        if(f==0 && t==0 && (s[i]==ch1 || s[i]==ch2)) {
            f=1;
            p=s[i];
            c=1;
        }
        else if(f!=0 && t==0 && (s[i]==ch1 || s[i]==ch2)) {
            if(s[i]!=p) {
                t=1;
                p=s[i];
                e=m(e,c);
                c=1;
            }
            else
                c=1;
        }
        else if(f!=0 && t!=0 && (s[i]==ch1 || s[i]==ch2)) {
            if(s[i]!=p) {
                p=s[i];
                e=m(e,c);
                c=1;
            }
            else
                c=1;
        }
        else if(s[i]!=ch1 && s[i]!=ch2)
            c++;
    }
    cout<<e<<endl;
    return 0;
}




