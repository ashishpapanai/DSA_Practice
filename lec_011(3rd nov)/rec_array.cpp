#include<iostream>
#include<vector>
#include<climits>   //For min and max value

using namespace std;

void display(vector<int>& arr, int i){

    if(i == arr.size())
        return;
    
    cout<<arr[i]<<" ";
    display(arr,i+1);
}

int max_array(vector<int>& arr, int i){

    // if(i == arr.size())      MINIMUM VALUE
    //     return INT_MIN;
    
    if(i == arr.size())
        return arr[i];

    int ans = max_array(arr,i+1);
    
    return max(ans,arr[i]);
}

int find(vector<int>& arr, int i, int data){     //Finding data in pre order

    if(i == arr.size())
        return 0;

    if(data == arr[i])
        return 1;

    return find(arr,i+1,data);
}

void mirror_index_val(vector<int>&arr, int i){

    if(i == arr.size())
        return;
    
    int temp = i;
    i = arr[i];
    arr[i] = temp;

    mirror_index_val(arr,i+1);
    cout<<i;
}

int main(int args,char ** argv){

    vector<int> arr({2,3,4,0,5,6,1});
    //display(arr,0);

    //cout<<max_array(arr,0);

    //cout<<find(arr,0,30);

    mirror_index_val(arr,0);
    return 0;
}