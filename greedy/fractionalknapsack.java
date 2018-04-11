import java.util.*;
import java.io.*;
import java.lang.*;
class pair
{
    int ma,mb;
    public pair(int a,int b)
    {
        this.ma=a;
        this.mb=b;
    }
    public int geta()
    {
        return ma;
    }
    public int getb()
    {
        return mb;
    }
}

class fractionalknapsack
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int n,i,j,value,weight,capacity,profit=0;
        Float ratio;
        Random r=new Random();
        System.out.print("Enter no of items in available: ");
        n=sc.nextInt();
        capacity=50+r.nextInt(110);
        System.out.print("\nCapacity of knapsack: "+capacity);
        System.out.print("\nvalue-weight pairs are: ");
        System.out.println("\nValue\tWeight\tRatio");
        Map hm=new TreeMap(Collections.reverseOrder());
        for(i=0;i<n;i++)
        {
            value=1+r.nextInt(110);
            weight=1+r.nextInt(110);
            ratio=(float)value/(float)weight;
            pair tp=new pair(value,weight);
            hm.put(ratio,tp);
            System.out.println(value+"\t"+weight+"\t"+ratio);
        }
        Set keys=hm.keySet();
        Iterator it=keys.iterator();
        System.out.println("\nThe selected items are");
        System.out.println("Value\tWeight\tUnit\tRatio");
        while(it.hasNext())
        {
            Float ration=(float)it.next();
            pair p=(pair)hm.get(ration);
            //System.out.println(p.geta()+"\t"+p.getb()+"\t"+ration);
            if(capacity>=(p.getb()))
            {
                capacity-=(p.getb());
                profit+=(p.geta());
                System.out.println(p.geta()+"\t"+p.getb()+"\t"+1+"\t"+ration);
            }
            else if(capacity<(p.getb()))
            {
                profit+=((capacity*p.geta())/(p.getb()));
                System.out.println(p.geta()+"\t"+p.getb()+"\t"+((float)capacity/(float)p.getb())+"\t"+ration);
                capacity=0;
            }
            else if(capacity<=0)
                break;
        }
        System.out.println("Hence the profit is: "+profit);
    }
}


