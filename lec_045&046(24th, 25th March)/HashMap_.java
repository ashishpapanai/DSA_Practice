import java.util.*;

public class HashMap_<K , V>{
    
    public class Node{
        K key;
        V value;

        public Node(final K key, final V value){
            this.key = key;
            this.value = value;
        }
        
        @Override
        public String toString(){
            final String str = this.key + " -> "+ this.value;
            return str;
        }
    }

    private int size = 0;
    private LinkedList<Node> [] buckets = new LinkedList[10];
    
    public HashMap_(){
        reassign();                
    }
    private void reassign(){
        for(int i = 0; i < buckets.length; i++){
            buckets[i] = new LinkedList<>();
        }
        this.size = 0;
    }
    public int size(){
        return this.size;
    }

    @Override
    public String toString(){
        final StringBuilder sb= new StringBuilder();
        sb.append("{");
       
        for(int i=0;i<buckets.length;i++){
            if(buckets[i].size()>0){
                
                final LinkedList<Node> group=buckets[i];
                int size=group.size();

                while(size-->0){
                    final Node tempNode=group.getFirst();
                    sb.append(tempNode + ",");
                    group.addLast(group.removeFirst());
                }

            }
        }
        sb.deleteCharAt(sb.length()-1);
        sb.append("}");
        return sb.toString();
    }

    public void put(final K key, final V value){
        final int code = MyGroup(key);   
        final LinkedList<Node> group = buckets[code];   
        final Node rn = foundInGroup(group, key);

        if(group == null){
            buckets[code] = new LinkedList<>();
        }        

        if(rn != null){
            rn.value = value;
        }
        else{
            final Node n = new Node(key, value);
            group.addLast(n);
            this.size++;

            final double lambda = group.size()*1.0/buckets.length;
            if(lambda > 0.3){
                System.out.println("REHASH : "+group.size());
                rehash();
            }

        }
    }

    public ArrayList<V> keySet(){

        final ArrayList<V> ans = new ArrayList<>();
        for(int i =0; i < buckets.length; i++){
            final LinkedList<Node> group = (buckets[i]);
            int size = group.size();
            while(size-- > 0){
                final Node tempNode = group.getFirst();
                ans.add(tempNode.value);
                ans.add(group.removeLast().value);
            }
        }
        return ans;        
    }

    public V getOrDefault(final K key, final V defaultVal){
        final int code = MyGroup(key);
        final LinkedList<Node> group = buckets[code];
        final Node rn = foundInGroup(group, key);
        if(rn != null) return rn.value;
        else return defaultVal;
    }

    private V get(final K key){
        final int code = MyGroup(key);   
        final LinkedList<Node> group = buckets[code];   
        final Node rn = foundInGroup(group, key);

        return rn == null ? null : rn.value;

    }

    private Node foundInGroup(final LinkedList<Node> group, final K key){
        if(group == null) return null;
        Node rn = null;
        int size = group.size();
        while(size-- > 0 ){
            final Node temNode = group.getFirst();
            if(temNode.key == key){
                rn = temNode;
                break;
            }
            group.addLast(group.removeFirst());
        }
        return rn;
    }

    public boolean containsKey(final K key){
        final int code = MyGroup(key);
        final LinkedList<Node> group = buckets[code];
        final Node rn = foundInGroup(group, key);

        if(rn != null) return true;
        else return false;

    }

    public Node remove(final K key){
        final int code = MyGroup(key);
        final LinkedList<Node> group = buckets[code];
        final Node rn = foundInGroup(group, key);
        if(rn != null){
            this.size--;
            return group.removeFirst();
        }
        else{
            System.out.println("ELEMENT NOT FOUND: -1");
            return null;
        }
        
    }

    public void rehash(){
        final LinkedList<Node>[] oldBuckets = buckets;
        buckets = new LinkedList[oldBuckets.length*2];
        reassign();

        for (int i = 0; i < oldBuckets.length; i++) {
            if(oldBuckets[i].size() > 0){
                final LinkedList<Node> group = oldBuckets[i];
                int size = group.size();

                while(size-- > 0){
                    final Node tnode = group.removeFirst();
                    put(tnode.key, tnode.value);
                }
            }         
            
        }
    }
    

    public int MyGroup(final K key){
        return MyHashCode(key)%buckets.length;
    }

    public int MyHashCode(final K key){
        final Integer val = key.hashCode();
        return Math.abs(val);
    }

}