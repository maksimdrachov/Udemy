# Embedded Programming Course
#### Lesson 6: Bit-wise operators in C
c = a | b; // OR
c = a & b; // AND
c = a ^ b; // XOR
c = ~b;	   // NOT
c = b >> 1;// right-shift
c = b << 3;// left-shift

Shifting: unsigned vs signed
instructions ASRS for right-shifting of signed numbers (Arithmetic right shift)
instructions LSRS for logical-right-shift of unsigned numbers (Logical right shift)

Updating a bit, without affecting rest of register
GPIO_PORTF_DATA_R = LED_BLUE;
GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R | LED_RED;	// long
GPIO_PORTF_DATA_R |= LED_RED;						// short

Clear a bit
GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R & ~LED_RED;	// long
GPIO_PORTF_DATA_R &= ~LED_RED;						// short

Setting multiple enable bits
GPIO_PORTF_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN);

#### Lesson 7: Arrays and Pointer Arithmetic
#### Lesson 8: Functions and the Stack