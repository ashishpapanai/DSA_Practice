#include<iostream>

using namespace std;

int Dtobase2(int n,int base2)
{
    int res = 0;
    int pow = 1;
    int rem;
    while(n!= 0)
    {
        rem = n % base2;
        res+= pow*rem;

        pow*= 10;
        n /= base2;
    }
    cout<<endl;
    cout<<"Base 2 form: "<<res;
}

int base1toD(int n,int base1)
{   
    int res = 0;
    int pow = 1;
    int rem;
    while(n!= 0)
    {
        rem = n % 10;
        res+= pow*rem;

        pow*= base1;
        n /= 10;
    }
    cout<<"Dec: "<<res;

    int base2;
    cout<<"\n Enter new base: ";
    cin>>base2;
    Dtobase2(res,base2);
}
int main(int args,char**argv)
{
    int n,base1;

    cout<<"Enter the value of n and base1: ";
    cin>>n>>base1;

    base1toD(n,base1);

    return 0;
}