import java.util.Scanner;
public class ncr{

    public static int fact(int n){

        int ans = 1;
        for(int i = 2;i<= n;i++)
            ans *= i;
        
            return ans;
    }

    public static void ncr(){

        int n = sc.nextInt();
        int r = sc.nextInt();

        int ans = fact(n)/(fact(r) * fact(n-r));

        System.out.println(ans);
    }
    public static Scanner sc = new Scanner(System.in);

    public static void main(String[] args){
        
        int n = sc.nextInt();
        System.out.println(fact(n));

        ncr();     
    }
}