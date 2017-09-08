#include <queue>
#include <iostream>
using namespace std;

int main() {
	queue<int> Q1;
	Q1.push(1);
	Q1.push(2);
	Q1.push(3);

	cout << Q1.back() << " " << Q1.front() << endl;

	auto temp = 2;
	cout << temp << endl;
	return 0;
}