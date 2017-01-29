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

void swap(llu *p,llu *q)
{
    llu t=*p;
    *p=*q;
    *q=t;
}

llu partition(llu a[],llu b,llu e)
{
    llu i=b-1;
    llu j;
    llu pivot=a[e];
    for(j=b;j<=e-1;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[e]);
    return (i+1);
}

void quicksort(llu a[],llu b,llu e)
{
    if(b<e)
    {
        llu p=partition(a,b,e);
        quicksort(a,b,p-1);
        quicksort(a,p+1,e);
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
    quicksort(a,0,n-1);
    cout<<"\nSorted array is: ";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}


