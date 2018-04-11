import java.util.*;
import java.lang.*;
import java.io.*;
class primmst 
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int i,j,n,u,v,p,c,min;
        System.out.println("Enter no of vertices in the graph: ");
        n=sc.nextInt();
        int inf=Integer.MAX_VALUE;
        int[][] adj=new int[n][n];
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                adj[i][j]=inf;
        }
        System.out.print("Enter no of edges: ");
        p=sc.nextInt();
        int tc=inf;
        min=-1;
        for(i=0;i<p;i++)
        {
            u=sc.nextInt();
            v=sc.nextInt();
            c=sc.nextInt();
            adj[u-1][v-1]=c;
            adj[v-1][u-1]=c;
        }
        int[] mst=new int[n];
        int[] minedge=new int[n];
        boolean[] mstset=new boolean[n];
        for(i=0;i<n;i++)
        {
            minedge[i]=inf;
            mstset[i]=false;
        }
        minedge[0]=0;
        mst[0]=-1;
        int mi;
        for(i=0;i<n-1;i++)
        {
            min=inf;
            mi=-1;
            for(j=0;j<n;j++)
            {
                if(mstset[j]==false && minedge[j]<min)
                {
                    min=minedge[j];
                    mi=j;
                }
            }
            //System.out.println(mi);
            u=mi;
            mstset[u]=true;
            for(j=0;j<n;j++)
            {
                if(adj[u][j]!=inf && mstset[j]==false && adj[u][j]<minedge[j])
                {
                    mst[j]=u;
                    minedge[j]=adj[u][j];
                }
            }
        }
        System.out.println("Edge  Weight");
        int m=0;
        for(i=1;i<n;i++)
        {
            System.out.println(mst[i]+"--"+i+"     "+adj[i][mst[i]]);
            m+=(adj[i][mst[i]]);
        }
        System.out.println("Cost is: "+m);
    }
}

