#include<iostream>

using namespace std;

void even_odd(int n)
{
    if(n == 0)
    {
        cout<<n<<endl;
        return;
    }

    if(n % 2 == 0)
        cout<<n<<endl;
   
    even_odd(n-1);

    if(n % 2 != 0)    
        cout<<n<<endl;
}

int main(int args,char ** argv)
{

    even_odd(10);
    return 0;
}