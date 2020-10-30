#include <iostream>

using namespace std;

int * apply_all(const int* const, size_t, const int* const, size_t);
void print(const int* const, size_t);

int main() {
    const size_t array1_size {5};
    const size_t array2_size {3};
    
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30}; 
    
    cout << "Array 1: ";
    print(array1, array1_size);
    
    cout << "Array 2: ";
    print(array2, array2_size);
    
    int *results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size {array1_size * array2_size};
    
    cout << "Result: ";
    print(results, results_size);
    
    delete [] results;
    cout << endl;
    
    return 0;
}

void print(const int* const array_pointer, size_t size) {
    cout << "[ ";
    for (size_t i=0; i < size; i++){
        cout << array_pointer[i] << " ";
        }
    cout << "]" << endl;
    }

int* apply_all(const int* const array1_pointer, size_t array1_size, const int* const array2_pointer, size_t array2_size) {
    int *new_array {nullptr};
    new_array = new int[array1_size*array2_size];
    int counter {0};
    for (int i=0; i < array2_size; i++){
        for (int j=0; j < array1_size; j++){
            new_array[counter] = array2_pointer[i]*array1_pointer[j];
            counter +=1;
            }
        }
    return new_array;
    
    }