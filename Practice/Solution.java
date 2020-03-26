import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Result {

    /*
     * Complete the 'pickingNumbers' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts INTEGER_ARRAY a as parameter.
     */

    public static int pickingNumbers(final List<Integer> a) {
    Collections.sort(a);
    final int ans = 0;
    final ArrayList<Integer> ans2 = new ArrayList<Integer>();   
    for(int i = 0; i < a.size(); i++){
        ans2.add(a.get(i));
        boolean flag = false;
        for(int j = i+1; j < a.size(); j++){
            if((Math.abs(a.get(i)) - Math.abs(a.get(j))) == 1){
                flag = true;
                ans2.add(a.get(i));                                                
            }
        }
        if(flag == false){
            ans2.remove(new Integer(a.get(i)));
        }
    }
    for(int i = 0; i < ans2.size();i++){
        for(int j = i+1; j < ans2.size();j++){
            if(Math.abs(ans2.get(i)- ans2.get(j)) != 1){
                
            }
        }
    }
    // System.out.println(ans2);
    return ans;
    }

}

public class Solution {
    public static void main(final String[] args) throws IOException {
        final BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        final BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        final int n = Integer.parseInt(bufferedReader.readLine().trim());

        final String[] aTemp = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        final List<Integer> a = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            final int aItem = Integer.parseInt(aTemp[i]);
            a.add(aItem);
        }

        final int result = Result.pickingNumbers(a);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
