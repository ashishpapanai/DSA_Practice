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
        height2 += max(height2,height(child));
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

void solutions(){
    vector<int> arr {10,20,50,-1,60,-1,-1,30,70,-1,80,100, -1, 110, -1,-1,90, -1,-1,40, -1,-1};
    Node* node = createTree(arr);
    display(node);
    cout<< height(node)<<endl;
    cout<< size(node)<<endl;
    cout << find(node, 100)<<endl;
}

int main(){
    solutions();
}