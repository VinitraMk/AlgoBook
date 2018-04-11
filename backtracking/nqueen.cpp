#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<utility>
#include<queue>
#include<numeric>
#define llu long long
#define N 8
#define m(a,b) (a>b? b : a)
#define M(a,b) (a>b? a : b)
#define mod 1000000007
using namespace std;
llu n;
llu board[N][N];

void init()
{
    llu i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            board[i][j]=0;
        }
    }
}

bool issafe(llu board[N][N],llu row,llu col)
{
    llu i,j;
    for(i=0;i<row;i++)
    {
        if(board[i][col])
            return false;
    }
    for(i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j])
            return false;
    }
    for(i=row,j=col;i>=0 && j<n;i--,j++)
    {
        if(board[i][j])
            return false;
    }
    return true;
}

bool nqueen(llu board[N][N],llu n,llu r)
{
    llu i,j;
    if(r>=n)
        return true;
    else
    {
        for(i=0;i<n;i++)
        {
            if(issafe(board,r,i))
            {
                board[r][i]=1;
                if(nqueen(board,n,r+1))
                    return true;
                board[r][i]=0;
            }
        }
    }
    return false;
}

int main()
{
    init();
    llu i,j,k,l,t,e,m;
    srand(time(NULL));
    n=rand()%8+1;
    cout<<n<<endl;
    if(!nqueen(board,n,0))
        cout<<"No solution"<<endl;
    else
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                cout<<board[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}


