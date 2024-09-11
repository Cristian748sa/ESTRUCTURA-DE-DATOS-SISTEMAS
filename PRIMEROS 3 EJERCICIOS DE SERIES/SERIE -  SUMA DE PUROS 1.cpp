//Ejer2
#include <iostream>
using namespace std;

int main() {
    int n, z=0;
    cout<<"Ingrese n: "; 
    cin>>n;

    cout<<"Los números de la serie son: ";
    for(int i=1; i<=n; i++){
        cout << " 1 ";
        z+=1;
    }

    cout<<endl<<"La suma de la serie es: " << z;
    return 0;
}