// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    std::ifstream in_file;
    std::string filename{"responses.txt"};

    in_file.open(filename);
    
    // Load the solution
    std::string solution;
    in_file >> solution;
    std::cout << "Solution loaded: " << solution << std::endl;
    
    // Iterate through students and save score
    vector<std::string> students;
    vector<int> scores;
    
    std::string student_name;
    std::string student_answers;
    
    while (in_file >> student_name) {
        in_file >> student_answers;
        students.push_back(student_name);
        
        std::cout << "Student name: " << student_name << std::endl;
        int student_score {0};
        for(int i=0; i<solution.size(); i++) {
            if (solution[i] == student_answers[i])
                student_score = student_score + 1;
            }
        scores.push_back(student_score);
        std::cout << "Student score: " << student_score << std::endl;
        }
    
    // Outpur
    const int field1_width {20};    // Student name
    const int field2_width {20};    // Student score
    
    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cout << std::setw(field1_width) << std::left << "Student" 
                   << std::setw(field2_width) << std::right << "Score" 
                   << std::endl;
    
    for (int i = 0; i < students.size(); i++) {
        std::cout << std::setw(field1_width) << std::left << students.at(i) 
                  << std::setw(field2_width) << std::right << scores.at(i) << std::endl;
        
        }
    
    cout << "Hello world" << endl;
    return 0;
}

