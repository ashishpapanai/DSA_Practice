#include<iostream>

using namespace std;

void num_print(int n)
{
    if(n == 0)
    {
        cout<<"base"<<endl;
        return;
    }
    cout<<"hi "<<n<<endl;
    num_print(n-1);
    cout<<"bye"<<n<<endl;
}

int main(int args,char** argv)
{ 

    num_print(8);
    return 0;
}
