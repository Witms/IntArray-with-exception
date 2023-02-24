#pragma once
#include <limits.h>


class IntArray {
private:
	int* _array{ nullptr };
	int _arrayLength{ 0 };
	int _fakeElement{ INT_MAX }; // ������� ������� ������������ ��� ����������
public:
	IntArray() = default;
	IntArray(int arrayLength);
	IntArray(const IntArray& a);

	~IntArray();

	void erase(); // ������ ������� ���������

	int& operator[](int index); // ������������� ��������, ������� ������� ������� ����������

	int getLength() const; // ������� ����� ����������

	void reallocate(int newLength); // �������� ������ ���������� ��� ���������� ������� ���������

	void resize(int newLength); // �������� ������ ���������� � ����������� ������� ���������

	IntArray& operator=(const IntArray& a); // ������������� ��������, ������� �������� ���������, ���� �� ������ ������ � ������� �� ���� ������

	void insertBefore(int value, int index); // ��������� ������� � ��������� �� ����������� �������

	void remove(int index); // ������� ������� � ���������� �� ����������� �������

	void insertAtBeginning(int value); // ��������� ������� � ������ ����������

	void insertAtEnd(int value); // ��������� ������� � ����� ����������

	void search(int value) const; // ���� ������� �� �������� � ������� �� ������� ��� ������
};
