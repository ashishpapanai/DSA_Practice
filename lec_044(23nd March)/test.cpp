#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int longestSeries(vector<int> &arr){
    unordered_map<int, bool> map;
    for(int ele: arr) map[ele] = true;

    int size = -1;
    int number = -1;

    for(auto keys: map){
        if(map.find(keys.first - 1) != map.end())
        map[keys.first] = false;
    }

    for (auto keys : map)
    {
        int num = keys.first;
        int smallSize = 1;
        while (map.find(num) != map.end())
        {
            num++;
            smallSize++;
        }
        if(smallSize > size){
            size = smallSize;
            number = keys.first;
        }
    }

    for (int i = 0; i < size-1; i++)
    {
        cout << number+i <<" ";
    }
    cout << endl;    
}

int main(){
    vector<int> arr{0,1,2,3,4,5,6,234,98,56,87,98,976,98,99,100,101,102,103,104,105,106};
    longestSeries(arr);
}