#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    vector<int> numbers {};
    bool programm_running {1};
    
    do {
        
        char selection {};
        
        cout << endl << "======================================="<< endl;
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl;
        cout << "Enter you choice: " << endl;
        
        cin >> selection;
        
        
        switch (selection) {
            case 'P':
            case 'p': {cout << "Stored numbers: " << endl;
                      cout << "[";
                      for(int i=0; i < numbers.size(); i++) {
                          cout << numbers.at(i) << " ";
                          }
                      cout << "]";
                      break;
                      }
            
            case 'A':
            case 'a': {cout << "Add number: " << endl;
                      int new_number {0};
                      cin >> new_number;
                      numbers.push_back(new_number);
                      break;
                      }
            case 'M':
            case 'm': {cout << "Mean of the numbers: " << endl;
                      int total {0};
                      for (auto value : numbers){
                          total += value;
                          }
                      cout << static_cast<double>(total)/numbers.size();
                      break;
                      }
            case 'S':
            case 's': {cout << "Smallest of the numbers: " << endl;
                      int smallest_number {numbers.at(0)};
                      for (int value : numbers){
                          if (smallest_number > value){
                              smallest_number = value;
                              }
                          }
                      cout << smallest_number;
                      break;
                      }
            case 'L':
            case 'l': {cout << "Largest of the numbers: " << endl;
                      int largest_number {numbers.at(0)};
                      for (int value : numbers){
                          if (largest_number < value){
                              largest_number = value;
                              }
                          }
                      cout << largest_number;
                      break;
                      }
            case 'Q':
            case 'q': {cout << "Goodbye!" << endl;
                      programm_running = 0;
                      break;
                      }
            
            //default: cout << "INVALID INPUT";
        
        }
    } while (programm_running == 1);
    
    
    return 0;
}
