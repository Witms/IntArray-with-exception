#include <iostream>
#include "IntArray.h"
using namespace std;

int main() {

	IntArray a(3);
	IntArray b(-12);
	IntArray c(0);

	cout << a[-2] << " " << a[0] << " " << a[5] << endl;

	b.insertBefore(23, -2);
	b.insertBefore(10, 4);
	b.insertAtBeginning(5);

	cout << b[0] << endl;

	b.reallocate(5);

	IntArray d(b);

	d[2] = 65;

	cout << d[2] << endl;

	d.resize(7);

	cout << d[2] << endl;

	d.search(65);
	d.search(100);

	cout << d.getLength() << endl;

	d.insertAtEnd(48);

	c = d;

	c.search(48);
	c.remove(4);
	c.remove(20);

	return 0;
}