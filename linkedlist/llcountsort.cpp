/* sort linked list containing 0,1,2 */
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

void node::countsort(node* head) {
    ll co[3]={0,0,0};
    node* ptr=head;
    while(ptr!=NULL) {
        co[ptr->key]++;
        ptr=ptr->next;
    }
    ptr=head;
    ll i=0;
    while(ptr!=NULL) {
        if(co[i]==0)
            i++;
        else {
            ptr->key=i;
            co[i]--;
            ptr=ptr->next;
        }
    }
}

int main()
{
    ll i,j,k,l,e,n,m,t,f,c;
    inp(n);
    node *head=NULL;
    fi(i,0,n) {
        inp(e);
        if(i==0)
            head=head->insert(head,e);
        else
            head->insert(head,e);
    }
    cout<<"Unsorted linked list: ";
    head->print(head);
    cout<<endl;
    head->countsort(head);
    cout<<"Sorted linked list: ";
    head->print(head);
    cout<<endl;
    return 0;
}




