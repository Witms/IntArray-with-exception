#pragma once
#include <limits.h>


class IntArray {
private:
	int* _array{ nullptr };
	int _arrayLength{ 0 };
	int _fakeElement{ INT_MAX }; // Элемент который используется для исключений
public:
	IntArray() = default;
	IntArray(int arrayLength);
	IntArray(const IntArray& a);

	~IntArray();

	void erase(); // Создаёт нулевой контейнер

	int& operator[](int index); // Перегруженный оператор, который передаёт элемент контейнера

	int getLength() const; // Передаёт длину контейнера

	void reallocate(int newLength); // Изменяет размер контейнера без сохранения прежних элементов

	void resize(int newLength); // Изменяет размер контейнера с сохранением прежних элементов

	IntArray& operator=(const IntArray& a); // Перегруженный оператор, который изменяет контейнер, брав за основу другой и передаёт на него ссылку

	void insertBefore(int value, int index); // Вставляет элемент в контейнер по переданному индексу

	void remove(int index); // удаляет элемент в контейнере по переданному индексу

	void insertAtBeginning(int value); // Вставляет элемент в начало контейнера

	void insertAtEnd(int value); // Вставляет элемент в конец контейнера

	void search(int value) const; // Ищет элемент по значению и выводит на консоль его индекс
};
