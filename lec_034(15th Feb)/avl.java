import java.util.*;
public class avl{
    public static class Node {

        int data = 0;
        Node left = null;
        Node right = null;
        int height = -1;
        int balanceFact = 0;
        public Node()
         {

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

    public static Node ll(Node node){
        
        Node y = node.left;
        Node yRight = y.right;

        y.right = node;
        node.left = yRight;

        updateHeightBalance(node);
        updateHeightBalance(y);

        return y;
    }

    public static Node rr(Node node){
        
        Node y = node.right;
        Node yLeft = y.left;

        y.left = node;
        node.right= yLeft;

        updateHeightBalance(node);
        updateHeightBalance(y);
        return y;        
    }

    public static Node rotation(Node node){
        updateHeightBalance(node);        
        if(node.balanceFact == 2){ //ll lr
            if(node.left.balanceFact == 1){        //ll;
                return ll(node);
            }
            else{           //lr
                node.left = rr(node.left);
                return ll(node);
            }
        }
        if(node.balanceFact == -2){ //rr rl
            if(node.right.balanceFact == -1){        //rr;
                return rr(node);
            }
            else{           //rl
                node.right = ll(node.right);
                return rr(node);
            }
        }
        return node;
    }

    public static Node addData(Node node, int data){
        if(node == null) 
        return new Node(data);

        if(data < node.data){
            node.left = addData(node.left, data);
        }
        else{
            node.right = addData(node.right, data);
        }
        node = rotation(node);
        return node;
    }
    
    public static void updateHeightBalance(Node node) {
        int lh = -1;
        int rh = -1;
        if(node.left != null){
            lh = node.left.height;
        }
        if(node.right != null){
            rh = node.right.height;
        }
        node.height = Math.max(lh, rh) + 1;
        node.balanceFact = lh-rh;
    }

    public static int maxTree(Node root) {
        if(root == null) return Integer.MIN_VALUE;
        Node rnode = root;
        while(rnode.right != null){
            rnode = rnode.right;
        }        
        return rnode.data;
    }

    static int leftmost = -1;
    static int rightmost = -1;
    public static void width(Node node, int level){
        if(node == null) return;

        leftmost = Math.min(leftmost, level);
        rightmost = Math.max(rightmost, level);

        width(node.left, level-1);
        width(node.right, level+1);
    }

    public static void VerticalOder(Node node) {
        LinkedList<Node> que1 = new LinkedList<>();
        LinkedList<Integer> que2 = new LinkedList<>();

        width(node, 0);
        ArrayList<Integer>[] list = new ArrayList[rightmost - leftmost+1];
        int[] sumList = new int[rightmost - leftmost];

        que1.addLast(node);
        que2.addLast(-leftmost);

        while (que1.size() != 0) {
            int size = que1.size();
            while (size-- > 0) {
                Node rn = que1.removeFirst();
                int rd = que2.removeFirst();
                System.out.println(rd);
                list[rd]=new ArrayList<>();
                list[rd].add(rn.data);
                sumList[rd] += rn.data;

                if (node.left != null) {
                    que1.addLast(rn.left);
                    que2.addLast(rd - 1);
                }

                if (node.right != null) {
                    que1.addLast(rn.right);
                    que2.addLast(rd + 1);
                }
            }
        }

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
        root = rotation(root);
        return root;
    }
    public static void main(String[] args) {
        Node node = null;
        for(int i = 1; i <= 20; i++){
            node = addData(node, i*10);
        }     
        System.out.println(node);
        VerticalOder(node);
        System.out.println(rightmost);
        System.out.println(leftmost);
        
    }     
}