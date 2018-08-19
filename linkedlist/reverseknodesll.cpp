/* reverse every k nodes in a linked list */
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

void push(node **headref,ll val) {

    if(*headref==NULL) 
        *headref=newnode(val);
    else {
        node *nn=newnode(val);
        nn->next=*headref;
        *headref=nn;
    }
}

node* append(node *headref, ll val) {
    if(headref==NULL) 
        headref=newnode(val);
    else {
        node *temp=headref;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode(val);
    }
    return headref;
}

void printlist(node *head) {
    node *temp=head;
    while(temp!=NULL) {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}

void appendtoll(node **newhead,node **end,node *temphead,node *tempend) {
    if(*newhead==NULL) {
        *newhead=temphead;
        *end=tempend;
    }
    else {
        (*end)->next=temphead;
        *end=tempend;
    }
}

node* newll(node *newhead,node *head,ll n,ll k) {

    ll e=0;
    ll c=0;
    node *temp=head,*end=NULL,*tempend=NULL,*temphead=NULL;

    while(temp!=NULL && c<((n/k)*k)) {
        c++;
        if(c%k==0) {
            push(&temphead,temp->val);
            appendtoll(&newhead,&end,temphead,tempend);
            temphead=NULL;
            tempend=NULL;
        }
        else {
            push(&temphead,temp->val);
            if(c%k==1) 
                tempend=temphead;
        }
        temp=temp->next;
    }
    while(temp!=NULL) {
        end->next=newnode(temp->val);
        end=end->next;
        temp=temp->next;
    }
    return newhead;
}


int main()
{
    ll i,j,k,l,e,n,m,t,f,c;
    node *head=NULL;
    inp(n);inp(k);
    fi(i,0,n) {
        inp(e);
        if(i==0)
            head=append(head,e);
        else
            append(head,e);
    }
    cout<<"The given linked list is: ";
    printlist(head);
    cout<<endl;
    node *newhead=NULL,*temphead=NULL;
    newhead=newll(newhead,head,n,k);
    cout<<"The new linked list is: ";
    printlist(newhead);
    cout<<endl;

    return 0;
}




