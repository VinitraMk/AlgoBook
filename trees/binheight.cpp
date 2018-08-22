/* Diameter of a binary tree */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<utility>
#include<queue>
#include<bitset>
#include<numeric>
#define ll long long
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define ipair pair<ll,ll>
#define inp(a) scanf("%lld",&a)
#define out(a) printf("%lld\n",a)
#define allv(a) a.begin(),a.end()
#define alla(a,n) a,a+n
#define fi(i,a,b) for(ll i=a;i<b;i++)
#define N 100000
#define set(n,x) x|=(1<<n)
#define unset(n,x) x&=~(1<<n)
#define chkbit(n,x) (x&(1<<n))!=0
#define m(a,b) (a>b? b : a)
#define M(a,b) (a>b? a : b)
#define mod 1000000007
using namespace std;

typedef struct node {
    ll val;
    struct node *left,*right;
}node;

node* newnode(ll val) {
    node *temp=(node *)malloc(sizeof(node *));
    temp->val=val;
    temp->left=temp->right=NULL;
    return temp;
}

ll getheight(node *root,ll& h) {
    if(root==NULL)
        return 0;
    ll lh=getheight(root->left,h);
    ll rh=getheight(root->right,h);

    h=M(h,lh+rh+1);

    return (1+M(lh,rh));
}


int main()
{
    ll i,j,k,l,e,n,m,t,f,c;
    node *root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    e=-inf;
    m=getheight(root,e);
    cout<<e<<endl;
    
    return 0;
}




