import java.util.*;
import java.io.*;
import java.lang.*;
class Employee {
    String name,post;
    int salary;
    public Employee() {
    }
    public Employee(String name,String post,int salary) {
        this.name=name;
        this.post=post;
        this.salary=salary;
    }
}
class treeNode {
    Employee emp;
    treeNode left,right;
    public treeNode() {
    }
    public treeNode(Employee emp) {
        this.emp=emp;
        this.left=null;
        this.right=null;
    }
    public treeNode addNode(int in,int n,treeNode root,Employee arr[]) {
        if(in<n) {
            root=new treeNode(arr[in]);
            if((2*in)<n && (2*in+1)<n) {
                if(arr[2*in+1].salary <= arr[2*in+2].salary)  {
                    root.left=root.addNode(2*in+1,n,root.left,arr);
                    root.right=root.addNode(2*in+2,n,root.right,arr);
                }
                else {
                    root.left=root.addNode(2*in+2,n,root.left,arr);
                    root.right=root.addNode(2*in+1,n,root.right,arr);
                }
            }
            else {
                root.left=root.addNode(2*in+1,n,root.left,arr);
                root.right=root.addNode(2*in+2,n,root.right,arr);
            }
        }
        return root;
    }
    public void preOrder(treeNode node) {
        if(node!=null) {
            System.out.println(node.emp.name);
            preOrder(node.left);
            preOrder(node.right);
        }
    }

    public void inOrder(treeNode node) {
        if(node!=null) {
            inOrder(node.left);
            System.out.println(node.emp.name);
            inOrder(node.right);
        }
    }

    public void postOrder(treeNode node) {
        if(node!=null) {
            postOrder(node.left);
            postOrder(node.right);
            System.out.println(node.emp.name);
        }
    }
}
class Tree {
	public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int i,j,k;
        Employee arr[] = new Employee[n];
        for(i=0;i<n;i++) {
            String t1,t2;
            int in1;
            t1=sc.next();
            t2=sc.next();
            in1=sc.nextInt();
            arr[i]=new Employee(t1,t2,in1);
        }
        buildTree(arr,n);
	}

    public static void buildTree(Employee arr[],int n) {
        treeNode root = new treeNode();
        root=root.addNode(0,n,root,arr);
        System.out.println("\nInorder\n");
        root.inOrder(root);
        System.out.println("\nPreorder\n");
        root.preOrder(root);
        System.out.println("\nPostorder\n");
        root.postOrder(root);
    }
}
