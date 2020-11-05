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

## Section 14: Operator Overloading

#### Overloading the Assignment Operator (copy)
```
Mystring &Mystring::operator=(const Mystring &rhs) {
	// Check for self assignment
	if (this == &rhs)
		return *this;
	
	// Deallocate storage for this->str since we are overwriting it
	delete [] str;
	
	str = new char[std::strlen(rhs.str)+1];
	
	// Perform the copy
	std::strcpy(str, rhs.str);
	
	// Return the current by reference to allow chain assignment
	return *this;
}
```

#### Overloading the Assignment Operator (move)
```
Mystring &Mystring::operator=(Mystring &&rhs) {
	// Check for self assignment
	if (this == &rhs)
		return *this;
	
	// Deallocate current storage
	delete [] str;
	// Steal the pointer
	str = rhs.str;
	
	// Null out the rhs object
	rhs.str = nullptr;
	
	// Return current object
	return *this;
}
```

#### Overloading Operators as Member Functions
```
Mystring Mystring::operator-() const {
	char *buff = new char[std::strlen(str) + 1];
	std::strcpy(buff, str);
	for (size_t i=0; i<std::strlen(buff); i++)
		buff[i] = std::tolower(buff[i]);
	Mystring temp {buff};
	delete [] buff;
	return temp;
}
```
operator==
```
bool Mystring::operator==(const Mystring &rhs) const {
	if (std::strcmp(str, rhs.str) == 0)
		return true;
	else
		return false;
}
```
operator+ (concatenation)
```
Mystring Mystring::operator+(const Mystring &rhs) const {
	size_t buff_size = std::strlen(str) + std::strlen(rhs.str) + 1;
	char *buff = new char[buff_size];
	std::strcpy(buff, str);
	std::strcat(buff, rhs.str);
	Mystring temp {buff};
	delete [] buff;
	return temp;
}
```
#### Overloading Operators as Global Functions
Often declated as friend functions in the class declaration
```
Mystring operator- (const Mystring &obj) {
	char *buff = new char[std::strlen(obj.str) + 1];
	std::strcpy(buff, obj.str);
	for (size_t i=0; i<std::strlen(buff); i++)
		buff[i] = std::tolower(buff[i]);
	Mystring temp {buff};
	delete [] buff;
	return temp;
}
```
Operator==
```
bool operator==(const Mystring &lhs, const Mystring &rhs) {
	if (std::strcmp(lhs.str, rhs.str) == 0)
		return true;
	else
		return false;
}
```

#### Overloading the Stream Insertion and Extraction Operators
```
std::ostream &operator<<(std::ostream &os, const Mystring &obj) {
	os << obj.str;			// if friend function
	// os << obj.get_str()	// if not friend function
	return os;
}
```
stream extraction operator >>
```
std::isstream &operator>>(std::istream &is, Mystring &obj) {
	char *buff = new char[1000];
	is >> buff;
	obj = Mystring{buff};		// if you have copy or move assignment
	delete [] buff;
	return is;
}
```

## Section 15: Inheritance

#### Terminology and Notation
- Inheritance
	 Process of creating new classes from existing classes
	 Reuse mechanism
- Single inheritance
	A new class is created from another 'single' class
- Multiple inheritance
	A new class is created from two (or more) other classes
	
- "is-A" relationship
	Public inheritance
	Derived classes are sub-types of their Base classes
	Can use a derived class object wherever we use a base class object

- Generalization
	Combining similar classes into a single, more general class based on common attributes

- Specialization
	Creating new classes from existing classes providing more specialized attributes or operations
	
#### Inheritance and Composition
- Public inheritance
	"is-a" relationship
- Composition 
	"has-a" relationship
```
class Person {
private:
	std::string name;		// has-a name
	Account account;		// has-a account
}
```

#### Deriving Classes from Existing classes
```
class Base {
	// Base class members
}

class Derived: access-specified Base {
	// Derived class member
}

Access-specifier can be: public, private or protected
```

Types of inheritance in C++
- Public
	Most common
	Establishes 'is-a' relationship between Derived and Base classes
- private and protected
	Establishes "derived class has a base class" relationship
	"Is implemented in terms of" relationship
	Different from composition

#### Protected Members and Class Access
The protected class member modifier
- Accessible from the Base class itself
- Accessible from classes derived from base
- Not accessible by objects of base or derived

Access with public inheritance
- Public: accessible in derived class
- Protected: accessible in derived class
- Private: no access

Access with protected inheritance
- Public: becomes protected in derived class
- Protected: becomes protected in derived class
- Private: no access

Access with private inheritance
- Public: becomes private in derived class
- Protected: becomes private in derived class
- Private: no access

#### Constructors and Destructors
```
class Base {
	public:
		Base() { cout << "Base constructor" << endl;}
};

class Derived: public Base {
	public:
		Derived() { cout << "Derived constructor" << endl;}
};
```
A derived class does not inherit
	- Base class constructors
	- Base class destructor
	- Base class overloaded assignment operators
	- Base class friend functions
	
#### Passing Arguments to Base Class Constructors
```
class Base {
	public:
		Base();
		Base(int);
		...
}

Derived::Derived(int x): Base(x), {optional initializers for Derived} {
	// code
}
```
Constructors and class initialization
```
class Base {
	int value;
	
	public:
		Base(): value{0} {
			cout << "Base no-args constructor" << endl;
		}
		Base(int x): value{x} {
			cout << "int Base constructor" << endl;
		}
};

class Derived : public Base {
	int doubled_value;
	
public:
	Derived(): Base {}, doubled_value{0} {
		cout << "Derived no-args constructor" << endl;
	}
	Derived(int x) : Base{x}, doubled_value{x*2} {
		cout << "int Derived constructor" << endl;
	}
}
```

#### Copy/Move Constructors and Operator = with Derived Classes
Copy/Move constructors and overloaded operators=
	- Not inherited from the Base class
	- You may not need to provide your own
		- Compiler-provided versions may be just fine
	- We can explicitely invoke the base class versions from the derived class

Copy constructor
```
class Base {
	int value;
public:
	
	Base(const Base &other) : value{other.value} {
		cout << "Base copy constructor" << endl;
	}
};

class Derived : public Base {
	int doubled_value;
public:
	Derived(const Derived &other) : Base(other), doubled_value{other.doubled_value} {
		cout << "Derived copy constructor" << endl;
	}
}
```
operator=
```
class Base {
	int value;
public:
	Base &operator=(const Base &rhs) {
		if (this != &rhs) {
			value = rhs.value;	//assign
		}
		return *this;
	}
}

class Derived : public Base {
	int doubled_value;
public:
	Derived &operator=(const Derived &rhs) {
		if (this != &rhs) {
			Base::operator=(rhs);				// assign base part
			doubled_value = rhs.doubled_value 	// assign derived part
		} 
	}

}
```

#### Redefining Base Class Methods
Using and redefining Base class methods
```
class Account {
public:
	void deposit(double amount) { balance += amount; }
};

class Savings_Account: public Account {
public:
	void deposit(double amount) {	// Redefine Base class method
		amount += some_interest;	
		Account::deposit(amount);	// invoke call base class method
	}
}
```

#### Multiple inheritance
A derived class inherits from 2 or more Base classes at the same time
```
class Department_Chair: 
	public Faculty, public Administrator {
	
	};
```

#### 


