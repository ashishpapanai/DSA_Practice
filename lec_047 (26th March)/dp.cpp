#include<iostream>
#include<vector>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

int display(vi dp){
    for(int i : dp){
        cout << i << " ";
    }
    cout << endl;
}

int fibo_01(int n, vector<int> &dp){
    if(n <= 1) {
        dp[n] = n;
        return n;
    }
    if(dp[n] != 0) 
        return dp[n];

    int ans = fibo_01(n-1, dp) + fibo_01(n-2, dp);    
    
    dp[n] = ans; //DP ON and OFF
    
    return ans;
}

int fibo_02(int n, vector<int> &dp){
  
    for(int i =0 ; i <= n; i++){
        if(i <= 1) {
            dp[i] = i;
            continue;        
        }
        dp[i] = dp[i-1] + dp[i-2];
    }    
    return dp[n];
}

int mazePath(int sr, int sc, int er, int ec, vii &dp){
    if(sr == er && ec == sc){
        dp[sr][sc] = 1;
        return 1;
    }

    int count = 0;
    
    if(dp[sr][sc] != 0){
        return dp[sr][sc];
    }

    if(sr + 1 <= er){
        count += mazePath(sr + 1,sc,er,ec);
    }

    if(er == ec && dp[sc][sr] != 0){
        return dp[sc][sr];
    }

    if(sc + 1 <= ec){
        count += mazePath(sr + 1,sc,er,ec);
    }
    dp[sr][sc] = count;

    if(re == ec) dp[sc][sr] = count;
        
    return count;
}

void set1(){
    // int n = 10;
    vvi dp(n+1, 0);
    // cout<< fibo_02(n, dp) << endl;
    // display(dp);

    cout <<mazePath(0,0,3,3,dp) <<endl;
}

void solve(){
    set1();
}


int main(){
    solve();
    return 0;
}