import java.util.Scanner;

public class bin_search_gfg{

    public static void fluc_pt(int []arr,int data){

        int lb = 0;
        int up = arr.length - 1;

        while(lb < up){

            int mid = (lb + up)/2;
            
            if(arr[mid] > arr[lb])
                lb = mid+1;
            else   
                up = mid-1;
        }


        if(data < arr[lb])
            bs(arr, data, 0, lb-1);
        else
            bs(arr, data, lb, arr.length-1);
    }

    public static void bs(int [] arr,int data,int lb,int up){

        while(lb<= up){
            System.out.println("in while");

            int mid = (lb + up)/2;

            if(arr[mid] == data){
                System.out.println("hello"+mid);
                break;
            }
            else if(arr[mid]> data)
                up = mid - 1;
            else
                lb = mid + 1;
        }
        System.out.println("in bs");
    }
    public static void main(String[] args){

        int[] arr = {3,4,5,1,2};
        fluc_pt(arr, 5);
    }
}