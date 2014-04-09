#include "plikWyjsciowy.h"

plikWyjsciowy::plikWyjsciowy(const char *name) throw (std::ios_base::failure) {
	
	file.open(name);
	//file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	if(!file.is_open()) throw std::ios_base::failure("Cannot open the file (OUT)");
}

plikWyjsciowy::~plikWyjsciowy() {
	if(file.is_open()) file.close();
}

std::ostream & operator<< (plikWyjsciowy &out, std::string &str) throw(std::ios_base::failure) {
	out.file << str << '\n';
	return out.file;
}

std::ostream & operator<< (plikWyjsciowy &out, char &ch) throw (std::ios_base::failure) {
	out.file << ch;
	return out.file;
}

std::ostream & operator<< (plikWyjsciowy &out, int &number) throw (std::ios_base::failure) {
	out.file << number;
	return out.file;
}

std::ostream & operator<< (plikWyjsciowy &out, double &number) throw (std::ios_base::failure) {
	out.file << number;
	return out.file;
}