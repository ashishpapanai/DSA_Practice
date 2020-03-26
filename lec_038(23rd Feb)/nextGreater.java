import java.util.*;
public class nextGreater extends stack {
//     public static void approach1() {
//         int arr[] = { 4, 5, 2, 25 };
//         stack st = new stack(arr);
//         boolean bool = false;
//         for (int i = 0; i < st.st.length; i++) {
//             System.out.print(st.st[i] + " -> ");
//             for (int j = i + 1; j < st.st.length; j++) {
//                 if (st.st[i] < st.st[j]) {
//                     System.out.print(st.st[j]);
//                     bool = true;
//                     break;
//                 }
//             }
//             if (i == (st.size() - 1)) {
//                 System.out.print(-1);
//             }
//             if (!bool) {
//                 System.out.print("-1");
//                 bool = false;
//             }
//             System.out.println();
//         }

//     }
    public static void nextGreaterOnRight(int arr[]){
        Stack<Integer> st = new Stack<>();
        for(int i = 0; i < arr.length; i++){
            if(st.size() == 0){
                st.push(arr[i]);
                continue;
            }
            while(st.size() != 0 && st.peek() < arr[i]){
                System.out.println(st.pop() +" -> "+arr[i]);
            }
            st.push(arr[i]);
        }
        while(st.size() != 0){
            System.out.println(st.pop() +" -> "+"X");
        }
    } 
    public static void nextGreaterOnLeft(int arr[]){
        Stack<Integer> st = new Stack<>();
        for(int i = arr.length-1; i >= 0; i--){
            if(st.size() == 0){
                st.push(arr[i]);
                continue;
            }
            while(st.size() != 0 && st.peek() < arr[i]){
                System.out.println(st.pop() +" -> "+arr[i]);
            }
            st.push(arr[i]);
        }
        while(st.size() != 0){
            System.out.println(st.pop() +" -> "+"X");
        }
    }
    public static void nextSmallerOnLeft(int arr[]){
        Stack<Integer> st = new Stack<>();
        for(int i = arr.length-1; i >= 0; i--){
            if(st.size() == 0){
                st.push(arr[i]);
                continue;
            }
            while(st.size() != 0 && st.peek() > arr[i]){
                System.out.println(st.pop() +" -> "+arr[i]);
            }
            st.push(arr[i]);
        }
        while(st.size() != 0){
            System.out.println(st.pop() +" -> "+"X");
        }
    }
    public static void nextSmallerOnRight(int arr[]){
        Stack<Integer> st = new Stack<>();
        for(int i = 0; i < arr.length; i++){
            if(st.size() == 0){
                st.push(arr[i]);
                continue;
            }
            while(st.size() != 0 && st.peek() > arr[i]){
                System.out.println(st.pop() +" -> "+arr[i]);
            }
            st.push(arr[i]);
        }
        while(st.size() != 0){
            System.out.println(st.pop() +" -> "+"X");
        }
    }
    public static int[] asteroidCollision(int[] arr) {
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > 0)
                st.push(arr[i]);
            else {
                while (st.size() != 0 && st.peek() > 0 && st.peek() < -arr[i]) {
                    st.pop();
                }

                if (st.size() != 0 && st.peek() == -arr[i])
                    st.pop();
                else if (st.size() == 0 || st.peek() < 0)
                    st.push(arr[i]);
            }
        }

        int[] ans = new int[st.size()];
        for (int i = ans.length - 1; i >= 0; i--) {
            ans[i] = st.pop();
        }

        return ans;
    }

    public String removeKdigits(String num, int k) {
        char[] arr = num.toCharArray();
        Stack<Character> st = new Stack<>();

        for (int i = 0; i < arr.length; i++) {
            while (st.size() != 0 && st.peek() > arr[i] && k != 0) {
                st.pop();
                k--;
            }

            st.push(arr[i]);
        }

        while (k-- > 0) {
            st.pop();
        }

        StringBuilder sb = new StringBuilder();
        while (st.size() != 0) {
            sb.append(st.pop());
        }

        if (sb.length() != 0 && sb.charAt(sb.length() - 1) == '0') {
            int i = sb.length() - 2;
            for (; i >= 0; i--) {
                if (sb.charAt(i) != '0')
                    break;
            }

            sb = new StringBuilder(sb.substring(0, i + 1));

        }
        sb.reverse();
        String ans = sb.toString();
        return ans.length() != 0 ? ans : "0";
    }
    
    public static void main(String args[]) {
        int arr[] = {9,1,7,3,11,-2,25,20,2,-4};
        nextSmallerOnRight(arr);                
    }
}