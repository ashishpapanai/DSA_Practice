#include<iostream>

using namespace std;

int dig(int n){

    int temp = n;
    int digit = 0;

    while(temp!=0){

        digit++;
        temp = temp /10;
    }

    return digit;
}

int rotate(int n,int r){

    int digit = dig(n);
    int mul = 1, div = 1;
    r = r % digit;
    r = (r<0)? r += digit : r;

    for(int i = 1;i <= digit;i++){

        if(i <= r)
            mul *= 10;
        else
            div *= 10; 
    }

    int fdigit = n / div;
    int sdigit = n % div;

    int new_num = sdigit * mul + fdigit;

    return new_num;
}

int main(int args, char** argv){

    int n,r;
    
    cout<<"Enter the value of n and r: ";
    cin>>n>>r;
    cout<<rotate(n,r);

    return 0;

    
}