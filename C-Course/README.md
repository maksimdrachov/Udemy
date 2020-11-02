# Beginning C++ Programming - from Beginner to Beyond

## Section 9: Controlling Programming Flow

#### if else statement
```
if (expr){
  statement;
}
```

#### switch case statement
```
switch (selection) {
  case '1': cout << "1 selected";
            break;
  case '2': cout << "2 selected";
            break;
  case '3': 
  case '4': cout << "3 or 4 selected";
            break;
  default:  cout << "1,2,3,4 NOT selected";
}
```

#### for loop
```
for (initialization ; condition ; increment) {
  statement;
}

int i {0};

for (i = 1; i <= 5; i++) {
  cout << i << endl;
}
```

#### range-based for loop
```
for (var_type var_name: sequence) {
  statement; // can use var_name
}

vector <double> temps {87.2, 77.1, 80.0, 72.5};

double average_temp {};
double running_sum {};

for (double temp: temps)
  running_sum += temp;
 
 average_temp = running_sum / temps.size();

int scores [] {100, 90, 97};

for (int score : scores)
  cout << score << endl;
  
 100
 90
 97

```

#### while loop
```
int i {1};

while (i <= 5) {
  cout << i << endl;
  i++;
}

1
2
3
4
5

```

#### do-while loop
```
int number {};
do {
  cout << "Enter an integer between 1 and 5: ";
  cin >> number;
} while (number <= 1 || number >= 5);

```

## Section 10: Characters and Strings
```
#include <cctype>
```
| isalpha(c)  | True if c is a letter |
| isalnum(c)  | True if c is a letter or digit  |
| isdigit(c)  | True if c is a digit  |
| islower(c)  | True if c is a lowercase letter  |
| isprint(c)  | True if c is a printable character  |
| ispunct(c)  | True if c is a punctuation character  |
| isupper(c)  | True if c is an uppercase letter  |
| isspace(c)  | True if c is whitespace  |
|   |   |
| tolower(c)  | returns lowercase of c  |
| toupper(c)  | returns uppercase of c  |

```
char str[80];

strcpy(str, "Hello "); //copy

strcat(str, "there "); //concatenate

cout << strlen(str); //10

strcomp(str, "Another"); //-1
```

```
#include <string>
using namespace std;

string s1;				//empty
string s2 {"Frank"};	//Frank
string s3 {s2};			//Frank
string s4 {"Frank", 3};	//Fra
string s5 {s3, 0, 2};	// Fr
string s6 (3,'X');		// XXX
```

#### Concatenation
```
string part1 {"C++"};
string part2 {"is a powerful"};

string sentence;

sentence = part1 + " " + part2 + " language"; // C++ is a powerful language
sentence = "C++"+" is powerrful"; // ILLEGAL!
```

#### Accessing characters [] and at() method
```
string s1;
string s2 {"Frank"};

cout << s2[0] << endl; 	// F
cout << s2.at(0) << endl; // F

s2[0] = 'f'; // frank
s2.at(0) = 'p'; // prank

------------
string s1 {"Frank"};

for (char c: s1)
	cout << c << endl;
F
r
a
n
k

```

#### Comparing
```
string s1 {"Apple"};
string s2 {"Banana"};
string s3 {"Kiwi"};
string s4 {"apple"};
string s5 {s1};

s1 == s5		// True
s1 == s2 		// False
s1 != s2		// True
s1 < s2			// True
s2 > s1			// True
s4 < s5 		// False
s1 == "Apple";	// True
```

#### Substring
substr() - Extracts a substring from a std::string

```
object.substr(start_index, length)
```

find() - Returns the index of a substring in a std::string

```
object.substr(start_index, length)

string s1 {"This is a test"};

cout << s1.find("This") // 0
cout << s1.find("XX");	// string::npos
```

#### Other useful methods
```
string s1 {"Frank"};

cout << s1.length() << endl; 	// 5

s1 += " James";
cout << s1 << endl;				// Frank James
```

Input >> and getline()
Reading std::string from cin

```
string s1;
cin >> s1;		// Hello there
				// Only accepts up to the first space
cout << s1 << endl;	// Hello

getline(cin, s1)	// Read entire line until \n
cout << s1 << end;	// Hello there

getline(cin, s1, 'x');	// this isx
cout << s1 << endl; // this is
```

##Section 11: Functions
#### Pass by Reference
```
void scale_number(int & num); 		//prototype

int main() {
	int number {1000};
	scale_number(number);			//call
	cout << number << endl;			//100
	return 0;
}

void scale_number(int &num) {
	if (num > 100)
		num = 100;
}
```

##Section 12: Pointers and References
#### Declaring Pointers
```
variable_type *pointer_name {nullptr};
```
#### Accessing the Pointer Address
```
int *p;
cout << "Address of p is: "<< &p << endl; 
```
#### Dereferencing a pointer
You can access the data at the address contained in the score_ptr using the dereferecing operator 
```
int score {100};
int *score_ptr {&score};

cout << *score_ptr << endl;	//100

*score_ptr = 200;			
cout << *score_ptr << endl;	//200
cout << score << endl;		//200
```

#### Dynamic Memory Allocation
```
int *int_ptr {nullptr};

int_ptr = new int;		//allocate an integer on the heap

delete int_ptr;			//frees the allocated storage
```

####  Pointers to constants
The data pointed to by the pointers is constant and cannot be changed.
The pointer itself can change and point somewhere else.

```
int high_score {100};
int low_score {65};

const int *score_ptr { &high_score};

*score_ptr = 86;		//ERROR
score_ptr = &low_score;	// OK
```

The data pointed to by the pointers can be changed.
The pointer itself cannot change and point somewhere else.

```
int high_score {100};
int low_score {65};

int *const score_ptr { &high_score};

*score_ptr = 86;		// OK
score_ptr = &low_score;	// ERROR
```

The data pointed to by the pointer is constant and cannot be changed.
The pointer itself cannot change and point somewhere else.
```
int high_score {100};
int low_score {65};

const int *const score_ptr { &high_score};

*score_ptr = 86;		// OK
score_ptr = &low_score;	// ERROR
```

#### Passing Pointers to Functions
Pass-by-reference with pointers - defining the function
```
void double_data(int *int_ptr);

void double_data(int *int_ptr) {
	*int_ptr *=2;_
}
```
Pass-by-reference with pinters - calling the function
```
int main() {
	int value {10};
	
	cout << value << endl;		//10
	
	double_data( &value);
	
	cout << value << endl;		//20
}
```

#### Returning a Pointer from a Function
```
int *largest_int (int *int_ptr1, int *int_ptr2) {
	if (*int_ptr1 > *int_ptr2)
		return int_ptr1;
	else
		return int_ptr2;
}
```

#### What is a reference?
```
vector<string> stooges {"Larry", "Moe", "Curly"};
	
for (auto &str: stooges)
	str = "Funny";		// changes the actual

for (auto str:stooges)
	cout << str << endl;	// Funny, Funny, Funny
```

## Section 13: OOP - Classes and Objects
#### Declaring a Class and Creating Objects
```
class Player
{
	//attributes
	std::string name;
	int health;
	int xp;
	
	//methods
	void talk(std::string text_to_say);
	bool is_dead();
}
```
Creating objects
```
Account frank_account;
Account jim_account;

Account accounts[] {frank_account, jim_account};

std::vector<Account> accounts1 {frank_account};
accounts1.push_back(jim_account);
```
#### Accessing Class members
If we have a pointer to an object (member of pointer operator)
1) Dereference the pointer then use the dot operator
```
(*frank_account).balance;
(*frank_account).deposit(1000.00);
```
2) Or use the member of pointer operator (arrow operator)
```
Account *frank_account = new Account();

frank_account->balance;
frank_account->deposit(1000.00);
```
#### Public and Private
Declaring a Class
```
class Player
{
	private:
		std::string name;
		int health;
		int xp;
	public:
		void talk(std::string text_to_say);
		bool is_dead();_
}
```

#### Implementing Member Methods
Outside the class declaration
```
class Account {
	private:
		double balance;
	public:
		void set_balance(double bal);
		double get_balance();
};

void Account::set_balance(double bal) {
	balance = bal;
}

double Account::get_balance() {
	return balance;
}
```

Include Guards
```
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

// Class Definition

#endif
```

#### Consturctors
```
class Player
{
	private:
		std::string name;
		int health;
		int xp;
	public:
		//Overloaded Constructors
		Player();
		Player(std::string name);
		Player(std::string name, int health, int xp);
};
```

#### The Default Constructor
```
class Account
{
	private:
		std::string name;
		double balance;
	public:
		Account(std::string name_val, double bal) {
			name = name_val;
			balance = bal;
		}
		bool withdraw(double amount);
		bool deposit(double amount);
};
```

#### Constructor Initialization lists
```
Player::Player()
	: name{"None"}, health{0}, xp{0} {
	
	}
```

#### Delegating Constructors
```
Player::Player(std::string name_val, int health_val, int xp_val)
	: name{name_val}, health{health_val}, xpo{xp_val} {
	}

Player::Player()
	: Player {"None", 0, 0} {
	}
	
Player::Player(std::string name_val)
	: Player {name_val, 0, 0} {
	}
```

#### Copy Constructor
```
Account

Account::Account(const Account &source)
	: name{source.name}, balance {source.balance} {
	}
```

#### Shallow Copying with the Copy Constructor
```
class Shallow {
	private:
		int *data;						//POINTER
	public:
		Shallow(int d);					//Constructor
		Shallow(const Shallow &source);	//Copy
	Constructor
		~Shallow();						//Destructor
};

Shallow::Shallow(int d) {
	data = new int;						// Allocate storage
	*data = d;
}

Shallow::Shallow(const Shallow &source): data(source.data) {
	cout << "Copy constructor - shallow" << endl;
}
```

#### Deep Copying with the Copy Constructor
```
class Deep {
	private:
		int *data;					//Pointer
	public:
		Deep(int d);				// Constructor
		Deep(const Deep &source);	// Copy Constructor
		~Deep();					// Destructor
	
};

Deep::Deep(int d) {
	data = new int;				// Allocate storage
	*data = d;					
}

Deep::~Deep() {
	delete data;				// free storage
	cout << "Destructor freeing data"
}

Deep::Deep(const Deep &source) {
	data = new int;				// Allocate storage
	*data = *source.data;
	cout << "Copy constructor - deep" << endl;
	
}

OR
	
	Deep::Deep(const Deep &source) : Deep {*source.data} {
		cout << "Copy constructor - deep" << endl;
		
	}
```
	
#### Move Constructors
r-value references
```
int x {100}

int &l_ref = x; 				// l-value reference
l_ref = 10;						// change x to 10

int &&r_ref = 200;				// r-value reference
r_ref = 300;					// change r_ref to 300

int &&x_ref = x;				// Compiler error

```
l-value reference parameters
```
int x {100};					// x is an l-value

void func(int &num):			// A 

func(x);						// Calls A - x is an l-value
func(200);						// Error - 200 is an r-value
```
l-value reference parameters
```
int x {100};					// x is an l-value

void func(int &&num):			// B 

func(200);						// Calls B - 200 is an r-value
func(x);						// Error - x is an l-value
```
	
#### 'This' pointer
Contains the address of the object - so its a pointer to the object
Can only be used in class scope

#### Using const with Classes

#### Static Class Members

#### Struct vs Classes
Essentially the same as a class except members are public by default

#### Friends of a class
A function or class that has access to private class member

non-member function
```
class Player {
	friend void display_player(Player &p);
	std::string name;
	int health;
	int xp;
}

void display_player(Player &p) {
	std:cout << p.name << std:endl;
}
```
member function of another class
```
class Player {
	friend void Other_class::display_player(Player &p);
	std::string name;
	int health;
	int xp;
}
```
Another class
```
class Player {
	friend class Other_class);
	std::string name;
	int health;
	int xp;
}
```