#include<iostream>
#include<vector>

using namespace std;


void input_motion(vector<vector<int>>&arr){

    for(int i = 0;i< arr.size();i++){
        for(int j = 0;j< arr[i].size();j++){

            if(i % 2 == 0)
                cin>>arr[i][j];
            else
                cin>>arr[i][arr[i].size()-1 -j];
        }
    }    
}

// void exit_point(vector<vector<int>>&arr){

//     for(int i = 0;i< arr.size();i++){
//         for(int j = 0;j< arr[i].size();j++){

//             if(a[i][j] == 0)
//         }
//     }
// }

void display(vector<vector<int>>&arr){

    for(int i = 0;i< arr.size();i++){
        for(int j = 0;j< arr[i].size();j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}

int main(int args,char** argv){

    int row,col;
    cout<<"Enter the number of rows and columns: ";
    cin>>row>>col;

    vector<vector<int>>arr(row,vector<int>(col,0));

    input_motion(arr);
    cout<<endl;
    display(arr);

    return 0;
}