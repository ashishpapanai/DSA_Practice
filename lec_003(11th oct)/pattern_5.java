import java.util.Scanner;

public class pattern_5{

    public static Scanner sc = new Scanner(System.in);

    public static void number_diamond(int rows){

        int nsp = rows/2;
        int nst = 1;

        for(int i = 1;i<= rows;i++){
            
            int val = i;
            if(i>= rows/2){
                val = rows-i+1;
            }
            for(int csp = 1;csp<= nsp;csp++)
                System.out.print(" ");

            for(int cst = 1;cst<= nst;cst++){
                System.out.print(val);

                if(cst<= nst/2)
                    val++;
                else
                    val--;
            }
            
            if(i<= rows/2){
                
                nst = nst + 2;
                nsp--;
            }
            else{
                nst = nst - 2;
                nsp++;
            }
            System.out.println();
        }
    }

    public static void main(String[] args){
       
        System.out.println("Enter the number of rows: ");
        int rows = sc.nextInt();

        number_diamond(rows);
    }
}