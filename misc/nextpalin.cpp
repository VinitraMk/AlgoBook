/* Given a number N, print the next higher palindrome */
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    long int i,j,t,n,l,mid,rep;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        l=s.length();
        string pal(s.rbegin(),s.rend());
        long int c=count(s.begin(),s.end(),'9');
        if(c==l)
        {
            pal.clear();
            pal.append("1");
            for(i=1;i<=(l-1);i++)
                pal.append("0");
            pal.append("1");
            cout<<pal<<endl;
        }
        else
        {
            string pal(s.begin(),s.end());
            if(l%2==0)
                mid=(l/2)-1;
            else
                mid=l/2;
            for(i=0;i<l/2;i++)
            {
                if(pal[i]!=pal[l-i-1])
                    pal[l-i-1]=pal[i];
            }
            if(pal<=s)
            {
                rep=pal[mid]-'0';
                rep=rep+1;
                if(rep<10)
                    pal[mid]= rep+'0' ;
                else
                {
                    pal[mid]='0';
                    for(i=mid-1;i>=0;)
                    {
                        rep=pal[i]-'0';
                        rep++;
                        if(rep<10)
                        {
                            pal[i]= rep+'0' ;
                            break;
                        }
                        else
                        {
                            pal[i]='0';
                            i--;
                        }
                    }
                }
                for(i=0;i<l/2;i++)
                {
                    if(pal[i]!=pal[l-i-1])
                        pal[l-i-1]=pal[i];
                }
            }
            cout<<pal<<endl;
        }
    }
    return 0;
} 
