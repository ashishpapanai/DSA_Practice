import java.util.*;
public class diameter{

    public static class Node {

        int data = 0;
        Node left = null;
        Node right = null;

        public Node() {

        }

        public Node(int data) {
            this.data = data;
        }

        public Node(int data, Node left, Node right) {
            this.data = data;
            this.left = left;
            this.right = right;
        }

        @Override
        public String toString() {

            String str = "";
            str += ((left != null ? left.data : "."));
            str += (" -> " + data + " <- ");
            str += ((right != null ? right.data : "."));
            str += "\n";

            if (left != null)
                str += left.toString();
            if (right != null)
                str += right.toString();

            return str;
        }

    }

    static int idx = 0;

    public static Node createTree(int[] arr) {
        if (idx == arr.length || arr[idx] == -1) {
            idx++;
            return null;
        }

        Node node = new Node(arr[idx]);
        idx++;

        node.left = createTree(arr);
        node.right = createTree(arr);

        return node;
    }

    public static int height(Node node) {
        if (node == null)
            return -1;
        return Math.max(height(node.left), height(node.right)) + 1;
    }


    public static void display(Node node) {
        if (node == null)
            return;

        System.out.print((node.left != null ? node.left.data : "."));
        System.out.print(" -> " + node.data + " <- ");
        System.out.println((node.right != null ? node.right.data : "."));

        display(node.left); // display(2*idx+1);
        display(node.right); // display(2*idx+2);

    }
    
    public static ArrayList<Node> rootToNodePath(Node node, int data) {
        ArrayList<Node> ans = new ArrayList<Node>();
        if (node == null)
            return null;
        if (node.data == data)
            return ans;
        ans.add(node.left);
        ans.add(node.right);     
        return ans;
    }

    public static void LCA_Check(Node node, int n1, int n2) {
        ArrayList<Node> pathE1 = new ArrayList<Node>();
        ArrayList<Node> pathE2 = new ArrayList<Node>();
        pathE1 = rootToNodePath(node, n1);
        pathE2 = rootToNodePath(node, n2); 
        int l1 = pathE1.size() - 1;
        int l2 = pathE2.size() - 1;
        int ans = -1;
        while(l1 >= 0 && l2 >= 0){
            if(pathE1.get(l1).data != pathE2.get(l2).data)
            {
                break;
            }
                ans = pathE1.get(l1).data;                   
                l1--;
                l2--;
        }
        System.err.println(ans);
    }

    //__________________TRY____________________
    public static ArrayList<Integer> Kdistance(Node node, int k){
        int counter = 0;
        ArrayList<Integer> ans = new ArrayList<Integer>();
        if (node == null)
            return null;
        if (counter == k){
            counter = 0;
            ans.add(node.data);   
        } 
        counter++;
        Kdistance(node.left, k);
        Kdistance(node.right, k);
        return ans;
    }
    public static void Kdistance(int k, Node node){
        ArrayList<Integer> ans = Kdistance(node, k);
        System.out.println(ans);
    }
    public static ArrayList<Node> rootToNodePath2(Node node, int data) {
        if (node == null)
            return null;
        if (node.data == data){
            ArrayList<Node> base = new ArrayList<>();
            return base;
        }
        ArrayList<Node> left = new ArrayList<>();
        if(left.size() != 0){
            left.add(node);
            return left;
        }
        ArrayList<Node> right = new ArrayList<>();
        if(right.size() != 0){
            right.add(node);
            return right;
        }               
        return new ArrayList<Node>();
    }
    public static void KDown(Node node, Node pnode, int level) {
        if(node == null || node == pnode){
            return;
        }
        if(level == 0){
            System.out.println(node.data+" ");
        }
        KDown(node.left, pnode, level-1);
        KDown(node.right, pnode, level-1);
    }
    public static void KDown01(Node node,int target ,int k) {
        Node pnode = null;
        ArrayList<Node> ans = rootToNodePath2(node, target);
        for(int i = 0; i < ans.size(); i++){
            KDown(node, pnode, k-i);
            pnode = (ans.get(i));
        }                     
    }                                
//______________________ D  I  A  M  E  T  E  R ________________________

    public static int diameter_01(Node node){
        if(node == null) return 0;

        int ld = diameter_01(node.left);
        int rd = diameter_01(node.right);
        int rh = height(node.right);
        int lh = height(node.left);

        return Math.max(Math.max(ld, rd), lh+rh+2);
    }

    public static int[] diameter_02(Node node){
        if(node == null) {
            int base[] = {0,-1};
            return base;
        }

        int[] ld = new int[2];
        ld = diameter_02(node.left);
        int[] rd = new int[2];
        rd = diameter_02(node.right);;
        int myAns[] = new int[2];
        myAns[0] = Math.max(Math.max(ld[0], rd[0]), ld[1]+rd[1]+2);
        myAns[1] = Math.max(ld[1], rd[1]) +1;
        return myAns;
    }

    public static boolean sum2(Node node,int target){
        if(node.left == null && node.right == null){
             if((target - node.data) == 0){
                 return true;
             }
            else
                return false;
        }
        boolean res = false;
        if(target-node.data >= 0){
            if(node.left != null){
                res = res|| sum2(node.left, target - node.data);
            }
            if(node.right != null){
                res = res || sum2(node.right, target - node.data);
            }
        }
        return res;
    }

    static int maxSum = Integer.MIN_VALUE;

    public static int leafToLeafSum(Node node){
        if(node == null) return Integer.MIN_VALUE;
        
        if(node.left != null && node.right != null){
            return node.data;
        }
        int lmaxSum = leafToLeafSum(node.left);
        int rmaxSum = leafToLeafSum(node.right);

        if(node.left != null && node.right != null){
            maxSum = Math.max(maxSum, lmaxSum + rmaxSum + node.data);
        }
        return Math.max(lmaxSum, rmaxSum) + node.data;
    }

    public static void solve() {
        int[] arr = { 10, 20, 30, 40, -1, -1, 50, -1, -1, 60, -1, 70, -1, -1, 80, 90, 100, 120, -1, -1, 130, -1, -1,
                110, -1, -1, 140, -1, -1 };

        Node root = createTree(arr);
        //LCA_Check(root, 300, 60);
        // KDown01(root, 20, 2);
        //int ans[] = diameter_02(root);
        //System.out.println(sum2(root, 340));
        leafToLeafSum(root);
        System.out.println(maxSum);
    }

    public static void main(String[] args) {
        solve();
    }

}