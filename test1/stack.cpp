class Stack {
	public : 
		Stack(int sz);	// Constructor : initialize variables, allocate space.
		~Stack();		// Destructor : deallocate space allocated above.
		void Push(int value);
		bool Full();	// Return TRUE if the stack is full, false otherwise
	private :
		int size;		// The maximum capacity of the stack.
		int top;		// Index of the the top of the stack
		int *stack;		// A pointer to an array that holds the contents.
};


void Stack::Push(int value) {
	ASSERT(!Full()); 	// stack should never overflow
	// ASSERT(!(this->Full()));
	stack[top++] = value;
}

bool Stack::Full() {
	return (top == 10);
}

Stack::Stack(int size) {
	size = sz;
	top = 0;
	stack = new int[size];
}

Stack::~Stack() {
	delete [] stack;
}


