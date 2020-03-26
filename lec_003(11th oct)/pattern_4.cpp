#include<iostream>

using namespace std;

void full_diamond(int rows){

    int nst = 1;
    int nsp = rows/2;

    for(int i = 1;i<= rows;i++){

        for(int csp = 1;csp<= nsp;csp++)
            cout<<" ";
        
        for(int cst = 1;cst<= nst;cst++)
            cout<<"*";

        if(i <= rows/2){

            nst = nst + 2;
            nsp--;
        }
        else{

            nst = nst - 2;
            nsp++;
        }
        cout<<endl;
    }
}

int main(int args,char** argv){

    int rows;

    cout<<"Enter the number of rows: ";
    cin>>rows;

    full_diamond(rows);

    return 0;
}
