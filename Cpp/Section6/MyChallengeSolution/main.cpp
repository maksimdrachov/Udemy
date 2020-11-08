#include <iostream>

using namespace std;

int main() {
    
    int number_of_small {0};
    int number_of_large {0};
    
    const float price_small {25};
    const float price_large {35};
    const int valid_days {30};
    
    cout << "How many small rooms need to be cleaned?" << endl;
    cin >> number_of_small;
    cout << "How many large rooms need to be cleaned?" << endl;
    cin >> number_of_large;
    cout << endl;
    cout << "Estimate for carpet cleaning service" << endl;
    cout << "Number of small rooms: " << number_of_small << endl;
    cout << "Number of large rooms " << number_of_large << endl;
    cout << "Price per small room: $" << price_small << endl;
    cout << "Price per large room: $" << price_large << endl;
    cout << "Cost: $" << (price_small*number_of_small+price_large*number_of_large) << endl;
    cout << "Tax: $" << (price_small*number_of_small+price_large*number_of_large)*0.06 << endl;
    cout << "============================" << endl;
    cout << "Total estimate: $" << (price_small*number_of_small+price_large*number_of_large)*1.06 << endl;
    cout << "This estimate is valid for " << valid_days << " days." << endl;
    
    
    
    return 0;
}
