#include<iostream>
#include<vector>

using namespace std;

string words[] = {"_","+-/","abc","def","ghi","jkl","mno","pqrs","tuv","xyz","*()%","\"#@$"};

vector<string>keypad(string str){

    if(str.length() == 0){
        vector<string>base;
        base.push_back("");
        return base;
    }


    char ch = str[0];
    string word = words[ch - '0'];

    vector<string> oneChar = keypad(str.substr(1));
    vector<string>myAns;

    for(string s : oneChar){
          for(int i = 0;i< word.length();i++)
            myAns.push_back(word[i] + s);
    }

    if(str.length() > 1 && ch != '0'){
        int num = (ch - '0') * 10 + (str[1] - '0');
        if(num < 12){
            vector<string> twoChar = keypad(str.substr(2));

            for(string s : twoChar){
                for(int i = 0;i<words[num].length();i++)
                    myAns.push_back(words[num][i] + s);
            }
        }
    }

    return myAns;

}

vector<string> encoding(string str){

    if(str.length() == 0){
        vector<string>base;
        base.push_back("");
        return base;
    }
    
    char ch = str[0];
    int num = ch - '1';
    char alpha = 'a' + num;

    if(ch == '0')
        return encoding(str.substr(1));

    vector<string> myAns;

    vector<string> firstRes = encoding(str.substr(1));
    for(string s : firstRes)
        myAns.push_back(alpha + s);

    if(str.length() > 1){
        int num = (ch - '0') * 10 + (str[1] - '0');
        if(num <= 26){

            char alpha = 'a' + num - 1;

            vector<string> secondRes = encoding(str.substr(2));

            for(string s : secondRes)
                myAns.push_back(alpha + s);
        }
    }

    return myAns;
}

int main(int args,char** argv){

    int count = 0;
    // for(string s : keypad_num("1011")){
    //     cout<<s<<endl;
    //     count++;
    // }   
    // cout<<endl<<count;

    for(string s : encoding("1124"))
        cout<<s<<" ";

    return 0;
}