#include<iostream>

using namespace std;

oct_sub(int n1,int n2){

    bool isneg = false;

    if(n1<=n2){
        int temp = n1;
        n1 = n2;
        n2 = temp;
        isneg = true;
    }

    int res = 0;
    int rem;
    int borrow = 0;
    int pow = 1;

    while(n1!= 0||n2!= 0){

        rem = n1 % 10 - n2 % 10 + borrow;

        if(rem< 0){
            borrow = -1;
            rem += 8;
        }
        else
            borrow = 0;
            
        res += rem*pow;

        n1 /= 10;
        n2 /= 10;
        pow*= 10;

        
    }
    if(isneg)
            res *= -1;
        
    cout<<res;
}

int main(int args,char**argc){

    int num1,num2;

    cout<<"Enter two numbers: ";
    cin>>num1>>num2;

    oct_sub(num1,num2);
    return 0;
}