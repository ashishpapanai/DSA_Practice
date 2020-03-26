#include<iostream>

using namespace std;

int fact(int n){

    int ans = 1;
    for(int i = 2;i <= n;i++){
        ans *= i;
    }

    return ans;
}

void ncr(){

    int n,r;
    cout<<"Enter n and r: ";
    cin>>n>>r;

    int ans = fact(n)/(fact(r) * fact(n-r));

    cout<<ans;
}

int main(int args, char** argv){

    int n;
    cout<<"Enter number: "<<endl;
    cin>>n;

    cout<<fact(n);
    ncr();

    return 0;
}