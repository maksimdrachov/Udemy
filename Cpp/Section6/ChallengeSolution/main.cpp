#include <iostream>

using namespace std;

int main() {
    
    cout << "Hello, welcome to Frank's Carpet Cleaning Service" << endl;
    
    int small_rooms {0};
    cout << "\nHow many small rooms would you like cleaned?";
    cin >> small_rooms;
    
    int large_rooms {0};
    cout << "How many large rooms would you like cleaned?";
    cin >> large_rooms;
    
    const double price_small {25.0};
    const double price_large {35.0};
    
    const double sales_tax {0.06};
    const int estimate_expiry {30};
    
    cout << "Estimate for carpet cleaning service" << endl;
    cout << "Price per small room: $" << price_small << endl;
    cout << "Price per large room: $" << price_large << endl;
    cout << "Cost: $" << (price_small*small_rooms+price_large*small_rooms) << endl;
    cout << "Tax: $" << (price_small*small_rooms+price_large*small_rooms)*sales_tax << endl;
    cout << "============================" << endl;
    cout << "Total estimate: $" << (price_small*small_rooms+price_large*small_rooms)*(sales_tax+1) << endl;
    cout << "This estimate is valid for " << estimate_expiry << " days." << endl;
    
    
    
    
    return 0;
}
