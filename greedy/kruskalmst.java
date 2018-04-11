import java.util.*;
import java.lang.*;
import java.io.*;
class edge
{
    int u,v,w;
    edge(int s,int d,int c)
    {
        this.u=s;
        this.v=d;
        this.w=c;
    }
    public int src()
    {
        return u;
    }
    public int des()
    {
        return v;
    }
    public int cost()
    {
        return w;
    }
};

class comp implements Comparator<edge>
{
    public int compare(edge a,edge b)
    {
        return a.w - b.w;
    }
};
class kruskalmst 
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int i,j,n,p,u,v,c;
        System.out.println("Enter no of nodes in the graph: ");
        n=sc.nextInt();
        System.out.println("Enter no of edges: ");
        p=sc.nextInt();
        int inf=Integer.MAX_VALUE;
        ArrayList<edge> adj=new ArrayList<edge>();
        for(i=0;i<p;i++)
        {
            u=sc.nextInt();
            v=sc.nextInt();
            c=sc.nextInt();
            adj.add(new edge(u-1,v-1,c));
        }
        Collections.sort(adj,new comp());
        edge[] res=new edge[n];
        int[] par=new int[n];
        for(i=0;i<n;i++)
            par[i]=-1;
        i=0;
        j=0;
        while(j<n-1)
        {
            edge e=adj.get(i);
            i++;
            int x=find(par,e.src());
            int y=find(par,e.des());
            if(x!=y)
            {
                res[j++]=e;
                union(par,x,y);
            }
        }
        System.out.println("Following are edges in the mst: ");
        int m=0;
        for(i=0;i<n-1;i++)
        {
            System.out.println(res[i].src()+"--"+res[i].des()+"   "+res[i].cost());
            m+=res[i].cost();
        }
        System.out.println("Cost is: "+m);
    }
    public static int find(int par[],int i)
    {
        if(par[i]==-1)
            return i;
        return find(par,par[i]);
    }

    public static void union(int par[],int x,int y)
    {
        int xs=find(par,x);
        int ys=find(par,y);
        par[xs]=ys;
    }
}

