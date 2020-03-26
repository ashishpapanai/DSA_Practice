#include<iostream>
#include<vector>

using namespace std;

void arr_input(vector<int>&arr){

    for(int i = 0;i< arr.size();i++){
        cout<<"a["<<i<<"]= ";
        cin>>arr[i];
        cout<<endl;
    }
}

void arr_output(vector<int>&arr){

    for(int i = 0;i< arr.size();i++)
        cout<<"a["<<i<<"]= "<<arr[i]<<endl;
}

int main(int args,char** argv){

    int n;

    cout<<"Enter the number of size of array: ";
    cin>>n;
    vector<int>arr(n,0);

    arr_input(arr);
    arr_output(arr);

    return 0;
}