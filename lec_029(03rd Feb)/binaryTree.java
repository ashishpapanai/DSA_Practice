public class binaryTree{
    public static class Node{
        int data = 0;
        Node left = null;
        Node right = null;
        public Node(){}
        public Node(int data){
            this.data = data;
        }
        public Node(int data, Node left, Node right){
            this.data = data;
            this.left = left;
            this.right = right;
        }
    }
    public static int idx = 0;
    public static Node create_Tree(int[] arr){
        if(idx == arr.length || arr[idx] == -1){
            idx++;
            return null;
        }
        Node node = new Node(arr[idx]);
        idx++;
        node.left = create_Tree(arr);
        node.right = create_Tree(arr);
        return node; 
    }
    public static void display(Node node){
        if(node == null){
            return;
        }
        System.out.print((node.left != null)?node.left.data:". ");
        System.out.print("-> "+node.data+" <-");
        System.out.println((node.right != null)?node.right.data:" .");
        display(node.left);
        display(node.right);
    }
    public static int maximum = -99999;
    public static int max(Node node){
        if(node == null){
            return maximum;
        }
        if(node.data > maximum){
            maximum = node.left.data;
        } 
        if(node.left != null){
            if(node.left.data > maximum){
                maximum = node.left.data;
            } 
        }
        if(node.right != null){
            if(node.right.data > maximum){
                maximum = node.right.data;
            } 
        }
        max(node.left);
        max(node.right);   
        return maximum;     
    }
    public static int minimum = 99999;
    public static int min(Node node){
        if(node == null){
            return minimum;
        }
        if(node.data < minimum){
            minimum = node.left.data;
        } 
        if(node.left != null){
            if(node.left.data < minimum){
                minimum = node.left.data;
            } 
        }
        if(node.right != null){
            if(node.right.data < minimum){
                minimum = node.right.data;
            } 
        }
        min(node.left);
        min(node.right);   
        return minimum;     
    }
    public static boolean find(Node node, int ele){
        if(node == null){
            return false;
        }
        if(node.data == ele){
            return true;
        } 
        if(node.left != null){
            if(node.left.data == ele){
                return true;
            } 
        }
        if(node.right != null){
            if(node.right.data == ele){
                return true;
            } 
        }
        find(node.left, ele);
        find(node.right, ele);   
        return false;     
    }
    public static int siz = 1;
    public static int size(Node node){
        if(node == null){
            return siz;
        }
        if(node.left != null){
            siz++;
        }
        if(node.right != null){
            siz++;
        }
        size(node.left);
        size(node.right);   
        return siz;     
    }

    public static void solution(){
        int arr[] = {10,20,30,40,-1,-1,50,-1,-1,60,-1,70,-1,-1,80,90,100,120,-1,-1,130,-1,-1,110,-1,-1,140,-1,-1};
        Node node = create_Tree(arr);
        System.out.println(max(node));
        //System.out.println(min(node));
        //display(node);
        //System.out.println(find(node, 150));
        //System.out.println(size(node));
    }
    public static void main(String args[]){
        solution();
    }
}