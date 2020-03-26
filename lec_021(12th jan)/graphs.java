import java.util.*;
public class graphs{
    public static class edge{
    int v = 0; int w = 0;
    public edge(int v, int w){
        this.v = v;
        this.w = w;                
        }
    }
    public static ArrayList<ArrayList <edge>> graph= new ArrayList<>();
    public static void main(String[] args){
        ConstructGraph();
        removeVtx(3);
        display();
        
    }
    public static void ConstructGraph(){
        int n = 7;
        for(int i = 0; i < n; i++){
            graph.add(new ArrayList<>());
        }
        addEdge(0, 1, 10); 
        addEdge(0, 3, 10); 
        addEdge(1, 2, 10); 
        addEdge(2, 3, 40);    
        addEdge(3, 4, 2); 
        addEdge(4, 5, 2); 
        addEdge(4, 6, 3); 
        addEdge(5, 6, 8);  

        // display();
    }
    public static void addEdge(int v, int u, int w){
    if(u < 0 || v < 0 || u >= graph.size()|| v > graph.size()){
            return;       
        }
        graph.get(u).add(new edge(v, w));
        graph.get(v).add(new edge(u, w));
    }
    public static void display(){
        for(int i = 0; i < graph.size(); i++){
            System.out.print(i+" -> ");                                        
            for(edge e:graph.get(i)){
                System.out.print(" ("+e.v+", "+e.w+") ");
            }
            System.out.println();
        }
    }
    public static void removeEdge(int u, int v) {
        int i = 0;
        while (i < graph.get(u).size()) {
            edge e = graph.get(u).get(i);
            if (e.v == v) {
                break;
            }
            i++;
        }

        int j = 0;
        while (j < graph.get(v).size()) {
            edge e = graph.get(v).get(j);
            if (e.v == u) {
                break;
            }
            j++;
        }

        graph.get(u).remove(i);
        graph.get(v).remove(j);
    }

    public static void removeVtx(int u){
        ArrayList<edge> list=graph.get(u);
        while(list.size()!=0){
            edge e=list.get(list.size()-1);
            removeEdge(u,e.v);
        }

    }
}