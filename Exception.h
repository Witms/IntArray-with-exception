#pragma once
#include <exception>
using std::exception;


class BadRange : public exception {
public:
	virtual const char* what() const noexcept override;
};


class BadLength : public exception {
public:
	virtual const char* what() const noexcept override;
};

