/* package codechef; // don't place package name! */
import java.math.*;
import java.util.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t > 0){
			t--;
			int n = sc.nextInt();
			System.out.println(factorial(n));
		}		
	}
    static BigInteger factorial(int N) 
    { 
        BigInteger f = new BigInteger("1");
        for (int i = 2; i <= N; i++) 
            f = f.multiply(BigInteger.valueOf(i)); 
        return f; 
    } 
}
