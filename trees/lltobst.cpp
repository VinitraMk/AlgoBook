/* Given a linked list, convert it into a balanced BST */

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
    struct node *next;
} node;

typedef struct tnode {
    ll val;
    struct tnode *left,*right;
} tnode;

tnode *root=NULL;
node *head=NULL;
node* newnode(ll val) {
    node *temp = (node *)malloc(sizeof(node *));
    temp->val=val;
    temp->next=NULL;
    return temp;
}

void append(node **headref,ll val) {
    node *nn=newnode(val);
    node *last=*headref;

    if(*headref==NULL) {
        *headref=nn;
        return;
    }
    while(last->next!=NULL)
        last=last->next;
    last->next=nn;
}

tnode* newtnode(ll val) {
    tnode *temp = (tnode *)malloc(sizeof(tnode *));
    temp->val=val;
    temp->left=temp->right=NULL;
    return temp;
}

void printlist() {
    node *n=head;
    while(n!=NULL) {
        cout<<n->val<<" ";
        n=n->next;
    }
    return;
}


tnode* getBst(node **headref,ll n) {
    if(n<=0)
        return NULL;

    tnode *left=getBst(headref,n/2);
    tnode *root=newtnode((*headref)->val);
    root->left=left;

    *headref=(*headref)->next;
    root->right=getBst(headref,n-n/2-1);
    return root;
}

void inorder(tnode *root) {

    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}


int main()
{
    ll i,j,k,l,e,n,m,t,f,c;
    inp(n);
    fi(i,0,n) {
        inp(e);
        append(&head,e);
    }

    cout<<"Given Linked list: ";
    printlist();
    cout<<endl;

    root=getBst(&head,n);
    cout<<"After converting to Balanced BST: ";
    inorder(root);
    cout<<endl;
    return 0;
}




