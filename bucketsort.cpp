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

void bucketsort(float a[],llu n)
{
    vector<float> b[n];
    llu i,j,in;
    for(i=0;i<n;i++)
    {
        in=(n*a[i]);
        b[in].push_back(a[i]);
    }
    for(i=0;i<n;i++)
        sort(b[i].begin(),b[i].end());
    in=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<b[i].size();j++)
        {
            a[in++]=b[i][j];
        }
    }
}
int main()
{
    llu i,j,k,l,t,e,m,n;
    cout<<"Enter no of array elements: ";
    cin>>n;
    srand(time(NULL));
    float a[n];
    cout<<"Randomly generated array elements are: ";
    for(i=0;i<n;i++)
    {
        a[i]=((float)rand()/(RAND_MAX));
        cout<<a[i]<<" ";
    }
    bucketsort(a,n);
    cout<<"\nSorted array is: ";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}


