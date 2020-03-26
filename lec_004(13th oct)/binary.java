import java.util.Scanner;
public class binary{
    public static void DtoB(int n){
        
        int pow = 1;
        int res = 0;
        int rem;
        while(n!= 0){

            rem = n % 2;
            n = n/2;
            
            res += pow*rem;
            pow *= 10;
        }
        System.out.print("Binary: " + res);
        System.out.println();
        BtoD(res);
    }

    public static void BtoD(int n){
        
        int pow = 1;
        int res = 0;
        int rem;
        while(n!= 0){

            rem = n % 10;
            n = n/10;
            
            res += pow*rem;
            pow *= 2;
        }
        System.out.print("Decimal: " + res);

        
    }
    public static Scanner sc = new Scanner(System.in);
    public static void main(String[] args){

        System.out.println("Enter the number: ");
        int n = sc.nextInt();

        DtoB(n);
    }
}