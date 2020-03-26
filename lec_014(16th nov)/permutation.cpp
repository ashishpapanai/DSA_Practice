#include<iostream>
#include<vector>

using namespace std;

vector<string> permutation(string str){

    if(str.size() == 0){
        vector<string> base;
        base.push_back("");
        return base;
    }

    char ch = str[0];
    vector<string> smallAns = permutation(str.substr(1));
    vector<string> myAns;

    for(string s : smallAns){
        for(int i = 0;i<= s.length();i++){
            string st = s.substr(0,i) + ch + s.substr(i);
            myAns.push_back(st);
        }       
    }
    return myAns;
}

int main(){

    for(string s : permutation("abc"))
        cout<<s<<endl;

    string str = "abcd";

    return 0;
}