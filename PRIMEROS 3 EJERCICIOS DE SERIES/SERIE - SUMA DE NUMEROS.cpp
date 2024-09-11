//Ejer1
#include <iostream>
using namespace std;
int main()
{
    int n,z=0;
    cout<<"Ingrese n: "; 
    cin>>n;
    cout<<"Los numeros de la serie son: ";
    for(int i=1; i<=n; i++)
    {
        cout<<i<<" ";
        z+=i;
    }

    cout<<endl<<"La suma de la series es: "<<z;
    return 0;
}
