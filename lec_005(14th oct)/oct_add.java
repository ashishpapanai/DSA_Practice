import java.util.Scanner;

public class oct_add{

    public static void add(int n1,int n2){

        int rem;
        int carry = 0,pow = 1,res = 0;

        while(n1!= 0|| n2!= 0|| carry!= 0){
            
            rem = n1 % 10 + n2 % 10 + carry;

            carry = rem / 8;
            rem %= 8;

            res += pow*rem;

            pow*= 10;
            n1 /= 10;
            n2 /= 10;

        }
        System.out.println(res);
    }
    public static Scanner sc = new Scanner(System.in);
    public static void main(String[] args){

        int n1 = sc.nextInt();
        int n2 = sc.nextInt();

        add(n1,n2);

    }
    
}