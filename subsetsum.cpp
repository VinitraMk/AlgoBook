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
#define llu long long
#define N 100000
#define m(a,b) (a>b? b : a)
#define M(a,b) (a>b? a : b)
#define mod 1000000007
using namespace std;
void printsubset(llu tar[],llu size)
{
    for(llu i=0;i<size;i++)
        cout<<tar[i]<<" ";
    cout<<endl;
}
void subsetselect(llu A[],llu n,llu k,llu tar[],llu tars,llu sum,llu start)
{
    if(sum==k)
    {
        printsubset(tar,tars);
        subsetselect(A,n,k,tar,tars-1,sum-A[start-1],start+1);
        return;
    }
    else
    {
        for(llu i=start;i<n;i++)
        {
            tar[tars]=A[i];
            subsetselect(A,n,k,tar,tars+1,sum+A[i],i+1);
        }
    }
}
int main()
{
    llu i,j,k,l,t,e,m,n;
    srand(time(NULL));
    n=rand()%10+1;
    llu A[n],tar[n];
    k=rand()%10+1;
    cout<<n<<" "<<k<<endl;
    for(i=1;i<=n;i++)
        A[i-1]=i;
    for(j=n-1;j>=0;j--)
    {
        e=rand()%n;
        swap(A[e],A[j]);
    }
    for(i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
    subsetselect(A,n,k,tar,0,0,0);
    return 0;
}


