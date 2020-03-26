#include<iostream>
#include<vector>

using namespace std;

void rev(vector<int>&a,int low_lim,int upp_lim){

    for(int i = low_lim,k = upp_lim;i< k;i++,k--){

        int temp = a[i];
        a[i] = a[k];
        a[k] = temp;
    }
}

void rotate(vector<int>&arr,int r){

    int l = arr.size();
    
    r %= l;
    r = (r<0)? r += l:r;
    
    rev(arr,0,r-1);
    rev(arr,r,l-1);
    rev(arr,0,l-1);
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

int main(int arg, char** argv){

    int size,r;
    cout<<"Enter the size of array: ";
    cin>>size;

    vector<int> arr(size,0);

    arr_input(arr);

    cout<<"Enter the number of rotation: ";
    cin>>r;
    rotate(arr,r);
    arr_output(arr);

    return 0;
}