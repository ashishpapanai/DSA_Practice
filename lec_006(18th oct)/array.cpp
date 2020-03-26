#include<iostream>
#include<vector>

using namespace std;

bool find(vector<int>& arr,int n){

    for(int i = 0;i< arr.size();i++){

        if(arr[i] == n){

            cout<<"Founded";
            return true; 
        }
    }
   cout<<"Not found";
   return false;
}

int max_value(vector<int>&arr){

    int max_val = arr[0];

    for(int ele : arr){

        if(ele > max_val)
            max_val = ele;
    }
    return max_val;
}

int min_value(vector<int>&arr){

    int min_val = arr[0];

    for(int ele : arr){

        if(ele < min_val)
            min_val = ele;
    }
    
    return min_val;
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


int main(int args,char** argv){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int>arr(n,0);

    arr_input(arr);
    arr_output(arr);

    int val;
    cout<<"Enter the value to be founded: ";
    cin>>val;

    find(arr,val);

    cout<<endl;
    cout<<"Maximum value: "<<max_value(arr);
    cout<<endl;
    cout<<"Minimum value: "<<min_value(arr);

    return 0;
}