import java.util.*;

class Main
{
    static int board[][] = new int[50][50];
    public static void main(String[] args)
    {
        System.out.println("ENTER THE ORDER OF MATRIX: ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ans(n);
    }
    public static void ans(int n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                board[i][j]=0;
            }
        }
        sol(board,0,n);
        for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)   
                {
                    if(board[i][j]==1)   System.out.print(" Q ");
                    else System.out.print(" - ");
                }
                System.out.println();
            }
    }
    public static boolean sol(int board[][],int col,int n)
    {
        if(col>=n) 
        {
            return true;
        }
        for(int i=0;i<n;i++)
        {
            
            if(safe(board,i,col,n)==true)
            {
                board[i][col]=1;
                if(sol(board,col+1,n)==true) return true;
                board[i][col]=0;
                
            }
            
        }
        return false;
    }
    
    public static boolean safe(int board[][],int row,int col,int n)
    {
        
        int i,j;
        
        for(i=0;i<col;i++) if(board[row][i]==1)  return false;
        for (i=row, j=col; i>=0 && j>=0; i--, j--)     if (board[i][j] == 1)    return false;
        for (i=row, j=col; j>=0 && i<n; i++, j--)      if (board[i][j] == 1)    return false;
        return true;
    }
    
}
