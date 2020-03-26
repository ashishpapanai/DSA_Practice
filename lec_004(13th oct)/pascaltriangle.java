import java.util.Scanner;

public class pascaltriangle{

    public static void print_pattern(int rows){

        for(int i = 1;i<= rows;i++){

            int val = 1;

            for(int cst = 1;cst<= i;cst++){
                System.out.print(val +" ");
                val = val* ((i-1)-(cst-1))/(cst);
            }
            System.out.println();
        }
    }
        public static Scanner sc = new Scanner(System.in);
        public static void main(String[] args){

            System.out.print("Enter number of rows: ");
            int rows = sc.nextInt();

            print_pattern(rows);

        }

}