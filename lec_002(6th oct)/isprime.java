import java.util.Scanner;
public class isprime{
    public static Scanner sc = new Scanner(System.in);

    public static boolean ifprime(int n){

        for(int i = 2; i*i<= n; i++){

            if(n % i == 0)
                return false;
        }

        return true;
  }

  public static void main(String[] args){

    System.out.println("Enter n: ");
    int n = sc.nextInt();

    boolean ans = ifprime(n);
    
    if(ans == true) 
        System.out.println("Prime");
    else
        System.out.println("Not Prime");
    }
}