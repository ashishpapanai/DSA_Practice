import java.util.Scanner;
public class array{
    public static void arr_input(int[] a){

        for(int i = 0;i< a.length;i++){
            System.out.print("a["+ i+ "]= ");
            a[i] = sc.nextInt();
            System.out.println();
        }
    }

    public static void arr_output(int[] a){

        for(int i = 0;i< a.length;i++){
            System.out.print("a["+ i+ "]= "+ a[i]);
            System.out.println();
        }
    }
    public static Scanner sc = new Scanner(System.in);
    public static void main(String[] args){

        System.out.print("Enter the size of array: ");
        int n = sc.nextInt();
        int[] a = new int[n];
        
        arr_input(a);
        arr_output(a);
    }
}