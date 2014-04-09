#include "zad10_1.h"

// ----------------- manipulatory wejsciowe ------------------

std::istream & clearline(std::istream &in) {
	while(in && in.get() != '\n') {}
	return in;
}

std::istream & ignore::operator() (std::istream &in) {
	while(number-- && in && in.get() != '\n') {}
	return in;
}

// ----------------- manipulatory wyjsciowe ------------------

std::ostream & comma(std::ostream &out) {
	return out << ", ";
}

std::ostream & colon(std::ostream &out) {
	return out << ": ";
}

std::ostream & index::operator() (std::ostream &out){
	int tmp = number;
	std::string spaces = "";
	if(number < 0) pos--;

	while(tmp != 0) { tmp /= 10; pos--; }
	while(pos > 0)  { pos--; spaces += " "; }

	return out << "[" << spaces << number << "]";
}

// ---------------- operatory strumieniowe -------------------

std::istream & operator>> (std::istream &in, ignore ignoreObj) {
	
	return ignoreObj(in);
}

std::ostream & operator<< (std::ostream &out, index indexObj) {

	return indexObj(out);
}