#include<iostream>
#include<vector>
#include<string>

using namespace std;
int infiniteCoinsPerm(vector<int> arr, int tar, string ans){
    if(tar == 0){
        cout<< ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i = 0; i < arr.size(); i++){
        if(tar - arr[i] >= 0){
        count+= infiniteCoinsPerm(arr, tar - arr[i], ans + to_string(arr[i]));
        }
    }  
    return count;
}
int infiniteCoinsComb(vector<int> &arr, int tar, int idx, string ans){
    if(tar == 0){
        cout<< ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i = idx; i < arr.size(); i++){
        if(tar - arr[i] >= 0){
            count += infiniteCoinsComb(arr, tar - arr[i],i, ans + to_string(arr[i]));
        }
    }  
    return count;
}
int CoinsCombWithoutRep(vector<int> &arr, int tar, int idx, string ans){
    if(tar == 0){
        cout<< ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i = idx; i < arr.size(); i++){
        if(tar - arr[i] >= 0){
            count += CoinsCombWithoutRep(arr, tar - arr[i],i+1, ans + to_string(arr[i]));
        }
    }  
    return count;
}
int CoinsPermWithoutRep(vector<int> &arr,vector<bool> &vis, int tar, string ans){
    if(tar == 0){
        cout<< ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i = 0; i < arr.size(); i++){
        if(!vis[i] && tar - arr[i] >= 0){
            vis[i] = true;
            count += CoinsPermWithoutRep(arr, vis,tar - arr[i], ans + to_string(arr[i]));
            vis[i] = false;
        }
    }
    return count;
}
int SubseqInfiniteCoinsPerm(vector<int> arr, int tar,int idx, string ans){
    if(tar == 0 || idx == arr.size()){

        if(tar == 0){
            cout<< ans<<endl;
            return 1;
        }else{
        return 0;}
    }
    int count = 0;
    if((tar - arr[idx]) >= 0){
    count+= SubseqInfiniteCoinsPerm(arr, tar - arr[idx],idx, ans + to_string(arr[idx])); 
    } 
    count+= SubseqInfiniteCoinsPerm(arr, tar,idx +1 ,ans);
    return count;
}
int SubseqInfiniteCoinsComb(vector<int> arr, int tar,int idx, string ans){
    if(tar == 0 || idx == arr.size()){

        if(tar == 0){
            cout<< ans<<endl;
            return 1;
        }else{
        return 0;}
    }
    int count = 0;
    if((tar - arr[idx]) >= 0){
    count+= SubseqInfiniteCoinsComb(arr, tar - arr[idx],idx+1, ans + to_string(arr[idx])); 
    } 
    count+= SubseqInfiniteCoinsComb(arr, tar,idx +1 ,ans);
    return count;
}
int SubseqSingleCoinsPerm(vector<int> &arr,vector<bool> &vis, int tar,int idx, string ans){
    if(tar == 0 || idx == arr.size()){

        if(tar == 0){
            cout<< ans<<endl;
            return 1;
        }else{
        return 0;}
    }
    int count = 0;
    if((tar - arr[idx]) >= 0 && !vis[idx]){
        vis[idx] = true;
    count+= SubseqSingleCoinsPerm(arr, vis,tar - arr[idx],0, ans + to_string(arr[idx])); 
    vis[idx] = false;
    } 
    count+= SubseqSingleCoinsPerm(arr, vis,tar,idx+1 ,ans);
    return count;
}
int SubseqSingleCoinsComb(vector<int> &arr,vector<bool> &vis, int tar,int idx, string ans){
    if(tar == 0 || idx == arr.size()){

        if(tar == 0){
            cout<< ans<<endl;
            return 1;
        }else{
        return 0;}
    }
    int count = 0;
    if((tar - arr[idx]) >= 0 && !vis[idx]){
    vis[idx] = true;
    count+= SubseqSingleCoinsComb(arr, vis,tar - arr[idx],idx+1, ans + to_string(arr[idx])); 
    vis[idx] = false;
    } 
    count+= SubseqSingleCoinsComb(arr, vis,tar,idx+1 ,ans);
    return count;
}
void basicQues(){
    vector<bool> vis(4,false);
    vector<int>arr{2,3,5,7};
    cout << SubseqSingleCoinsComb(arr,vis,10, 0,"");
}
int main(){
    basicQues();
    return 0;    
}