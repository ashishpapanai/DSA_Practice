import java.util.*;
public class avl{

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

    public static Node BSTCreate(int[] arr, int si, int ei){
        if(si > ei) return null;

        int mid = (si+ei)/2;
        Node node = new Node(arr[mid]);
        node.left = BSTCreate(arr, si, mid-1);
        node.right = BSTCreate(arr, mid+1, ei);
        return node;
    }
    public static void BSTCreate(){
        int arr[] = new int[10];
        for(int i = 0; i < 10; i++){
            arr[i] = (i+1)*10;
        }
        Node root = BSTCreate(arr,0, arr.length-1);
        System.out.println(root);
        System.out.println();

    }

    public static boolean find_01(Node node, int data){
        if(node == null) return false;
        if(node.data == data){
            return true;
        }
        if(data < node.data){
            return find_01(node.left, data);
        }
        else{
            return find_01(node.right, data);
        }
    }

    public static boolean find_02(Node node, int data) {
        while(node != null){
            if(node.data == data){ 
                return true;
            }
            else if(data < node.data){
                node = node.left;
            }
            else{
                node = node.right;
            }
        }        
        return false;
    }

    public static Node addData(Node node, int data){
        if(node == null) return new Node(data);

        if(data < node.data){
            node.left = addData(node.left, data);
        }
        else{
            node.right = addData(node.right, data);
        }
        return node;
    }

    public static int minTree(Node root) {
        if(root == null) return Integer.MAX_VALUE;
        Node rnode = root;
        while(rnode.left != null){
            rnode = rnode.left;
        }        
        return rnode.data;
    }

    public static int maxTree(Node root) {
        if(root == null) return Integer.MIN_VALUE;
        Node rnode = root;
        while(rnode.right != null){
            rnode = rnode.right;
        }        
        return rnode.data;
    }

    public static Node remNode(Node root, int data) {
        if(root == null) return null;
        if(root.data == data){
            if(root.left == null || root.right == null){
                return root.left == null?root.right:root.left; 
            }
            int maxNode = maxTree(root.left);
            root.data = maxNode;
            root.left = remNode(root.left, maxNode);
        }
        else if(data < root.data){
            root.left = remNode(root.left, data);
        }
        else{
            root.right = remNode(root.right, data);
        }
        return root;
    }

    public static void morrisInOrder(Node node){
        Node curr = node;
        while(curr == null){
            Node nextLeft = curr.left;
            if(nextLeft == null){
                System.out.println(curr.data+" ");
                curr = curr.right;
            }
            else{
                
            }

       }
    }

            
    
    public static void solve() {
        // int[] arr = { 10, 20, 30, 40, -1, -1, 50, -1, -1, 60, -1, 70, -1, -1, 80, 90, 100, 120, -1, -1, 130, -1, -1,
        //         110, -1, -1, 140, -1, -1 };

        // Node root = createTree(arr);
        // //LCA_Check(root, 300, 60);
        // KDown01(root, 20, 2);
        // BSTCreate();
        int arr[] = new int[10];
        for(int i = 0; i < 10; i++){
            arr[i] = (i+1)*10;
        }
        Node root = BSTCreate(arr,0, arr.length-1);
        //System.out.println(root);
        System.out.println(remNode(root, 50));
        //System.out.println(find_02(root,60));
    }

    public static void main(String[] args) {
        solve();
    }

}