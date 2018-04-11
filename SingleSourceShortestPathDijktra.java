import java.util.*;
import java.io.*;
import java.lang.*;

class SingleSourceShortestPathDijktra 
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int i,j,n,u,v,p,c,imin,min;
        int INT_MAX=Integer.MAX_VALUE;
        System.out.println("Enter no of vertices in the graph: ");
        n=sc.nextInt();
        int[][] adj=new int[n][n];
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                adj[i][j]=0;
        }
        System.out.println("The paths in the graph are: ");
        System.out.println("Src     Destination     Cost");
        int in;
        for(i=1;i<=n;i++)
        {
            in=(int)((Math.random()*n)+1);
            while(in==i)
                in=(int)((Math.random()*n)+1);
            c=(int)((Math.random()*100)+1);
            adj[i-1][in-1]=c;
            adj[in-1][i-1]=c;
            System.out.println(i+"        "+in+"              "+c);
        }
        int s=(int)((Math.random()*n)+1);
        int[] dist=new int[n];
        int[] set=new int[n];
        for(i=0;i<n;i++)
        {
            dist[i]=INT_MAX;
            //System.out.println(dist[i]);
            set[i]=0;
        }
        dist[s-1]=0;
        imin=0;
        for(i=0;i<n;i++)
        {
            min=INT_MAX;
            for(j=0;j<n;j++)
            {
                if((dist[j]<=min) && (set[j]==0))
                {
                    min=dist[j];
                    imin=j;
                }
            }
            set[imin]=1;
            for(j=0;j<n;j++)
            {
                if((set[j]==0) && dist[imin]!=INT_MAX && adj[imin][j]!=0 && ((adj[imin][j]+dist[imin])<(dist[j])))
                    dist[j]=(adj[imin][j]+dist[imin]);
            }
        }
        System.out.println("Source    Destination");
        for(i=0;i<n;i++)
            System.out.println(s+"          "+dist[i]);
    }
}

