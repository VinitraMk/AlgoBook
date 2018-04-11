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
llu heap[N];
void swap(llu *p,llu *q)
{
    llu t=*p;
    *p=*q;
    *q=t;
}
void buildheap(llu a[],llu n)
{
    llu i;
    for(i=0;i<n;i++)
    {
        heap[i]=a[i];
        if(i>0 && (heap[i]>heap[0]))
            swap(&heap[i],&heap[0]);
    }
}
void heapify(llu heap[],llu hp)
{
    llu i;
    for(i=1;i<hp;i++)
    {
        if(heap[i]>heap[0])
            swap(&heap[i],&heap[0]);
    }
}
        
void heapsort(llu a[],llu n)
{
    llu i;
    llu hp=n;
    buildheap(a,hp);
    for(i=hp-1;i>=1;i--)
    {
        swap(&heap[0],&heap[i]);
        hp--;
        if(hp>1)
            heapify(heap,hp);
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
    heapsort(a,n);
    cout<<"\nSorder array is: ";
    for(i=0;i<n;i++)
        cout<<heap[i]<<" ";
    cout<<endl;
    return 0;
}


