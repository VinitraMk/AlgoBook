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

        for(i=0;i<n-1;i++) {
            for(j=i+1;j<n;j++) {
                if(a[i].length()!=a[j].length())
                    continue;
                else {
                    int m=a[i].length();
                    int co[] = new int[26];
                    Arrays.fill(co,0,26,0);
                    int f=0;
                    for(k=0;k<m;k++) {
                        co[a[i].charAt(k)-'a']++;
                        co[a[j].charAt(k)-'a']--;
                    }
                    for(k=0;k<26;k++) {
                        if(co[k]!=0) {
                            f=1;
                            break;
                        }
                    }
                    if(f==0) {
                        System.out.println(a[i]+" and "+a[j]+" are anagrams ");
                        c++;
                    }
                }
            }
        }
        System.out.println(c);
	}
}

