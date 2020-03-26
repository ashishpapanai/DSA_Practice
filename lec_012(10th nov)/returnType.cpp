#include<iostream>
#include<vector>

using namespace std;

string removeHi(string str){

    if(str.length() == 0)
        return "";

    char ch = str[0];

    if(str.length() > 1 && str.substr(0,2) == "Hi")
        return removeHi(str.substr(2));
    else
        return ch + removeHi(str.substr(1));
    
}

string removeHi_hit(string str){

    if(str.length() == 0)
        return "";

    char ch = str[0];

    if(str.length() > 2 && str.substr(0,3) == "Hit")
        return "Hit" + removeHi_hit(str.substr(3));
    else if(str.length() > 1 && str.substr(0,2) == "Hi")
        return removeHi_hit(str.substr(2));
    else
        return ch + removeHi_hit(str.substr(1));
    
    
}

string rem_dup_idiot(string str){

    if(str.length() == 0)
        return "";

    char ch = str[0];

    if(str.length() > 1 && str[0] == str[1])
        return rem_dup_idiot(str.substr(1));
    else
        return ch + rem_dup_idiot(str.substr(1));
    
}

/*string rem_dup_better(string str,string idx){

    if(idx == str.length()){
        return str(1,str[idx - 1]);
    }

    if(idx != 0 && str[idx - 1] != str[idx])
        return str[idx-1] + rem_dup_better_idiot(str.substr(str,idx + 1))
    else
        return rem_dup_better_idiot(str,idx + 1);
}*/

vector<string> subseq(string str){

    if(str.length() == 0){
        vector<string> base;
        base.push_back(" ");
        return base;
    }

    char ch = str[0];1
    vector<string> myAns;
    vector<string> smallAns = subseq(str.substr(1));
    

    for(string s : smallAns)
        myAns.push_back(ch + s);

    return myAns;
}


vector<string> mazePathSimple(int sr,int sc,int er,int ec){


    if(sr == er && sc == ec){

        vector<string> base;
        base.push_back("");
        return base;
    }

    vector<string>myAns;
    
    if(sc + 1 <= ec){

        vector<string> horizontal = mazePathSimple(sr,sc + 1,er,ec);
        for(string s : horizontal)
            myAns.push_back("h" + s);
    }

    if(sr + 1 <= er){

        vector<string> vertical = mazePathSimple(sr + 1,sc,er,ec);
        for(string s : vertical)
            myAns.push_back("v" + s);
    }
    return myAns;
}

vector<string> mazePath_D(int sr,int sc,int er,int ec){


    if(sr == er && sc == ec){

        vector<string> base;
        base.push_back("");
        return base;
    }

    vector<string>myAns;
    
    if(sc + 1 <= ec){

        vector<string> horizontal = mazePathSimple(sr,sc + 1,er,ec);
        for(string s : horizontal)
            myAns.push_back("h" + s);
    }

    if(sr + 1 <= er){

        vector<string> vertical = mazePathSimple(sr + 1,sc,er,ec);
        for(string s : vertical)
            myAns.push_back("v" + s);
    }

    if(sr + 1 <= er && sc + 1 <= ec ){

        vector<string>diag = mazePath_D(sr + 1,sc + 1,er,ec);
        for(string s : diag)
            myAns.push_back("d" + s);
    }
    return myAns;
}

void mazePath(){

    //vector<string> ans = mazePathSimple(0,0,3,3);
    vector<string>ans = mazePath_D(0,0,4,7);

    for(string s : ans)
        cout<<s<<endl;
}

void basic(){

    //cout<<removeHi_hit(str);
    //cout<<rem_dup_idiot("aaaabbbccddefgga");
    //for(string s : subseq("abcd"))
        cout<<s<<" ";

    mazePath();

}

int main(){

    basic();
    return 0;
}