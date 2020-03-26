import java.util.*;
// import java.lang.*;

class Main
{
    public static Scanner sc = new Scanner(System.in);
    public static ArrayList<Integer> ans = new ArrayList<Integer>();
	public static void main (String[] args) throws java.lang.Exception
	{
		int n = sc.nextInt();
		for(int i = 0; i < n; i++){
			int a = sc.nextInt();
			int b = sc.nextInt();
			primeGen(a,b);
        }
        print();
	}
	public static void primeGen(int a, int b){
		int ctr = 0;
		for(int i = a; i <= b; i++){
			for(int j = 1; j <= i; j++){
				if(i%j == 0){
					ctr++;
				}
			}
			if(ctr <= 2 && i!= 1){
				ans.add(i);
			}
        }
        ans.add(0);
    }
    public static void print(){
        for(int i = 0; i < ans.size(); i++){
            if(ans.get(i) != 0){
            System.out.println(ans.get(i));
            }
            else{
                System.out.println();
            }
        }
    }
}
