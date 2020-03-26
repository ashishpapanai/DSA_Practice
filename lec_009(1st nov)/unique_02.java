import java.util.Scanner;

public class unique_02{
        public static Scanner sc = new Scanner(System.in);

        public static void unique_forK(int[] arr,int k){

                int[] bits = new int[32];

                for(int ele : arr){

                        for(int i = 0; i< 32; i++){
                                int mask = 1<<i;
                                if((ele & mask) != 0)
                                        bits[i]++;
                        }
                }

                int ans = 0;
                for(int i = 0; i< 32; i++){

                        if(bits[i] % k != 0)
                                ans |= 1<<i;
                }

                System.out.println(ans);
                
        }

        public static void main(String args[]){

                int arr[] = {5,2,3,14,2,3,14,7,5,3,2,14,5};
                unique_forK(arr,3);
        }
}