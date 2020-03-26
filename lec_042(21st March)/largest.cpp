#include<stdio.h>
#include<queue>

using namespace std;

void downheapify(vector<int> &arr, int idx, int lidx){
    int midx= idx;
    int lci = idx >> 1 + 1;
    int rci = idx >> 1 + 2;
    if(lci <= lidx && arr[rci] > arr[midx]) midx= rci;
    if(rci <= lidx && arr[lci] > arr[midx]) midx = lci;
    if(midx != idx){
        swap(arr[idx], arr[midx]);
        downheapify(arr, midx, lidx);
    }
}
int kthSmallest(vector<int> &nums, int k) {
    int n = nums.size()-1;
    for(int i = n; i >= 0; i--)downheapify(nums,i,n);
    for(int i = 0; i < k; i++){
        swap(nums[0], nums[n-i]);
        downheapify(nums, 0, n-i-1);
    }
    return nums[n+1-k];            
}