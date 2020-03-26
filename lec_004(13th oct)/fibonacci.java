import java.util.Scanner;

public class fibonacci{

    public static void print_pattern_1(int n){

        int a = 0;      
        int b = 1;
        System.out.print(a +" "+ b+" ");

        for(int i=1;i<= n-2;i++){
            int c = a + b;
            System.out.print(c+" ");
            a = b;
            b = c;
        }
    }

    public static void print_pattern_new(int n){

        int a = 0;
        int b = 1;
        int c = a + b;
        System.out.println(a);
        System.out.println(b+ " " + c);

        for(int i=1;i<= n-2;i++){
            for(int j = 1;j<= i+2;j++){
                a = b;
                b = c;
                c = a + b;
                System.out.print(c+" ");
            }
            System.out.println();
        }
    }
    public static Scanner sc = new Scanner(System.in);
    public static void main(String[] args){

        System.out.print("Enter number of elements: ");
            int n = sc.nextInt();

            print_pattern(n);

    }
}