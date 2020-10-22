#include <iostream>

using namespace std;

int main() {
    
    int nReturn {0};
    
    cout << "Enter the number of cents to be returned:" << endl;
    cin >> nReturn;
    
    int nDollars {0};
    int nQuarters {0};
    int nDimes {0};
    int nNickels {0};
    int nPennies {0};
    
    nDollars = nReturn / 100;
    nReturn -= (nDollars*100);
    
    nQuarters = nReturn / 25;
    nReturn -= (nQuarters*25);
    
    nDimes = nReturn / 10;
    nReturn -= (nDimes*10);
    
    nNickels = nReturn / 5;
    nReturn -= (nNickels*5);
    
    nPennies = nReturn / 1;
    nReturn -= (nPennies*1);
    
    cout << "Return the following: " << endl;
    cout << "Dollars: " << nDollars << endl;
    cout << "Quarters " << nQuarters << endl;
    cout << "Dimes: " << nDimes << endl;
    cout << "Nickels: " << nNickels << endl;
    cout << "Pennies: " << nPennies << endl;
    
    
    
    return 0;
}
