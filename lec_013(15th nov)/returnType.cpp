#include<iostream>
#include<vector>

using namespace std;

vector<string> mazePath_D(int sr,int sc,int er,int ec){


    if(sr == er && sc == ec){

        vector<string> base;
        base.push_back("");
        return base;
    }

    vector<string>myAns;
    
    if(sc + 1 <= ec){

        vector<string> horizontal = mazePath_D(sr,sc + 1,er,ec);
        for(string s : horizontal)
            myAns.push_back("h" + s);
    }

    if(sr + 1 <= er){

        vector<string> vertical = mazePath_D(sr + 1,sc,er,ec);
        for(string s : vertical)
            myAns.push_back("v" + s);
    }

    if(sr + 1 <= er && sc + 1 <= ec){

        vector<string>diag = mazePath_D(sr + 1,sc + 1,er,ec);
        for(string s : diag)
            myAns.push_back("d" + s);
    }
    return myAns;
}

int mazePath_D_H(int sr,int sc,int er,int ec){

    if(sc == ec && sr == er)
        return 0;


    int hor = 0,ver = 0,diag = 0;
    
    if(sc + 1 <= ec)    
        hor = mazePath_D_H(sr,sc + 1,er,ec);

    if(sr + 1 <= er)
        ver = mazePath_D_H(sr + 1,sc,er,ec);

    if(sr + 1 <= er && sc + 1 <= ec)
        diag = mazePath_D_H(sr + 1,sc + 1,er,ec);    

    return (max(hor,max(ver,diag)) + 1);
}

pair<int,string> mazePath_D_H_P(int sr,int sc,int er,int ec){

    pair<int,string> hor,ver,diag;

    if(sc + 1 <= ec){

        hor = mazePath_D_H_P(sr,sc + 1,er,ec);
        for(char s : hor.second)
            myAns.push_back("h" + s);
    }

    if(sr + 1 <= er){

        ver = mazePath_D_H_P(sr + 1 ,sc,er,ec);
        for(char s : ver.second)
            myAns.push_back("v" + s);
    }

    if(sr + 1 <= er && sc + 1)
        
    
} 

void mazePath(){

    //vector<string> ans = mazePathSimple(0,0,3,3);
    //vector<string>ans = mazePath_D(0,0,4,7);

    //for(string s : ans)
    //    cout<<s<<endl;

    //cout<<mazePath_D_H(0,0,4,7);

    mazePath_D_H_P(0,0,2,2);
}

void basic(){

    //cout<<removeHi_hit(str);
    //cout<<rem_dup_idiot("aaaabbbccddefgga");
    //for(string s : subseq("abcd"))
    //   cout<<s<<" ";

    mazePath();

}

int main(){

    basic();
    return 0;
}