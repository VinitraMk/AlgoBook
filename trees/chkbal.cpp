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

struct node {
    ll key;
    struct node *left,*right;
};

struct node *newnode(ll key) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key=key;
    temp->left=temp->right=NULL;
    return temp;
}

struct node* insert(struct node* node,ll key) {
    if(node==NULL)
        return newnode(key);

    if(key<node->key)
        node->left=insert(node->left,key);
    else
        node->right=insert(node->right,key);
    return node;
}

void inorder(struct node *root) {
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%lld ",root->key);
    inorder(root->right);
}

bool ifbal(struct node *root,ll *height) {
    ll lh=0,rh=0;
    bool l=false,r=false;
    if(root==NULL) {
        *height=0;
        return true;
    }
    l=ifbal(root->left,&lh);
    r=ifbal(root->right,&rh);

    *height=M(lh,rh)+1;

    if((lh-rh>=2) || (rh-lh)>=2)
        return false;
    else
        return l&&r;
}

int main()
{
    ll i,j,k,l,e,n,m,t,f,c;
    inp(n);
    struct node *root=NULL;
    fi(i,0,n) {
        inp(e);
        if(i==0)
            root=insert(root,e);
        else
            insert(root,e);
    }
    inorder(root);
    cout<<endl;
    e=0;
    if(ifbal(root,&e))
        cout<<"Tree is balanced!"<<endl;
    else
        cout<<"Tree is not balanced!"<<endl;
    return 0;
}




