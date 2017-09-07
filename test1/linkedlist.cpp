#include <iostream>
#include <limits>
using namespace std;

class node {
	public :
		int value;	// The value which node stores in.
		node *next;	// The node which a pointer in node points to.

		char aa;		// Exactly one byte in size. 8-bit
		char16_t a;		// At least 16-bits.
		char32_t b;		// At least 32-bits.
		wchar_t  c;		// Represent the largest supported character set.

		signed char d;	// At least 8-bits.
		signed short int e;	// At least 16-bits.
		signed int f;		// At least 16-bits.
		signed long int g;	// At least 32-bits.
		signed long long int h;	// At least 64-bits.

		unsigned char d2;
		unsigned short int e2;
		unsigned int f2;
		unsigned long int g2;
		unsigned long long int h2;

		float i;			
		double j;
		long double k;

		bool l;
		void m;
		decltype;



		node() {
			next = nullprt;
		}

		node(int store) {
			value = store;
			next = nullprt;
		}
}

