import java.util.ArrayList;
import java.util.HashMap;

public class test{
    public static void HashmapOperations(String str){
        HashMap<Character, ArrayList<Integer>> map = new HashMap<>();
        
        for(int i = 0; i < str.length(); i++){
            char ch = str.charAt(i);
            if(!map.containsKey(ch)) map.put(ch, new ArrayList<>());
            map.get(ch).add(i);
        }

        for(Character ch: map.keySet()){
            System.out.println(ch + " -> "+ map.get(ch));
        }
    }

    public static void HashmapOperations02() {
        HashMap<String, Integer> map = new HashMap<>();
        map.put("USA", 100);
        map.put("PAK", 70);       
        map.put("NEP", 80);
        map.put("CHINA", 90);
        map.put("India", 1000);
        map.put("SRI", 60);
        for(String ch: map.keySet()){
            System.out.println(ch + " -> "+ map.get(ch));
        }
    }

    public static void HashmapOperations03(String str) {
        HashMap<Character, Integer> map = new HashMap<>();
        for(int i = 0; i < str.length(); i++){
            char ch = str.charAt(i);
            map.put(ch, map.getOrDefault(ch, 0)+1);
        }
        
        for(Character ch: map.keySet()){
            System.out.println(ch + " -> "+ map.get(ch));
        }
    }

    // public static int order(int[] str){
    //     int max = 0; int ctr = 0;
    //     for(int i = 0; i < str.length-1; i++){
    //         if(str[i] -1 == str[i+1]){
    //             ctr++;
    //         }
    //         else{
    //             if(max < ctr){
    //                 max = ctr;
    //             }
    //             ctr = 0;
    //         }            
    //     }
    //     return max;        
    // }

    public static void main(String[] args){
        HashmapOperations("asdfghjkllkjhgfdsaasdfghjkllkjhggfdss");
        System.out.println();
        HashmapOperations02();
        System.out.println();
        HashmapOperations03("qwertyuiopqwertyuiopasdfghjklzxcvbnmgjhhjhjvrtyuiopasdfghjklzxcvbnm");
        System.out.println();
        // int arr[] = {1,2,3,4,565,667,45,556,23,4354,656,5654,99,89,90,91,92,93,94,95,100,28};
        // System.out.println(order(arr));

    }
}