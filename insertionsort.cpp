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
    for(i=0;i<n;i++)
    {
        e=a[i];
        j=i;
        while(j>0 && e<=a[j-1])
        {
            a[j]=a[j-1];
            j--;
        }
        a[j]=e;
    }
    cout<<"\nSorted array is: ";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}


