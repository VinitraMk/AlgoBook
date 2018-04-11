import java.util.*;
import java.io.*;
import java.lang.*;

class knapsackdp
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int n,W,i,j;
        System.out.print("Enter no of items and capacity of knapsack: ");
        n=sc.nextInt();
        int[] v=new int[n];
        int[] w=new int[n];
        W=sc.nextInt();
        int[][] knapsack=new int[n+1][W+1];
        for(i=0;i<n;i++)
        {
            v[i]=sc.nextInt();
            w[i]=sc.nextInt();
        }
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=W;j++)
            {
                if(i==0 || j==0)
                    knapsack[i][j]=0;
                else if(w[i-1]<=j)
                {
                    if((v[i-1]+knapsack[i-1][j-w[i-1]])>knapsack[i-1][j])
                        knapsack[i][j]=v[i-1]+knapsack[i-1][j-w[i-1]];
                    else
                        knapsack[i][j]=knapsack[i-1][j];
                }
                else
                    knapsack[i][j]=knapsack[i-1][j];
                //System.out.print(knapsack[i][j]+" ");
            }
            //System.out.println();
        }
        System.out.println("Total profit: "+knapsack[n][W]);
    }
}


