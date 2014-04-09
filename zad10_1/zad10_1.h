#ifndef ZAD10_1_H
#define ZAD10_1_H

#include <iostream>
#include <string>

// ----------------- manipulatory wejsciowe ------------------
std::istream & clearline(std::istream &in);
class ignore {
	public:
		ignore(int x) : number(x) {}
		std::istream & operator() (std::istream &in);
		friend std::istream & operator>> (std::istream &in, ignore ignoreObj);
	private:
	 int number;
};

// ----------------- manipulatory wyjsciowe ------------------
std::ostream & comma(std::ostream &out);
std::ostream & colon(std::ostream &out);
class index {
	public:
	 index(int x, int w) : number(x), pos(w) {};
	 std::ostream & operator() (std::ostream &out);
	 friend std::ostream & operator<< (std::ostream &out, index indexObj);
	public:
	 int number, pos;	
};

// ----------------- operatory strumieniowe ------------------
std::istream & operator>> (std::istream &in, ignore ignoreObj);
std::ostream & operator<< (std::ostream &out, index indexObj);

#endif //ZAD10_1_H