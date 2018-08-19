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

ll lcabst(node *root,ll a,ll b) {

    if(root==NULL)
        return -1;
    if(root->val==a || root->val==b || (a<root->val && root->val<b))
        return root->val;
    if(root->val>a)
        lcabst(root->left,a,b);
    else if(root->val<a)
        lcabst(root->right,a,b);
}


int main()
{
    ll i,j,k,l,e,n,m,t,f,c;
    node *root=newnode(20);
    root->left=newnode(8);
    root->right=newnode(22);
    root->left->left=newnode(4);
    root->left->right=newnode(12);
    root->left->right->left=newnode(10);
    root->left->right->left=newnode(14);

    cout<<"\nFor the given binary search tree lca of 8 & 14: "<<lcabst(root,8,14)<<endl;
    cout<<"\nFor the given binary search tree lca of 10 & 22: "<<lcabst(root,10,22)<<endl;


    return 0;
}




