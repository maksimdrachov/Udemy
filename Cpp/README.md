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

## Section 15: Polymorphism
Runtime polymorphism: Being able to assign different meanings to the same function at run-time

Not the default in C++, run-time polymorphism is achieved via
- Inheritance
- Base class pointers or references
- virtual functions

#### Using a Base Class Pointer
```
Account *p1 = new Account();
Account *p2 = new Savings();
Account *p3 = new Checking();
Account *p4 = new Trust();

p1->withdraw(1000);			// Account::withdraw
p2->withdraw(1000); 		// Savings::withdraw
p3->withdraw(1000);			// Checking::withdraw
p4->withdraw(1000); 		// Trust::withdraw
```
With vector
```
Account *p1 = new Account();
Account *p2 = new Savings();
Account *p3 = new Checking();
Account *p4 = new Trust();

vector<Account *> accounts {p1, p2, p3, p4};

for (auto acc_ptr: accounts)
	acc_ptr->withdraw();
```

#### Virtual Functions
Virtual functions
- Redefined functions are bound statistically
- Overridden functions are bound dynamically
- Virtual functions are overridden
- Allow us to treat all objects generally as objects of the base class

Declaring virtual functions
- Declare the funtions you want to override as virtual in the base class
- Virtual functions are virtual all the way down the hierarchy from this point
- Dynamic polymorpism only via account class pointer or reference

```
class Account {
public:
	virtual void withdraw(double amount);
};

class Checking : public Account {
public:
	virtual void withdraw(double amount);
};
```

#### Virtual Destructors
Virtual Destructors
- Problems can happen when we destroy polymorphic objects
- If a derived class is destroyed by deleting its storage via the base class pointer
- Derived objects must be destroyed in the correct order starting at the correct destructor

- Solution/rule:
	- If a class has virtual functions
	- ALWAYS provide a public virtual destructor
	- If base class destructor is virtual then all derived class destructors are also virtual
	
```
class Account {
public:
	virtual void withdraw(double amount);
	virtual ~Account();
}
```

#### Using the Override Specifier
```
class Base {
public:
	virtual void say_hello() const {
		...
	}
	virtual ~Base() {}
};

class Derived: public Base {
public:
	virtual void say_hello() override {	// Produces compiler error
										// Error: marked override but does not override
	} 
	virtual ~Derived() {}
};
```

#### Using the Final Specifier
- When used at the class level
- Prevents a class from being derived from

- When used at the method level
- Prevents virtual method from being overridden in derived classes

final class
```
class My_class final {
	...
};

class Derived final: public Base {
	...
};
```

final method
```
class A {
public:
	virtual void do_something();
};

class B: public A {
	virtual void do_something() final; 	// prevent further overriding
};

class C: public B {
	virtual void do_something();		// COMPILER ERROR - can't override
}
```

#### Using Base class references

- We can use base class references with dynamic polymorphism
- Useful when we pass objects to functions that expect a base class reference

```
Account a;
Account &ref = a;
ref.withdraw(1000);		// Account::withdraw

Trust t;
Account &red1 = t;
ref1.withdraw(1000);	// Trust::withdraw

```

## Pure Virtual Functions and Abstract Classes
Abstract class
- Cannot instantiate objects
- These classes are used as base classes in inheritance hierarchies
- Often referred to as "abstract base classes"

Concrete class
- Used to instantiate objects from
- All their member functions are defined

Pure virtual funtion
- Used to make a class abstract
- Specified with "=0" in its declaration
- Typically do not provide implementations

- Derived classes must override the base class
- If the derived class does not override then the derived class is also abstract
- Used when it doesn't make sense for a base class to have an implementation -> but concrete classes must implement it

```
class Shape {			// Abstract
private:
	// attributes common to all shapes
public:
	virtual void draw() = 0;	// pure virtual function
	virtual void rotate() = 0;	// pure virtual function
	virtual ~Shape();
}

class Circle: public Shape {		// Concrete
private:
	// attributes for a circle
public:
	virtual void draw() override {
		// code to draw a circle
	}
	virtual void rotate() override {
		// code to rotate a circle
	}
	virtual ~Circle();
	...
}
```

Abstract base class
- Cannot be instantiated
- We can use pointers and references to dynamically refer to concrete class derived from them
```
Shape *ptr = new Circle();
ptr->draw();
ptr->rotate();
```

#### Abstract Classes as Interfaces
- C++ does not provide true interfaces
- We use abstract classes and pure virtual functions to achieve it
- Suppose we want to provide Printable support for any object we wish without knowing it's implementation at compile time
```
std::cout << any_object << std::endl;
```

An Printable example
```
class Printable {
	friend ostream &operator<<(ostream &, const Printable &obj);
public:
	virtual void print(ostream &os) const = 0;
	virtual ~Printable() {};
};

ostream &operator<<(ostream &os, const Printable &obj) {
	obj.print(os);
	return os;
};

class Any_Class: public Printable {
public:
	// Must override Printable::print()
	virtual void print(ostream *os) override {
		os << "Hi, from Any_class";
	}
};
```

A Shapes example
```
class I_Shape {
public:
	virtual void draw() = 0;
	virtual void rotate() = 0;
	virtual ~I_Shape() {};
};

class Circle : public I_Shape {
public:
	virtual void draw() override {
	};
	virtual void rotate() override {
	};
	virtual ~Circle() {};

};


vector <I_Shape *> shapes;

I_Shape *p1 = new Circle();
I_Shape *p2 = new Line();
I_Shape *p3 = new Square();

for (auto const &shape: shapes) {
	shape->rotate();
	shape->draw();
};
```

## Section 17: Smart Pointers
What are they?
- Objects
- Can only point to heap-allocated memory
- Automatically call delete when no longer needed
- C++ Smart pointers
	- Unique pointers
	- Shared pointers
	- Weak pointers
- #include <memory>
- Defined by class templates
	- Wrapper around a raw pointer
	- Overloaded operators
		- Dereference (*)
		- Member selection (->)
		- Pointer arithmetic not supported (++, --, etc)
	- Can have curtom deleters

RAII - Resource Acquisition is Initialization
- Common idiom or pattern used in software design based on container object lifetime
- RAII objects are allocated on the stack
- Resource Acquisition
	- Open a file
	- Allocate memory
	- Acquire a lock
- Is Initialization
	- The resource is acquired in a constructor
- Resource relinquishing
	- Happens in the destructor
	
#### Unique pointers
unique_ptr
- Simple smart pointer - very efficient

unique_ptr<T>
- Points to an object of type T on the heap
- It is unique - there can only be one unique_ptr<T> pointing to the object on the heap
- Owns what it points to
- Cannot be assigned or copied
- Can be moved
- When the pointer is destroyed, what it points to is automatically destroyed

```
{
std::unique_ptr<int> p1 {new int {100}};

std::cout << *p1 << std::endl;		//100

*p1 = 200;

std::cout << *p1 << std::endl;		//200

} // Automatically deleted
```

unique_ptr - used defined class
{
std::unique_ptr<Account> p1 {new Account{"Larry"}};

std::cout << *p1 << std::endl;	//display account

p1->deposit(1000);
p1->withdraw(500);

}	// Automatically deleted

unique_ptr - vectors and move

{
std::vector<std::unique_ptr<int>> vec;

std::unique_ptr<int> ptr {new int(100)};

vec.push_back(ptr);		// Error - copy not allowed

vec.push_back(std::move(ptr));
}		// automatically deleted

unique_ptr - make unique
{
std::unique_ptr<int> p1 = make_unique<int>(100);

std::unique_ptr<Account> p2 = make_unique<Account>("Curly", 5000);

auto p3 = make_unique<Player>("Hero", 100, 100);
}	// automatically deleted + (more efficient, no calls to new or delete)

#### Shared pointers
shared_ptr
- Provides shared ownership of heap objects

shared_ptr<T>
- Points to an object of type T on the heap
- It is not unique - there can be many shared_ptrs pointing to the same object on the heap
- Establishes shared ownership relationship
- can be assigned and copied
- can be moved
- doesn't support managing arrays by default
- when the use count is zero, the managed object on the heap is destroyed

shared_ptr - creating, initializing and using
```
{
std::shared_ptr<int> p1 {new int {100}};

std::cout << *p1 << std::endl;		// 100

*p1 = 200;

std::cout << *p1 << std::endl;		// 200
}	// Automatically deleted
```

shared_ptr - some other useful methods
```
{
// use_count - the number of shared_ptr objects managing the heap object
std::shared_ptr<int> p1 {new int {100}};
std::cout << p1.use_count() << std::endl;		// 1

std::shared_ptr<int> p2 {p1};
std::cout << p1.use_count() << std::endl;		// 2

p1.reset();			// decrement the use_count; p1 is nulled out
std::cout << p1.use_count() << std::endl;		// 1
std::cout << p2.use_count() << std::endl;		// 2

} // Automatically deleted
```

shared_ptr - used defined classes
```
{
std::shared_ptr<Account> p1 {new Account{"Larry"}};
std::cout << *p1 <<std::endl;		// display account

p1->deposit(1000);
p1->withdraw(1000);
}		// Automatically deleted
```

shared_ptr - vectors and move
```
{
std::vector<std::shared_ptr<int>> vec;
std::shared_ptr<int> ptr {new int{100}};

vec.push_back(ptr);		// OK - copy is allowed

std::cout << ptr.use_count() << std::endl;	// 2
}
```
shared_ptr - make_shared
```
{
std::shared_ptr<int> p1 = make_shared<int>(100);	// use_count = 1
std::shared_ptr<int> p2 {p1};						// use_count = 2
std::shared_ptr<int> p3;
p3 = p1												// use_count = 3
} // Automatically deleted
```
- Use make_shared - it's more efficient
- All 3 pointers point to the same object on the heap
- When the use_count becomes 0 the heap object is deallocated

#### Weak pointers
weak_ptr
- provides a non-owning "weak" reference

weak_ptr<T>
- points to an object of type T on the heap
- does not participate in owning relationship
- always created from a shared_ptr
- does not increment or decrement reference use count
- used to prevent strong reference cycles which could prevent objects from being deleted

weak_ptr - circular or cyclic reference
- A refers to B
- B refers to A
- Shared strong ownership prevents heap deallocation

- Solution : make one of the pointers non-owning or weak
- Now heap storage is deallocated properly

#### Custom deleters
- Sometimes when we destroy a smart pointer we need to do more than to just destroy the object on the heap
- These are special use-cases
- C++ smart pointers allow you to provide custom deleters
- Different ways to achieve this:
	- Functions
	- Lambdas
	- ...

custom deleters - function
```
void my_deleter(Some_Class *raw_pointer) {
	// your custom deleter code
	delete raw_pointer;
}

shared_ptr<Some_Class> ptr {new Some_class{}, my_deleter};
```

## Section 18: Exception Handling

#### Basic Concepts and a Simple Example: Dividing by zero
What causes exceptions?
- insufficient resources
- missing resources
- invalid operations
- range violations
- underflows and overflows
- illegal data and many others

Exception safe: when your code handles exceptions

- throw
	- throws an exception
	- followed by an argument
- try { code that may throw an exception}
	- you place code that may throw an exception in a try block
	- if the code throws an exception the try block is exited
	- the thrown exception is handled by a catch handler
	- if no catch handler exists the program terminates
- catch(Exception ex) { code to handle the exception}
	- code that handles the exception
	- can have multiple catch handlers
	- may or may not cause the program to terminate

Divide by zero example
```
double average {};
try {
	if (total == 0)
		throw 0;
	average = sum / total;
}
catch (int &ex) {
	std::cerr << "can't divide by zero" << std::endl;
}
std::cout << "program continues" << std::endl;
```

#### Throwing an Exception from a function
Throwing an exception from a function
```
double calculate_avg(int sum, int total) {
	if (total == 0)
		throw 0;
	return static_cast<double>(sum)/total;
}

double average {};

try {
	average = calculate_avg(sum, total);
	std::cout << average << std::endl;
}

catch (int &ex) {
	std::cerr << "You can't divide by zero" << std::endl;
}
```

#### Handling Multiple Exceptions
```
double calculate_mpg(int miles, int gallons) {
	if (gallons == 0)
		throw 0;
	if (miles < 0 || gallons < 0)
		throw std::string{"Negative value error"};
		
	return static_cast<double>(miles) / gallons;
}

double miles_per_gallon {};
try {
	miles_per_gallon = calculate_mpg(miles, gallons);
	std::cout << miles_per_gallon << std::endl;
}
catch (int &ex) {
	std::cerr << "You can't divide by zero" << std::endl;
}
catch (std::string &ex) {
	std::cerr << ex << std::endl;
}

std::cout << "Bye" << std::endl;
```

Catching any type of exception
```
catch (int &ex) {
	
}
catch (std::string &ex) {
	
}
catch(...) {
	std::cerr << "Unknown exception" << std::endl;
}
```

#### Stack Unwinding and How it Works
If an exception is thrown but not caught in the current scope
C++ tries to find a handler for the exception by unwinding the stack

#### Creating User-defined Exception classes
we can create exception classes and throw instances of those classes

Best practice:
- throw an object not a primitive type
- throw an object by value
- catch an object by reference (or const reference)

```
class DivideByZeroException {
};

class NegativeValueException {
};

double calculate_mpg(int miles, int gallons) {
	if (gallons = 0)
		throw DivideByZeroException();
	if (miles < 0 || gallons < 0)
		throw NegativeValueException();
		
	return static_cast<double>(miles) / gallons;
}

try {
	miles_per_gallon = calculate_mpg(miles, gallons);
	std::cout << miles_per_gallon << std::endl;
}
catch (const DivideByZeroException &ex) {
	std::cerr << "You can't divide by zero" << std::endl;
}
catch (const NegativeValueException &ex) {
	std::cerr << "NEgative values aren't allowed" << std::endl;
}

std::cout << "Bye" << std::endl;
```

#### Class Level Exceptions
Exceptions can also be thrown from within a class
- Method
	- These work the same way as they do for function as we've seen
- Constructor
	- Constructors may fail
	- Cosntructors do not return any value
	- Throw an exception in the cosntructor if you cannot initialize an object
- Destructor
	- Do NOT throw exceptions from your destructor
	
```
Account::Account(std::string name, double balance) : name{name}, balance{balance} {
	if (balance < 0.0)
		throw IllegalBalanceException{};
}
try {
	std::unique_ptr<Account> moes_account = std::make_unique<Checking_Account>("Moe", -10.0);
}
catch (const IllegalBalanceException &ex) {
	std::cerr << "Couldn't create account" << std::endl;
}
```
#### The C++ std::exception class hierarchy
C++ provides a class hierarchy of exception classes
	- std::exception is the base class
	- all subclasses implement the what() virtual function
	- we can create our own user-defined exception subclasses

Deriving our class from std::exception
```
class IllegalBalanceException: public std::exception
{
public:
	IllegalBalanceException() noexcept = default;
	~IllegalBalanceException() = default;
	virtual const char* what() const noexcept {
		return "Illegal balance exception";
	}
}

Account::Account(std::string name, double balance): name{name}, balance{balance} {
	if (balance < 0.0)
		throw IllegalBalanceException{};
}

try {
	std::unique_ptr<Account> moes_account = std::make_unique<Checking_Account>("Moe", -100.0);
	
	std::cout << "Use moes_account" << std::endl;
}

catch (const IllegalBalanceException &ex) {
	std::cerr << ex.what() << std::endl;
}
```

## Section 19: IO and Streams
| Header file  	| Description |
| ------------- | ------------- |
| iostream		| Provides definitions for formatted input and output from/to streams  |
| fstream  		| Provides definitions for formatted inputs and output from/to file streams  |
| iomanip  		| Provides definitions for manipulators used to format stream IO  |

Commonly used stream classes
|Class					| Description			|
| -------------------	| ------------------- 	|
| ios							| Provides basic support for fomatted and unformatted IO operations.				|
| ifstream						| Provides for high-level input operations on file based streams					|
| ofstream						| Provides for high-level output operations on file based stream					|
| fstream						| Provides for high-level IO operations on file based systems						|
| stringstream					| Provides for high-level IO operations on memory based strings						|

Global stream objects
| Object 	| Description		|
| -------- 	| ---------- |
| cin		| Standard input stream - by default 'connected' to the standard input device (keyboard)		|
| cout		| Standard output stream - by default 'connected' to the standard output device (console)		|
| cerr		| Standard error stream - by default 'connected' to the standard error device (console)			|
| clog		| Standard log stream - by default 'connected' to the standard log device (console)				|

#### Stream Manipulators
- Boolean:
	- boolalpha, noboolalpha
- Integer:
	- dec, hex, showbase, noshowbase, showpos, noshowpos, uppercase, nouppercase
- Floating point
	- fixed, scientific, setprecision, showpoint, noshowpoint, showpos, noshowpos
- Field width, justification, fill
	- setw, left, right, internal, setfill
- Others
	- endl, flush, skipws, noskipws, ws
	
#### Stream Manipulators: boolean
```
std::cout << std::boolalpha;	// 1 or 0
std::cout << std::noboolalpha;	// true or false
```	
Reset to default
```
std::cout << std::resetiosflags(std::ios::boolalpha);
```

#### Stream Manipulators: integers
```
int num {255};

std::cout << std::dec << num << std::endl;
std::cout << std::hex << num << std::endl;
std::cout << std::oct << num << std::endl;

// Will display
255
ff
377
```

```
int num {255};

std::cout << std::showbase;		// std::noshowbase
std::cout << std::dec << num << std::endl;
std::cout << std::hex << num << std::endl;
std::cout << std::oct << num << std::endl;

// Will display
255
0xff	// Note the 0x prefix for hexadecimal
0377	// Note the 0 prefix for octal
```

```
int num {255};

std::cout << num << std::endl;	// 255

std::cout << std::showpos;		//std::noshowpos

std::cout << num << std::endl;	// +255
```

#### Stream Manipulators - floating point
```
double num {1234.5678};

std::cout << num << std::endl;

// Will display

1234.57	// Notice precision is 6 and rounding
```

```
double num {123456789.123456789};

std::cout << num << std::endl;

// Will display

1.23457e+008	// Notice precision is 6 
```

```
double num {123456789.123456789};

std::cout << std::setprecision(9);
std::cout << num << std::endl;

// Will display

1.2345790	// Note that rounding occurs
```

```
double num {123456789.123456789};

std::cout << std::fixed;
std::cout << num << std::endl;

// Will display precision 6 from the decimal

123456789.987654
```

```
double num {123456789.123456789};

std::cout << std::setprecision(3) << std::fixed;
std::cout << num << std::endl;

// Will display precision 3 from the decimal

123456789.988
```

```
double num {123456789.123456789};

std::cout << std::setprecision(3) << std::scientific << std::uppercase;
std::cout << num << std::endl;

// Will always display precision 3

1.23E+008	// Note the capital E
```

#### Stream Manipulators: align and fill
Default when displaying floating point values:
- setw - not set by default
- left - when no field width, right - when using field width
- fill - not set by default - blank space is used

```
double num {1234.5678};
std::string hello{"Hello"};

std::cout 	<< std::setfill('*');
std::cout 	<< std::setw(10) << num
			<< std::setfill("-") << std::setw(10) << hello
			<< std::setw(15) << hello
			<< std::endl;
			
// Will display
1234567890123456789012345678901234567890
***1234.57-----Hello----------Hello
```

#### Reading from a Text file
fstream and ifstream are commonly used for input files
1. #include <fstream>
2. Declare an fstream or ifstream object
3. Connect it to a file on your file system (opens it for reading)
4. Read data from the file via the stream
5. Close the stream

Opening a file for reading with (fstream)
```
std::fstream in_file {"../myfile.txt", std::ios::in};
```

Open for reading in binary mode
```
std::fstream in_file {"../myfile.txt", std::ios::in | std::ios::binary};
```

```
std::ifstream in_file;
std::string filename;
std::cin >> filename;

in_file.open(filename);
```

Check if file opened succesfully (is_open)
```
if (in_file) {
	// read from it
} else {
	// file could not be opened
}
```

Closing a file: always close any open files to flush out any unwritten data
```
in_file.close();
```

Reading from files using (>>)
```
int num {};
double total {};
std::string name {};

in_file >> num;
in_file >> total >> name;
```

Reading from files using getline
```
std::string line{};

std::getline(in_file, line);
```

Reading text file one line at a time
```
std::ifstream in_file{"../myfile.txt"};		// open file
std::string line (};

if (!in_file) {
	std::cerr << "File open error" << std::endl;
	return 1;		// exit the program (main)
}

while (!in_file.eof()) {			// while not at the end
	std::getline(in_file, line);	// read a line
	cout << line << std::endl;		// display the line
}
in_file.close();	// close the file
```

Reading text file one character at a time (get)
```
std::ifstream in_file{"../myfile.txt"};	// open file
char c;

if (!in_file) {		// check if file is open
	std::cerr << "File open error" << std::endl;
	return 1;
}
while (in_file.get(c))	// read a character
	cout << c;			// display the character

in_file.close();		// close the file
```

#### Writing to a Text file
fstream and ofstream are commonly used for output files
1. #include <fstream>
2. Declare an fstream or ofstream object
3. Connect it to a file on your file system
4. Write data to the file via the stream
5. Close the stream

Opening a file for writing with (fstream)
```
std::fstream out_file {"../myfile.txt", std::ios::out};
```
Open for writing in binary mode
```
std::fstream out_file {"../myfile.txt", std::ios::out | std::ios::binary};
```

Opening a file for writing with (ofstream)
```
std::ofstream out_file {"../myfile.txt", std::ios::out};

std::ofstream out_file {"../myfile.txt"};
```
Open for writing in binary mode
```
std::ofstream out_file {"../myfile.txt", std::ios::binary};
```

Opening a file for writing with (ofstream)
```
// truncate (discard contents) when opening
std::ofstream out_file {"../myfile.txt", std::ios::trunc};

// append on each write
std::ofstream out_file {"../myfile.txt", std::ios::app};

// seek to end of stream when opening
std::ofstream out_file {"../myfile.txt", std::ios::ate};
```

Opening a file for writing with open
```
std::ofstream out_file;
std::string filename;
std::cin >> filename;	// get the file name

out_file.open(filename);
// or
out_file.open(filename, std::ios::binary);
```

Check if file opened succesfully (is_open)
```
if (out_file.is_open()) {
	// read from it
} else {
	// file could not be created of opened
}
```

Always close any open files to flush out any unwritten data
```
out_file.close();
```

Writing to files using (<<)
```
int num {100};
double total {255.67};
std::string name {"Larry"};

out_file 	<< num << "\n"
			<< total << "\n"
			<< name << std::endl;
```

Copying a text file one line at a time
```
std::ifstream in_file{"../myfile.txt"};	// open file
std::ofstream out_file{"../copy.txt"}; 

if (!in_file) {
	std::cerr << "File open error" << std::endl;
	return 1;	// exit the program
}
if (!out_file) {
	std::cerr << "File create error" << std::endl;
	return 1;	// exit the program
}

std::string line {};

while (std::getline(in_file, line))	// read a line
	out_file << line << std::endl;

in_file.close();
out_file.close();
```

Copying a text file one character at a time (get/put)
```
std::ifstream in_file{"../myfile.txt"};
std::ofstream out_file{"../copy.txt"};

if (!in_file) {
	std::cerr << "File open error" << std::endl;
	return 1;
}
if (!out_file) {
	std::cerr << "Fome create error" << std::endl;
	return 1;
}

char c;

while (in_file.get(c))
	out_file.put(c);

in_file.close();
out_file.close();
```

#### Using String Streams
stringstream, istringstream and ostringstream
1. #include <sstream>
2. Declare an stringstream, istringstream or ostringstream object
3. Connect it to a std::string
4. Read/write data from/to the string stream using formatted IO

Reading from a stringstream
```
#include <sstream>

int num {};
double total {};
std::string name {};
std::string info {"Moe 100 1234.5"};

std::istringstream iss{info};
iss >> name >> num >> total;
```

Writing to a stringstream
```
#include <sstream>
int num {100};
double total {1234.5};
std::string name {"Moe"};

std::ostringstream oss {};
oss << name << " " << num << " " << total;
std::cout << oss.str() << std::endl;
```

Validating input with stringstream
```
int value {};
std::string input {};

std::cout << "Enter an integer: ";
std::cin >> input;

std::stringstream ss{input};
if (ss >> value) {
	std::cout << "An integer was entered";
else
	std::cout << "An integer was NOT entered";
}
```

## Section 20: The Standard Template Library 
#### What is the STL?
- Containers
	- Collections of objects of primitive types 
	- (array, vector, deque, stack, set, map,...)
- Algorithms
	- Functions for processing sequences of elements from containers 
	- (find, mac, count, accumulate, sort, ...)
- Iterators
	- Generate sequences of elements from containers
	- (forward, reverse, by value, by reference, constant, ...)

A simple example - sort a vector
```
std::sort(v.begin(), v.end());
```
A simple example - reverse a vector
```
std::reverse(v.begin(), v.end());
```
A simple example - accumulate
```
sum = std::accumulate(v.begin(), v.end(), 0);
```

Types of Containers
- Sequence containers
	- array, vector, list, forward_list, deque
- Associative containers
	- set, multi set, map, multi map
- Container adapters
	- stack, queue, priority queue
	
Types of Iterators
- Input iterators - from the container to the program
- Output iterators - from the program to the container
- Forward iterators - navigate one item at a time in one direction
- Bi-directional iterators - navigate one item at a time both directions
- Random access iterators - directly access a container item

Types of Algorithms 
- About 60 algorithms
- Non-modifying
- Modyfying

#### Generic Programming with Macros
- Generic programming
	"Writing code that works with a variety of types as arguments,
	 as as those argument types meet specific syntactic and semantic requirements"
- Macros***beware!***
- Function templates
- Class templates

Macros (#define)
- C++ preprocessor directives
- No type information
- Simple substitution
```
#define MAX_SIZE 100
#define PI 3.14159
```

```
#define MAX(a,b) ((a > b) ? a:b)

std::cout << MAX(10,20)	<< std::endl;	// 20
std::cout << MAX(2.4,3.5)	<< std::endl;	// 3.5
std::cout << MAX('A','C')	<< std::endl;	// C
```

#### Generic Programming with Function Templates
What is a C++ Template?
- Blueprint
- Function and class templates
- Allow plugging-in any data type
- Compiler generates the appropriate function/class from the blueprint
- Generic programming/meta-programming

max function as a template function
- we can replace type we want to generalize with a name, say T
- we need to tell the compiler this is a template function
- we also need to tell it that T is the template parameter
```
template <typename T>
T max(T a, T b) {
	return (a>b) ? a:b;
}
```

- Now the compiler can generate the appropriate function from the template
- Note: this happens at compile-time
```
int a {10};
int b {20};

std::cout << max<int>(a,b);
```
- Many times the compiler can deduce the type and the template parameter is not needed
- Depending on the type of a and b, the compiler will figure it out
```
std::cout << max<double>(c,d)
std::cout << max(c,d)
```
- Note the type MUST support the > operator either natively or as an overloaded operator

#### Generic Programming with Class Templates
What is a C++ class template
- Similar to function template, but at the class level
- Allows plugging-in any data type
- Compiler generates the appropriate class from the blueprint

```
template <typename T>
	class Item {
	private:
		std::string name;
		T value;
	public:
		Item(std::string name, T value): name {name}, value{value}
		{}
		std::string get_name() const {return name;}
		T get_value() const { return value; }
	};
	
Item<int> item1 {"Larry", 1};
Item<double> item2 {"House", 1000.0};
Item<std::string> item3 {"Frank", "Boss"};
std::vector<Item<int>> vec;
```

std::pair
```
#include <utility>
std::pair<std::string, int> p1 {"Frank", 100};

std::cout << p1.first;	// Frank
std::cout << p1.second;	// 100
```

#### Introduction to STL Containers
Data structures that can store objects of almost any type
- Template-based classes
- Each container has member functions
	- Some are specific to the containers
	- Others are available to all containers
- Each container has an associated header file
	- #include <container_type>

| Function  | Description |
| ------------- | ------------- |
| Default constructor  		| Initializes empty container  |
| Overloaded constructor  	| Initializes container with many options |
| Copy constructor  		| Initializes a container as a copy of another container |
| Move constructor  		| Moves existing container to new container |
| Destructor  				| Destroys a container |
| Copy assignment  			| Copy one container to another |
| Move assignment  			| Move one container to another |
| size  					| Returns the number of elements in the container |
| empty  					| Returns boolean - is the container empty |
| insert  					| Insert an element into the container |
| operator< and operator <= | Returns boolean - compare contents of 2 containers |
| operator> and operator>=  | Returns boolean - compare contents of 2 containers |
| operator== and operator!= | Returns boolean - are the contents of 2 containers equale or not |
| swap  					| Swap the elements of 2 containers |
| erase  					| Remove elements from a container |
| clear  					| Remove all elements from a container |
| begin and end  			| Returns iterators to first element or end |
| rbegin and rend  			| Returns reverse iterators to first element or end |
| cbegin and cend  			| Returns constant iterators to first element or end |
| crbegin and crend  		| Returns constant reverse iterators to first element or end |

What types of elements can we store in containers?
- A copy of the element will be stores in the container
- Element should be 
	- copyable and assignable 
	- Moveable for efficiency 
- Ordered associative containers must be able to compare elements
	- operator<, operator==
	
#### Introduction to STL Iterators
Iterators
- Allows abstracting an arbitrary container as a sequence of elements
- They are objects that work like pointers by design
- Most container classes can be traversed with iterators

Iterators must be declared based on the container type they will iterate over
```
std::vector<int>::iterator it1;
std::list<std::string>::iterator it2;
std::map<std::string, std::string>::iterator it3;
std::set<char>::iterator it4;
```

Initializing iterators
```
std::vector<int>::iterator it = vec.begin();
or
auto it = vec.begin();
```

Using iterators
```
std::vector<int> vec {1,2,3};
std::vector<int>::iterator it = vec.begin();
while (it != vec.end()) {
	std::cout << *it << " ";
	++it;
}
// 1 2 3
```

```
for (auto it = vec.begin(); it != vec.end(); it++) {
	std::cout << *it " ";
}
// 1 2 3
```

Reverse iterators
- works in reverse
- last element is the first and first is the last
- ++ moves backward, -- moves forward
```
std::vector<int>::reverse_iterator it = vec.begin();
while (it != vec.end()) {
	std::cout << *it << " ";
	++it;
}
// 3 2 1
```

#### Introduction to STL Algorithms
- STL algorithms work on sequences of container elements provided to them by an iterator
- see cppreference/algorithm
- #include <algorithm>

find
The find algorithm tries to locate the first occurence of an element in a container
Returns an iterator pointing to the located element or end()
```
auto loc = std::find(vec.begin(), vec.end(), 3);

if (loc != vec.end())
	std::cout << *loc << std::endl;
```

find with user-defined types
- operator== is used and must be provided by your class
```
Player p {"Hero", 100, 12};

auto loc = std::find(team.begin(), team.end(), p);

if (loc != vec.end())
	std::cout << *loc << std::endl;
```

for_each
- for_each algorithm applies a function to each element in the iterator sequence
- Function must be provided to the algorithm as
	- Functor (function object)
	- Function pointer
	- Lambda expression

for_each - using a functor
```
struct Square_Functor {
	void operator() (int x) {	// overload () operator
		std::cout << x*x << " ";
		}
};
Square_Functor square;	// Function object

std::vector<int> vec {1, 2, 3, 4};

std::for_each(vec.begin(), vec.end(), square);
// 1 4 9 16
```

for_each - using a function pointer
```
void square(int x) {
	std::cout << x*x << " ";
}

std::vector<int> vec {1, 2, 3, 4};

std::for_each(vec.begin(), vec.end(), square);
// 1 4 9 16
```

for_each - using a lambda expression
```
std::vector<int> vec {1, 2, 3, 4};

std::for_each(vec.begin(), vec.end(), [] (int x) {std::cout << x*x << " ";})
// 1 4 9 16 
```

#### Sequence Container - Array
- Fixed size
- Direct element access
- Provides access to the underlying raw array
- Use instead of raw arrays when possible
- All iterators available and do not invalidate

std::array - initialization and assignment
```
std::array<int, 5> arr1 { {1,2,3,4,5} };

std::array<std::string, 3> stooges {std::string{"Larry"}, "Moe", std::string("Curly")};

arr1 = {2,4,6,8,10};
```

std::array - common methods
```
std::array<int, 5> arr {1,2,3,4,5};
std::cout << arr.size();			// 5
std::cout << arr.at(0);				// 1
std::cout << arr[1];
std::cout << arr.front();			// 1
std::cout << arr.back();			// 5
```

std::array - common methods
```
std::array<int, 5> arr {1,2,3,4,5};
std::array<int, 5> arr1 {10,20,30,40,50};

std::cout << arr.empty();		// 0
std::cout <<.max_size();		// 5

std::cout << arr.fill(10);		// fills all to 0
arr.swap(arr1);					// swap the 2 arrays
int *data = arr.data();			// get raw array address
```

#### Sequence Containers - Vector
std::vector
#include <vector>
- Dynamic size
	- Handled automatically
	- Can expand and contract as needed
	- Elements are stored in contigious memory as an array
- Direct element access
- Rapid insertion and deletion at the back
- Insertion or removal of elements (linear time)
- All iterators available and may invalidate

std::vector - initialization and assignment
```
std::vector<int> vec {1,2,3,4,5};
std::vector<int> vec1 (10,100); // ten 100s

std::vector<std::string> stooges {
	std::string("Larry"),
	"Moe",
	std::string("Curly")	
};

vec1 = {2,4,6,8,10};
```

```
Person p1 {"Larry", 18};
std::vector<Person> vec;

vec.push_back(p1);		// add p1 to the back
vec.pop_back();			// remove p1 from the back

vec.push_back(Person{"Larry", 18});

vec.emplace_back("Larry", 18);		// efficient
```

std::vector - common methods
```
std::vector<int> vec1 {1,2,3,4,5};
std::vector<int> vec2 {10,20,30,40,50};

auto it = std::find(vec1.begin(), vec1.end(), 3);
vec1.insert(it, 10);	// 1,2,10,3,4,5

it = std::find(vec.begin(), vec1.end(), 4);
std::insert(it, vec2.begin(), vec2.end());	// 1,2,3,10,20,30,40,50,4,5

vec1.reserve(100);	// reserves memory for 100 entries
```

#### Sequence Containers - Deque
std::deque (double ended queue)
#include <deque>
- Dynamic size
	- Handled automatically
	- Can expand and contract as needed
	- Elements are not stored in contigious memory
- Direct element access (constant time)
- Rapid insertion and deletion at the front and back
- Insertion or removal of elements
- All iterators available and may invalidate

std::deque - initialization and assignment
```
std::deque<int> d {1,2,3,4,5};
std::deque<int> d1(10,100);

std::deque<std::string> stooges {
	std::string("Larry"),
	"Moe",
	std::string("Curly")
};

d = {2,4,6,8,10};
```

std::deque - common methods
```
std::deque<int> d {1,2,3,4,5};

std::cout << d.size();		// 5
std::cout << d.max_size;	// a very large number

std::cout << d.at(0); 		// 1
std::cout << d[1];			// 2

std::cout << d.front();		// 1
std::cout << d.back();		// 5
```

```
Person p1 {"Larry", 18};
std::deque<Person> d;

d.push_back(p1);			// add p1 to the back
d.pop_back();				// remove p1 from the back

d.push_front(Person{"Larry", 18});
d.pop_front();				// remove element from the front

d.emplace_back("Larry", 18);	// add to back efficient
d.emplace_front("Moe", 24);	// add to front
```

```
std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
std:deque<int> d;

std::copy(vec.begin(), vec.end(), std::front_inserter(d));
display(d);	// 10,9,8,7,6,5,4,3,2,1

std::copy(vec.begin(), vec.end(), std::front_inserter(d));
display(d);	// 10,9,8,7,6,5,4,3,2,1
```

#### Sequence Containers - List and Forward List
std::list
#include <list>
- Dynamic size
	- Lists of elements
	- list is bidirectional (doubly-linked)
- Direct element access is not provided
- Rapid insertion and deletion of elements anywhere in the container
- All iterators available and invalidate when corresponding element is deleted

std::list - initialization and assignment
```
std::list<int> l {1,2,3,4,5};
std::list<int> ll (10,100):	// ten 100s

std::list<std::string> stooges {
	std::string("Larry"),
	"Moe",
	std::string("Curly")
};

l = {2,4,6,8,10};
```

std::list - methods that use iterators
```
std::list<int> l {1,2,3,4,5};
auto it = std::find(l.begin(), l.end(), 3);
l.insert(it, 10);		// 1 2 10 3 4 5
l.erase(it);			// erases the 3, 1 2 10 4 5
l.resize(2);			// 1 2
l.resize(5);			// 1 2 0 0 0
```
traversing the list (bi-directional)
```
std::list<int> l {1,2,3,4,5};
auto it = std::find(l.begin(), l.end(), 3);

std::cout << *it;		// 3
it++;
std::cout << *it		// 4
it--
std::cout << *it		// 3
```

std::forward_list
#include <forward_list>
- Dynamic size
	- Lists of elements
	- list uni-directional (singly-linked)
	- less overhead than a std::list
- Direct element access is not provided
- Rapid insertion and deletion of elements anywhere in the container
- Reverse iterators not available. Iterators invalidate when corresponding element is deleted

std::forward_list - common methods
```
std::forward_list<int> {1,2,3,4,5};

std::cout << l.size();	// not available
std::cout << l.max_size;		// a very large number

std::cout << l.front();			// 1
std::cout << l.back();			// not available
```

```
Person p1 {"Larry", 18};
std::forward_list<Person> l;
l.push_front(p1);		// add p1 to the front
l.pop_front();			// remove p1 from the front

l.emplace_front("Moe", 24);		// add to the front
```

std::forward_list - methods that use iterators
```
std::forward_list<int> l {1,2,3,4,5};
auto it = std::find(l.begin(), l.end(), 3);
l.insert_after(it, 10);		// 1 2 3 10 4 5
l.emplace_after(100);		// 1 2 3 100 10 4 5

l.erase_after(it);			// erases the 100, 1 2 3 10 4 5

l.resize(2);				// 1 2

l.resize(5);				// 1 2 0 0 0 
```

#### Associative containers - Sets










