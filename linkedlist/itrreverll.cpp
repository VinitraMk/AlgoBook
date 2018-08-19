/* Iteratively reverse a linked list */

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
}node;

node* newnode(ll val) {
    node *temp=(node *)malloc(sizeof(node *));
    temp->val=val;
    temp->next=NULL;
    return temp;
}

void append(node **headref,ll val) {

    node *nn=newnode(val);
    if(*headref==NULL) {
        *headref=nn;
        return;
    }

    node *curr=*headref;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->next=nn;
}

void printlist(node *head) {
    node *curr=head;
    while(curr!=NULL) {
        cout<<curr->val<<" ";
        curr=curr->next;
    }
    cout<<endl;
}

void reverse(node **headref) {

    node *curr=*headref,*next;
    while(curr->next!=NULL) {
        next=curr->next;
        curr->next=next->next;
        next->next=*headref;
        (*headref)=next;
    }

}

int main()
{
    ll i,j,k,l,e,n,m,t,f,c;
    inp(n);
    node *head=NULL;
    fi(i,0,n) {
        inp(e);
        append(&head,e);
    }
    
    cout<<"Given linked list: ";
    printlist(head);

    reverse(&head);
    cout<<"Reversed linked list: ";
    printlist(head);
    return 0;
}




