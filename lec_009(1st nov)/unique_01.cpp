#include<iostream>
#include<vector>

using namespace std;

int unique_01(vector<int>& arr){

    int ans = 0;
    for(int i = 0; i<= arr.size(); i++)
        ans = ans ^ arr[i];

    return ans;   
}

int main(int args,char** argv){

    vector<int> arr({1,1,2,2,3,4,4});

    cout<<unique_01(arr);

    return 0;

}