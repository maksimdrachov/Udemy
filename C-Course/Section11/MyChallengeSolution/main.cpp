#include <iostream>
#include <vector>

using namespace std;

void print_menu();
void print_numbers(vector<int> &);
void add_numbers(vector<int> &);
void mean_numbers(vector<int> &);
void smallest_numbers(vector<int> &);
void largest_numbers(vector<int> &);

int main() {
    
    vector<int> numbers {};
    bool programm_running {1};
    
    do {
        
        char selection {};
        
        print_menu();
        
        cin >> selection;
        
        
        switch (selection) {
            case 'P':
            case 'p': {
                        print_numbers(numbers);
                        break;
                      }
            
            case 'A':
            case 'a': {
                        add_numbers(numbers);
                        break;
                      }
            case 'M':
            case 'm': {
                        mean_numbers(numbers);
                        break;
                      }
            case 'S':
            case 's': {
                        smallest_numbers(numbers);
                        break;
                      }
            case 'L':
            case 'l': {
                        largest_numbers(numbers);
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

void print_menu() {
    cout << endl << "======================================="<< endl;
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;
    cout << "Enter you choice: " << endl;
    
    }
    
void print_numbers(vector<int> &numbers) {
    cout << "Stored numbers: " << endl;
    cout << "[";
    for(int i=0; i < numbers.size(); i++) {
        cout << numbers.at(i) << " ";
        }
    cout << "]";
    }
    
void add_numbers(vector<int> &numbers) {
    cout << "Add number: " << endl;
    int new_number {0};
    cin >> new_number;
    numbers.push_back(new_number);
    }
    
void mean_numbers(vector<int> &numbers) {
    cout << "Mean of the numbers: " << endl;
    int total {0};
    for (auto value : numbers){
        total += value;
        }
    cout << static_cast<double>(total)/numbers.size();
    }
    
void smallest_numbers(vector<int> &numbers) {
    cout << "Smallest of the numbers: " << endl;
    int smallest_number {numbers.at(0)};
    for (int value : numbers){
        if (smallest_number > value){
            smallest_number = value;
        }
    }
    cout << smallest_number;
    }
    
void largest_numbers(vector<int> &numbers) {
    cout << "Largest of the numbers: " << endl;
    int largest_number {numbers.at(0)};
    for (int value : numbers){
        if (largest_number < value){
            largest_number = value;
        }
    }
    cout << largest_number;
    
    }