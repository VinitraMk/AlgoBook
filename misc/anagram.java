import java.util.*;
import java.io.*;
import java.lang.*;
class anagram{
	public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int i,j,k;
        String[] a = new String[n];
        int mat[][] = new int[n][26];
        for(i=0;i<n;i++) {
            for(j=0;j<26;j++)
                mat[i][j]=0;
        }

        for(i=0;i<n;i++)
            a[i]=sc.next();
        for(i=0;i<n;i++) {
            for(j=0;j<a[i].length();j++) 
                mat[i][a[i].charAt(j)-'a']++;
        }

        int c=0;
        Arrays.sort(a,0,n);
        int dp[] = new int[n];
        Arrays.fill(dp,0,n,0);

        for(i=1;i<n;i++) {
            if(a[i].length()!=a[i-1].length())
                dp[i]=0;
            else {
                int co[]=new int[26];
                Arrays.fill(co,0,26,0);
                int m=a[i].length();
                int f=0;
                for(j=0;j<m;j++) {
                    co[a[i-1].charAt(j)-'a']++;
                    co[a[i].charAt(j)-'a']--;
                }
                for(j=0;j<26;j++) {
                    if(co[j]!=0) {
                        f=1;
                        break;
                    }
                }
                if(f==0) {
                    System.out.println(a[i]+" and "+a[i-1]+" are anagrams.");
                    dp[i]=dp[i-1]+1;
                }
            }
        }
	}
}

