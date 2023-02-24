#include "IntArray.h"
#include "Exception.h"
#include <iostream>
using std::cout;
using std::endl;


IntArray::IntArray(int arrayLength) {
	try {
		if (arrayLength < 0) throw BadLength();
		_arrayLength = arrayLength;
		if (arrayLength > 0) _array = new int[_arrayLength] {};
	}
	catch (exception& e) {
		cout << e.what() << "Null container was created" << endl;
	}
}

IntArray::IntArray(const IntArray& a) {

	reallocate(a.getLength());

	for (int i = 0; i < _arrayLength; ++i) {
		_array[i] = a._array[i];
	}
}

IntArray::~IntArray() {
	delete[] _array;
}

void IntArray::erase() {
	delete[] _array;
	_array = nullptr;
	_arrayLength = 0;
}

int& IntArray::operator[](int index) {
	try {
		if (index < 0 || index >= _arrayLength) throw BadRange();
		return _array[index];
	}
	catch (exception& e) {
		cout << e.what() << "Reference to fake element was passed" << endl;
		return _fakeElement;
	}
}

int IntArray::getLength() const {
	return _arrayLength;
}

void IntArray::reallocate(int newLength) {

	erase();
	if (newLength == 0) return;

	try {
		if (newLength < 0) throw BadLength();
	}
	catch (exception& e) {
		cout << e.what() << "Container size was changed to null" << endl;
		return;
	}

	_array = new int[newLength];
	_arrayLength = newLength;
}

void IntArray::resize(int newLength) {

	if (newLength == _arrayLength) return;

	if (newLength <= 0) {
		erase();

		try {
			if (newLength < 0) throw BadLength();
		}
		catch (exception& e) {
			cout << e.what() << "Container size was changed to null" << endl;
		}

		return;
	}

	int* data = new int[newLength];

	if (_arrayLength > 0) {
		int elementsToCopy = (newLength > _arrayLength) ? _arrayLength : newLength;

		for (int i = 0; i < elementsToCopy; ++i) {
			data[i] = _array[i];
		}
	}

	delete[] _array;

	_array = data;
	_arrayLength = newLength;

}

IntArray& IntArray::operator=(const IntArray& a) {
	if (&a == this) return *this;

	reallocate(a.getLength());

	for (int i = 0; i < _arrayLength; ++i) {
		_array[i] = a._array[i];
	}

	return *this;
}

void IntArray::insertBefore(int value, int index) {
	
	try {
		if (index < 0 || index > _arrayLength) throw BadRange();
		int* data = new int[_arrayLength + 1];

		for (int i = 0; i < index; ++i) {
			data[i] = _array[i];
		}
		data[index] = value;

		for (int i = index; i < _arrayLength; ++i) {
			data[i + 1] = _array[i];
		}

		delete[] _array;
		_array = data;
		++_arrayLength;
	}
	catch (exception& e) {
		if (_arrayLength == 0) cout << "Null container. Only 0 index is suitable" << endl;
		else cout << e.what() << "Use a numbers from 0 to " << _arrayLength << endl;
	}

}

void IntArray::remove(int index) {
	try {
		if (index < 0 || index >= _arrayLength) throw BadRange();
		if (_arrayLength == 1) {
			erase();
			return;
		}

		int* data = new int[_arrayLength - 1];

		for (int i = 0; i < index; ++i) {
			data[i] = _array[i];
		}

		for (int i = index + 1; i < _arrayLength; ++i) {
			data[i - 1] = _array[i];
		}

		delete[] _array;
		_array = data;
		--_arrayLength;
	}
	catch (exception& e) {
		if (_arrayLength == 0) cout << "Null container" << endl;
		else if (_arrayLength == 1) cout << "Container has the only one element with index 0" << endl;
		else cout << e.what() << "Use a numbers from 0 to " << _arrayLength - 1 << endl;
	}
}

void IntArray::insertAtBeginning(int value) {
	insertBefore(value, 0);
}

void IntArray::insertAtEnd(int value) {
	insertBefore(value, _arrayLength);
}

void IntArray::search(int value) const {
	for (int i = 0; i < _arrayLength; ++i) {
		if (value == _array[i]) {
			cout << "Element index = " << i << endl;
			return;
		}
	}
	cout << "Suitable element was not found" << endl;
}