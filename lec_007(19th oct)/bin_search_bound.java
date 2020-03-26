import java.util.Scanner;

public class bin_search_bound{

    public static int bs(int [] arr,int data){

        int lb = 0;
        int up = arr.length - 1;
        
        while(lb<= up){

            int mid = (lb + up)/2;

            if(arr[mid] == data){
                
                if(mid - 1 > 0 && arr[mid] == arr[mid - 1])
                    up = mid - 1;
                else    
                    return mid;

            }
            else if(arr[mid]> data)
                up = mid - 1;
            else
                lb = mid + 1;
        }
        System.out.println("Element not found");
        return -1;
    }

    public static void main(String[] args){

        int[] arr = {-2,-1,0,1,2,2,2,2,2,2,2,3,3,3,3,3,4,4,4,4,5,5,5,5,6,7};

        System.out.println(bs(arr, 3));
    }
}