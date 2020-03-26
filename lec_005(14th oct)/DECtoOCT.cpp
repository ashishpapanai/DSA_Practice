#include<iostream>

using namespace std;

DtoOct(int n)
{
    int res = 0;
    int pow = 1;
    int rem;

    while(n!= 0)
    {
        rem = n % 8;
        res += pow*rem;
        pow *= 10;

        n /= 8;
    }
    cout<<res;
}

int main(int args,char**argv)
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<endl<<"Octal: ";
    DtoOct(n);

    return 0;
}
