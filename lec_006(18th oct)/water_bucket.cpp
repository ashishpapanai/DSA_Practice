#include<iostream>
#include<vector>

using namespace std;

void water_cap(vector<int>&arr){

    int max_vol = 0;
    int height;
    int i = 0;
    int j = arr.size() - 1;

    while(i< j){

        if(arr[i]<= arr[j]){
            
            height = arr[i];
            max_vol = max(height * (j-i), max_vol);
            i++;
        }
        else{

            height = arr[j];
            max_vol = max(height * (j-i), max_vol);
            j--;
        }
    }

    cout<<max_vol;

}

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

int main(){

    int size;

    cout<<"Enter the size of array: ";
    cin>>size;

    vector<int> arr(size,0);

    arr_input(arr);
    arr_output(arr);

    cout<<endl;
    water_cap(arr);

    return 0;
}