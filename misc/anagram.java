import java.util.*;
import java.io.*;
import java.lang.*;
class anagram{
	public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int i,j,k;
        String[] a = new String[n];

        for(i=0;i<n;i++) {
            a[i]=sc.next();
        }

        int c=0;

        HashMap<Integer,Integer> hp = new HashMap<Integer,Integer>();
        for(i=0;i<n;i++) {
            int hs=hash(a[i]);
            //System.out.println(a[i]+" "+hs+" "+hp.get(hs));
            if(hp.containsKey(hs)) 
                hp.put(hs,hp.get(hs)+1);
            else
                hp.put(hs,1);
        }
        for(int in:hp.keySet())
            c+=hp.get(in);
        System.out.println(c);
    }

    public static int hash(String s) {
        int freq[] = new int[26];
        for(int i=0;i<s.length();i++) {
            freq[s.charAt(i)-'a']++;
        }
        int t=1,ret=0;
        for(int i=0;i<26;i++) {
            ret+=(t*freq[i]);
            t=t*1000003;
        }
        return ret;
    }
}

