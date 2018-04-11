#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<utility>
#include<queue>
#include<numeric>
#include<ctime>
#include<climits>
#define llu long long
#define N 100000
#define inf 0x3f3f3f3f
#define m(a,b) (a>b? b : a)
#define M(a,b) (a>b? a : b)
#define mod 1000000007
using namespace std;

int main()
{
    llu i,j,k,l,t,e,m,n;
    cout<<"Enter no of array elements: ";
    cin>>n;
    srand(time(NULL));
    llu a[n+1],b[n+1];
    cout<<"Randomly generated array elements are: ";
    m=LLONG_MIN;
    for(i=1;i<=n;i++)
    {
        a[i]=(rand()%127)+1;
        m=M(m,a[i]);
        cout<<a[i]<<" ";
    }
    llu c[m+1];
    fill_n(c,m+1,0);
    for(i=1;i<=n;i++)
        c[a[i]]+=1;
    for(i=1;i<(m+1);i++)
        c[i]+=c[i-1];
    for(i=n;i>=1;i--)
    {
        b[c[a[i]]]=a[i];
        c[a[i]]-=1;
    }
    cout<<"\nThe sorted array is: ";
    for(i=1;i<=n;i++)
        cout<<b[i]<<" ";
    cout<<endl;
    return 0;
}


