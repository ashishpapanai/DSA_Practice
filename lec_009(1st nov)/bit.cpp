#include<iostream>

using namespace std;

int count_one_left_shift(int n){

    int count = 0;

    for(int i = 0; i< 32; i++){
        
        int mask = 1<<i;

        if((n & mask) != 0)
            count++;
    }
    return count;
} 

int count_one_right_shift(int n){

    int count = 0;
    int bit = 0;

    while(n!= 0 && bit < 32){

        if((n & 1) != 0)
            count++;

        n = n>>1;
        bit++;
    }
    return count;
}

int count_one_optimize(int n){

    int count = 0;

    while(n!= 0){

        n &= (n-1);
        count++;
    }
    return count;
}

int main()
{
    int n = -1;
    //cout<<count_one_left_shift(n);
    //cout<<count_one_right_shift(n);
    cout<<count_one_left_shift(10);

    return 0;
}