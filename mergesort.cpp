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
#define llu long long
#define N 100000
#define m(a,b) (a>b? b : a)
#define M(a,b) (a>b? a : b)
#define mod 1000000007
using namespace std;

llu c[N];
void merge(llu a[],llu b,llu m,llu e)
{
    llu i=b,j=m+1,k=0;
    llu l1=m-b+1;
    llu l2=e-m;
    for(llu p=b;p<=e;p++)
    {
        if(i>m)
            c[k++]=a[j++];
        else if(j>e)
            c[k++]=a[i++];
        else if(a[i]<a[j])
            c[k++]=a[i++];
        else 
            c[k++]=a[j++];
    }
    for(i=0;i<k;i++)
        a[b++]=c[i];
}

    
void  mergesort(llu a[],llu b,llu e)
{
    if(b<e)
    {
        llu m=(b+e)/2;
        mergesort(a,b,m);
        mergesort(a,m+1,e);
        merge(a,b,m,e);
    }
}
int main()
{
    llu i,j,k,l,t,e,m,n;
    cout<<"Enter no of array elements: ";
    cin>>n;
    llu a[n];
    srand(time(NULL));
    cout<<"Randomly generated array elements are: ";
    for(i=0;i<n;i++)
    {
        a[i]=(rand()%127)+1;
        cout<<a[i]<<" ";
    }
    mergesort(a,0,n-1);
    cout<<"\nThe sorted array is: ";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}


