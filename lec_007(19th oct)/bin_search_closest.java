import java.util.Scanner;

public class bin_search_closest{

    public static int bs(int [] arr,int data){

        int lb = 0;
        int up = arr.length - 1;

        if(data > arr[up])
            return arr[up];
        if(data < arr[lb])
            return arr[lb];
        
        while(lb<= up){

            int mid = (lb + up)/2;

            if(arr[mid] == data)
                return mid;
            else if(arr[mid]> data)
                up = mid - 1;
            else
                lb = mid + 1;
        }
        System.out.println("Element not found");
        return ((data - arr[up] <= arr[lb] - data)? arr[up]:arr[lb]);
    }

    public static void main(String[] args){

        int[] arr = {-2,-1,0,1,2,2,2,2,2,2,2,4,5};

        System.out.println(bs(arr,-8));
    }
}