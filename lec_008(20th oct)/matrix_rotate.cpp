#include<iostream>
#include<vector>

using namespace std;

void transpose(vector<vector<int>>&arr){

    for(int i = 0;i < arr.size();i++){
        for(int j = i;j < arr[0].size;j++)
            swap(arr[i][j], arr[j][i]);
    }
}

void swapR(vector<vector<int>>&arr){

    for(int i = 0;i<)
}