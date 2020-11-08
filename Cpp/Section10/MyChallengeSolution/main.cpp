#include <iostream>
#include <string>

using namespace std;

int main() {
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    
    string s1;
    int number_char {0};
    
    cout << "Please enter a message to be encoded: " << endl;
    getline(cin, s1);
    
    // Encoding message
    for (char c: s1) {
        if (isalpha(c)) {
            char letter_code;
            letter_code = key.at(alphabet.find(c));
            s1.at(number_char) = letter_code;
            }
        number_char +=1;
        }
    
    cout << "Encoded message: " << s1 << endl;
    number_char = 0;
    // Decoding message
    for (char c: s1) {
        if (isalpha(c)) {
            char letter_code;
            letter_code = alphabet.at(key.find(c));
            s1.at(number_char) = letter_code;
            }
        number_char +=1;
        }
    cout << "Decoded message: " << s1 << endl;
    return 0;
}
