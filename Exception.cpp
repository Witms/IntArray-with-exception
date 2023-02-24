#include "Exception.h"


const char* BadRange::what() const noexcept {
	return "Error: bad range. ";
}


const char* BadLength::what() const noexcept {
	return "Error: bad length. ";
}