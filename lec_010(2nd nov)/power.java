public class power{

    public static void main(String[] args){

        System.out.println(pow_better(2,10));

    }

    public static int cal_pow(int a,int b){

        if(b == 1)
            return a;

        int ans = cal_pow(a,b-1);
        return ans*a;
    }

    public static int pow_better(int a,int b){

        if(b == 1)
            return a;

        int ans = pow_better(a,b/2);
        ans *= ans;

        return ((b % 2)!= 0)?ans*a : ans; 
    }
}