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
    cout<<"Randomly generated array elements are: ";
    srand(time(NULL));
    for(i=0;i<n;i++)
    {
        a[i]=(rand()%127)+1;
        cout<<a[i]<<" ";
    }
    for(i=0;i<n-1;i++)
    {
        m=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[m])
                m=j;
        }
        swap(a[m],a[i]);
    }
    cout<<"\nSorted array is: ";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}


