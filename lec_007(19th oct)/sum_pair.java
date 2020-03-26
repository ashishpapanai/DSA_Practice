public class sum_pair{

    public static sum(int[] arr,int target){

     int lb = 0;
     int up = arr.length - 1;
     
     while(i<= j){

        int sum = arr[lb] + arr[up];
        if(sum == target){

            System.out.println(arr[lb]+" , "+arr[up]);
            lb++;
            up--;
        }
        else if(sum> target)
            up--;
        else 
            lb++;
        }

    }

    public static void main(String[] args){

        
    }
}