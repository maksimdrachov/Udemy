#include <iostream>
#include <vector>

using namespace std;


int main() {
    vector <int> vector1 {};
    vector <int> vector2 {};
    
    vector1.push_back(10);
    vector1.push_back(20);
    
    //"Display the elements in vector 1"
    cout << "Elements of vector 1" << endl;
    cout << vector1.at(0) << endl;
    cout << vector1.at(1) << endl;
    
    //"Display the size of vector 1"
    cout << "The size of vector 1 is " << vector1.size() << endl;
    
    vector2.push_back(100);
    vector2.push_back(200);
    
    //"Display the elements in vector 2"
    cout << "Elements of vector 2" << endl;
    cout << vector2.at(0) << endl;
    cout << vector2.at(1) << endl;
    
    //"Display the size of vector 2"
    cout << "The size of vector 2 is " << vector2.size() << endl;
    
    //Declare an empty 2D vector called vector_2d
    vector <vector<int>> vector_2d;
    
    //Add vector1 to vector_2d dynamically using push_back
    vector_2d.push_back(vector1);
    
    //Add vector2 to vector_2d dynamically using push_back
    vector_2d.push_back(vector2);
    
    //Display the elements in vector_2d again using the at() method
    cout << "elements of vector  2d" << endl;
    cout << vector_2d.at(0).at(0) << endl;
    cout << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << endl;
    cout << vector_2d.at(1).at(0) << endl;
    
    //Change vector1.at(0) to 1000
    cout << "Vector1 changed" << endl;
    vector1.at(0) = 1000;
    
    //Display the elements in vector 2d again
    cout << "elements of vector  2d" << endl;
    cout << vector_2d.at(0).at(0) << endl;
    cout << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << endl;
    cout << vector_2d.at(1).at(0) << endl;
    
    
    return 0;
}
