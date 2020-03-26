#include<iostream>
#include<vector>

using namespace std;

void input(vector<vector<int>>&arr){

    for(int i = 0;i< arr.size();i++){
        for(int j = 0;j< arr[i].size();j++)
                cin>>arr[i][j];
    }
}

void exit_point(vector<vector<int>>&arr){

    int row = 0, col = 0, dir = 0;

    while(true){

        dir = (dir + arr[row][col]) % 4;

        if(dir == 0){
            col++;
            if(col == arr[0].size()){
                cout<<row<<","<<(col-1)<<endl;
                break;
            }
        }
        else if(dir == 1){
            row++;
            if(row == arr.size()){
                cout<<(row-1)<<","<<col<<endl;
                break;
            }
        }
        else if(dir == 2){
            col--;
            if(col == -1){
                cout<<row<<","<<(col+1)<<endl;  
                break;
            }
        }
        else{
            row--;
            if(row == -1){
                cout<<(row+1)<<","<<col<<endl;
                break;
            }
        }
    }
}

void display(vector<vector<int>>&arr){

    for(int i = 0;i< arr.size();i++){
        for(int j = 0;j< arr[i].size();j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}

int main(int args,char** argv){

    int row,col;

    cout<<"Enter number of rows and columns: ";
    cin>>row>>col;

    vector<vector<int>>arr(row,vector<int>(col,0));

    input(arr);
    exit_point(arr);

    return 0;
}