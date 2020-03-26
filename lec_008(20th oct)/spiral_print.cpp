#include<iostream>
#include<vector>

using namespace std;

void input(vector<vector<int>>&arr){

    for(int i = 0;i< arr.size();i++){
        for(int j = 0;j< arr[i].size();j++)
                cin>>arr[i][j];
    }
}

void spiral_print(vector<vector<int>>&arr){

    int minr = 0,minc = 0;
    int maxr = arr.size() - 1 ,maxc = arr[0].size() - 1;

    int total_elm = arr.size() * arr[0].size();

    while(total_elm != 0){

        for(int i = minc;i<= maxc && total_elm !=0;i++){
            cout<<arr[minr][i]<<" ";
            total_elm--;
        }
        minr++;

        for(int i = minr;i<= maxr && total_elm !=0;i++){
            cout<<arr[i][maxc]<<" ";
            total_elm--;
        }
        maxc--;

        for(int i = maxc;i>= minc && total_elm !=0;i--){
            cout<<arr[maxr][i]<<" ";
            total_elm--;
        }
        maxr--;

        for(int i = maxr;i>= minr && total_elm !=0;i--){
            cout<<arr[i][minc]<<" ";
            total_elm--;
        }
        minc++;
    }
}

int main(int args,char**argv){

    int row,col;
    cout<<"Enter the number of rows and columns: ";
    cin>>row>>col;

    vector<vector<int>>arr(row,vector<int>(col,0));

    input(arr);
    spiral_print(arr);

    return 0;
}