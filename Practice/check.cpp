#include <iostream>
#include <bits/stdc++.h> 
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int testCase;
	cin >>testCase;
	while(testCase > 0){
    	int n; int m;
    	cin >> n;
    	cin >> m;
    	vector<int> f;
    	vector<int> p;
    	for(int i = 0; i < n; i++){
    	    cin >> f[i];
    	}
    	for(int i = 0; i < n; i++){
    	    cin >> p[i];
    	}
    	vector<int> ans;
    	for(int i = 0; i < n; i++){
    	    ans[f[i]] += p[i];  
    	}
    	cout<< *min_element (ans.begin(), ans.end())<<" "; 
    	testCase--;
	}
	return 0;
}
