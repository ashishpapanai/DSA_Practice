#include<iostream>

using namespace std;

void mirrortriangle(int rows){

    int nsp = rows-1;
    int nst = 1;

    for(int i= 1;i<= rows;i++){

        for(int csp = 1;csp<= nsp;csp++)
            cout<<" ";
        
        for(int cst = 1;cst<= nst;cst++)
            cout<<"*";

        nst++;
        nsp--;
        cout<<endl;
    }

}

int main(int args, char** argv){

    int rows;
    cout<<"Enter the number of rows: ";
    cin>>rows;

    mirrortriangle(rows);

    return 0;
}