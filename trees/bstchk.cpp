/* Check if tree is BST or not */

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

//typedef struct node node;
node* newnode(ll val) {
    node *temp = (node *)malloc(sizeof(node));
    temp->val=val;
    temp->left=temp->right=NULL;
    return temp;
}

bool isbst(node *nn,node *l=NULL,node *r=NULL) {
    //cout<<nn->val<<endl;
    if(nn==NULL) 
        return true;

    if(l!=NULL && nn->val<l->val) 
        return false;
    
    if(r!=NULL && nn->val>r->val) 
        return false;
    

    return (isbst(nn->left,l,nn) && isbst(nn->right,nn,r));

}


int main()
{
    ll i,j,k,l,e,n,m,t,f,c;
    node *root=newnode(3);
    root->left=newnode(2);
    root->right=newnode(5);
    root->left->left=newnode(1);
    root->left->right=newnode(4);

    if(isbst(root))
        cout<<"Is BST"<<endl;
    else
        cout<<"Is not BST"<<endl;
    return 0;
}




