import java.util.*;
public class heap{
    ArrayList<Integer> arr;
    public heap(){
        arr = new ArrayList<>();
    }
    //_____________API________________
    public void swap(int i, int j){
        int tmp = arr.get(i);
        arr.set(i, arr.get(j));
        arr.set(j, tmp);
    }
    public void push(int n){
        arr.add(n);
        upHeapify(arr.size()-1);
    }
    public void remove(){
        swap(arr.size()-1,0);
        arr.remove(0);
        downHeapify(0);
    }    
    public int top(){
        return arr.get(0);
    }
    public void update(int idx, int data){
        arr.set(idx, data);
        upHeapify(idx);
        downHeapify(idx);        
    }
    // _______________UTILITY _________________
    public void upHeapify(int cidx){
        int pidx = (cidx+1)/2;
        if(pidx > 0 && arr.get(cidx) > arr.get(pidx)){
            swap(pidx, cidx);
            upHeapify(pidx);
        }
    }
    public void downHeapify(int idx){
        int max = idx;
        int cleft = idx*2+1;
        int cright = idx*2+2;
        if(cleft < arr.size() && arr.get(cleft) > arr.get(max)){
            max = cleft;          
        }
        if(cright < arr.size() && arr.get(cright) > arr.get(max)){
            max = cright;          
        }
        if(max != idx){
            swap(max, idx);
        }
    }
}