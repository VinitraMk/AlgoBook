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
#define m(a,b) (a>b? b : a)
#define M(a,b) (a>b? a : b)
#define mod 1000000007
using namespace std;

void radixsort(llu a[],llu n,llu p)
{
    llu i;
    llu freq[10];
    fill_n(freq,10,0);
    llu output[n];
    for(i=0;i<n;i++)
        freq[(a[i]/p)%10]++;
    for(i=1;i<10;i++)
        freq[i]+=freq[i-1];
    for(i=n-1;i>=0;i--)
    {
        output[freq[(a[i]/p)%10]-1]=a[i];
        freq[(a[i]/p)%10]--;
    }
    for(i=0;i<n;i++)
        a[i]=output[i];
}

int main()
{
    llu i,j,k,l,t,e,m,n;
    cout<<"Enter no of array elements: ";
    cin>>n;
    llu a[n];
    srand(time(NULL));
    cout<<"Randomly generated array elements are: ";
    m=LLONG_MIN;
    for(i=0;i<n;i++)
    {
        a[i]=(rand()%127)+1;
        m=M(m,a[i]);
        cout<<a[i]<<" ";
    }
    e=1;
    while(m)
    {
        radixsort(a,n,e);
        e*=10;
        m/=10;
    }
    cout<<"\nSorted array is: ";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}


