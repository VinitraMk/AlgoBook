/* BST to doubly linked list conversion */
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
    struct node *next,*prev;
} node;

typedef struct tnode {
    ll val;
    struct tnode *left,*right;
} tnode;

node *head=NULL;
node* newnode(ll val) {
    node *temp = (node *)malloc(sizeof(node *));
    temp->val=val;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
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


void push(node **headref,ll val) {
    node *nn=newnode(val);
    if(*headref==NULL) {
        *headref=nn;
        return;
    }
    nn->next=*headref;
    (*headref)->prev=nn;
    *headref=nn;
}

void inorder(tnode *root) {
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void rightfirst(tnode *root) {
    if(root==NULL)
        return;
    rightfirst(root->right);
    push(&head,root->val);
    rightfirst(root->left);
}

int main()
{
    ll i,j,k,l,e,n,m,t,f,c;
    tnode *root=newtnode(6);
    root->left=newtnode(2);
    root->right=newtnode(9);
    root->left->left=newtnode(1);
    root->left->right=newtnode(3);
    root->right->left=newtnode(8);
    root->right->right=newtnode(13);

    cout<<"The given BST inorder traversal is: ";
    inorder(root);
    cout<<endl;

    rightfirst(root);
    cout<<"Constructed doubly linked list is: ";
    printlist();
    cout<<endl;


    return 0;
}




