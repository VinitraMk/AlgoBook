/* given 2 sorted linked list, construct a third with elements of first not present in second */
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
class node {

    public:
    ll key;
    node* next;
    node* insert(node*,ll);
    void print(node*);
    void countsort(node*);
    node* aminusb(node*,node*);
};

node* node::insert(node* head,ll key) {
    if(head==NULL) {
        head=(node *)malloc(sizeof(node *));
        head->key=key;
        head->next=NULL;
        return head;
    }
    else {
        node* last=head;
        node* nn = (node *)malloc(sizeof(node *));
        nn->key=key;
        nn->next=NULL;
        while(last->next!=NULL)
            last=last->next;
        last->next=nn;
        return last;
    }
}

void node::print(node* head) {
    while(head!=NULL) {
        cout<<head->key<<" ";
        head=head->next;
    }
}

node* node::aminusb(node* h3,node* h2) {

    node* p1=h3;
    node* p2=h2;
    node* prev=NULL;

    while(p1!=NULL && p2!=NULL) {
        if(p1->key==p2->key) {
            if(prev!=NULL) {
                prev->next=p1->next;
                p2=p2->next;
            }
            else {
                h3=p1->next;
                p2=p2->next;
            }
        }
        prev=p1;
        p1=p1->next;
    }
    return h3;
}

int main()
{
    ll i,j,k,l,e,n,m,t,f,c;
    inp(n);
    inp(m);

    node* head1=NULL;
    node* head2=NULL;
    node* head3=NULL;
    fi(i,0,n) {
        inp(e);
        if(i==0)
            head1=head1->insert(head1,e);
        else
            head1->insert(head1,e);
    }
    head3=head1;
    fi(i,0,m) {
        inp(e);
        if(i==0)
            head2=head2->insert(head2,e);
        else
            head2->insert(head2,e);
    }
    cout<<"\nLinked List A: ";
    head1->print(head1);
    cout<<endl;
    cout<<"\nLinked List B: ";
    head2->print(head2);
    cout<<endl;
    cout<<"\nLinked List C: ";
    head3=head3->aminusb(head3,head2);
    head3->print(head3);
    cout<<endl;
    return 0;
}

