#include<iostream>
#include<vector>
#include<string>

using namespace std;

int subseq(string str, string ans){
    if(str.length() == 0){
        cout << ans << endl;
        return 1; 
    }
    int count = 0;
    count += subseq(str.substr(1), ans);
    count += subseq(str.substr(1), ans + str[0]);
    return count;  
}
string words[] = {".:;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz", "@$&", "_-%"};
int keyPad(string str, string ans){
    if(str.length() == 0){
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    int idx = str[0] - '0';
    for(int i = 0; i < words[idx].length(); i++){
        count += keyPad(str.substr(1), ans+(words[idx])[i]);
    }
    return count;
}
int keyPad2(string str, string ans){
    if(str.length() == 0){
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    int idx = str[0] - '0';
    string word = (words[idx]);
    for(int i = 0; i < words[idx].length(); i++){
        count += keyPad(str.substr(1), ans+word[i]);
    }
    if(str.length() > 1){
        int idx2 = (idx*10+(str[1] - '0'));
    if(idx2 < 12 && idx2 > 9){
        string word = (words[idx2]);
    for(int i = 0; i < words[idx2].length(); i++){
        count += keyPad(str.substr(2), ans+word[i]);
    }
    }
    }
    return count;
}
int permutations(string str, string ans){
    if(str.length() == 0){
        cout << ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i = 0; i < str.length();i++){
        string strn = str.substr(0,i)+ str.substr(i+1);
        count += permutations(strn, ans+str[i]);
    }
    return count;
}int permutations2a(string str, string ans){
    if(str.length() == 0){
        cout << ans<<endl;
        return 1;
    }
    int count = 0;
    vector<bool> vis(26,false);
    for(int i = 0; i < str.length();i++){
        if(!vis[str[i] - 'a']){
        vis[str[i] - 'a'] = true;       
        string strn = str.substr(0,i)+ str.substr(i+1);
        count += permutations2a(strn, ans+str[i]);
        }
    }
    return count;
}
int permutations2b(string str, string ans){
    if(str.length() == 0){
        cout << ans<<endl;
        return 1;
    }
    int count = 0;
    int arr = 0;
    for(int i = 0; i < str.length();i++){
        int mask = 1 << (str[i] - 'a');
        if((arr&mask) == 0){
        arr |= mask;
        string strn = str.substr(0,i)+ str.substr(i+1);
        count += permutations2b(strn, ans+str[i]);}
    }
    return count;
}


void basicQues(){
    cout << permutations("aab", "");
}
int main(){
    basicQues();
    return 0;    
}