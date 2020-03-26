#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Node
{
    public:
    int data = 0;
    vector<Node *> childs;
    Node(){}
    Node(int data){
        this->data = data;
    }
};

Node* createTree(vector<int> &arr){
    stack<Node *> st;
    for(int i = 0; i < arr.size() -1; i++){
        if(arr[i] != -1){
            Node *node = new Node(arr[i]);
            st.push(node);
        }
        else{
            Node* node = st.top();
            st.pop();
            st.top()->childs.push_back(node);
        }
    }     
    return st.top();
}

void display(Node* node){
    cout<<node->data<<" -> ";
    for(Node* child: node->childs){
        cout<< child->data<<", ";
    }
    cout<<endl;
    for (Node* child: node->childs)
    {
        display(child);
    }
}     

int height(Node* node){
    int height2 = 1;
    for(Node* child: node->childs){
        height2 = max(height2,height(child));
    }
    return height2+1;
}

int size(Node* node){
    int sz = 0;
    for(Node* child: node->childs){
        sz+= size(child);
    }
    return sz+1;
}

bool find(Node* node, int data){
    if (node->data == data)
    {
        return true;
    }
    
    bool res = false;
    for(Node* child: node->childs){
        res = res||find(child, data);
    }
    return res;
}

Node* linearise(Node* node){
    if(node->childs.size() == 0) return node;

    Node* myTail = linearise(node->childs.back());
    for(int i = node->childs.size() -2; i >=0; i--){
        Node* tail = linearise(node->childs[i]);

        tail -> childs.push_back(node->childs.back());
        node->childs.pop_back();
    }
    return myTail;
}

bool isSymmetric(Node* node1, Node* node2){
    if(node1->childs.size() != node2->childs.size()) return false;

    for(int i = 0, j = node2->childs.size()-1; i<=j;i++,j--){
        Node* child1 = node1->childs[i];
        Node* child2 = node2->childs[j];

        if (!isSymmetric(child1, child2))
        {
            return false;
        }
    }
    return true;
}

bool isMirror(Node* node1, Node* node2){
    if(node1->childs.size() != node2->childs.size() || node1->childs.data() != node2->childs.data()) return false;

    for(int i = 0, j = node2->childs.size()-1; i<=j;i++,j--){
        Node* child1 = node1->childs[i];
        Node* child2 = node2->childs[j];
        if (! isMirror(child1, child2))
        {
            return false;
        }
    }

    return true;
}

void spiralPrint(Node* node){
    stack<int> st1;
    stack<int> st2;
    for(int i = 0; i < node->childs.size(); i++){

        if(st1.size() == 0){
            swap(st1,st2);
            cout<< endl;
        }
        if(node->childs[i]->childs.size == 0){
            cout << st1.top()+" ";
            st1.pop();
        }
        if(i%2 == 0){
            
        }
    }
}

void solutions(){
    vector<int> arr {10,20,50,-1,60,-1,-1,30,70,-1,80,100, -1, 110, -1,-1,90, -1,-1,40, -1,-1};
    Node* node = createTree(arr);
    display(node);
    // cout<< height(node)<<endl;
    // cout<< size(node)<<endl;
    // cout << find(node, 1000)<<endl;
    cout<< endl;
    Node* tail = linearise(node);
    display(node);
    cout<< endl;
    cout<<isSymmetric(node,node);

}

int main(){
    solutions();
}