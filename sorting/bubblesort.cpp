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

int main()
{
    llu i,j,k,l,t,e,m,n;
    cout<<"Enter no of elements: ";
    cin>>n;
    llu a[n];
    srand(time(NULL));
    cout<<"Randomly generated array elements are: ";
    for(i=0;i<n;i++)
    {
        e=(rand()%127)+1;
        a[i]=e;
        cout<<a[i]<<" ";
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<(n-i-1);j++)
        {
            if(a[j]>a[j+1])
                swap(&a[j],&a[j+1]);
        }
    }
    cout<<"\nSorted array is: ";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}


