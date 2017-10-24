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

llu kadane(llu a[], llu n)
{
	llu max_till_now = a[0];
	llu currmax = a[0];

	for (int i=1;i<n;i++)
	{
			currmax = max(a[i], currmax+a[i]);
			max_till_now = max(max_till_now, currmax);
	}
	return max_till_now;
}

int main()
{
	llu n;
	cin>>n;
	llu i,a[n];
	for(i=0;i<n;i++) cin>>a[i];
	llu ans = kadane(a, n);
	cout<<ans<<endl;
	return 0;
}

