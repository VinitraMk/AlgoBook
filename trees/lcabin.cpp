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

node* newnode(ll val){
    node *temp=(node *)malloc(sizeof(node *));
    temp->val=val;
    temp->left=temp->right=NULL;
}

node* lca(node *root,ll a,ll b,bool &v1,bool &v2) {
    if(root==NULL)
        return NULL;
    if(root->val==a) {
        v1=true;
        return root;
    }
    if(root->val==b) {
        v2=true;
        return root;
    }
    node *ln=lca(root->left,a,b,v1,v2);
    node *rn=lca(root->right,a,b,v1,v2);

    if(ln && rn)
        return root;
    return (ln!=NULL)?ln:rn;
}


int main()
{
    ll i,j,k,l,e,n,m,t,f,c;
    node *root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->left->right->left=newnode(8);
    root->left->right->right=newnode(9);
    root->right->left=newnode(6);
    root->right->right=newnode(7);
    bool v1=false,v2=false;
    node *ans=lca(root,4,9,v1,v2);
    if(v1 && v2)
        cout<<"The lca of 4 and 9 is:"<<ans->val<<endl;
    else
        cout<<"No lca as either 4 or 9 is not present in the tree"<<endl;
    return 0;
}




