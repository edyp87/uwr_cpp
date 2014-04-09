#include "plikWejsciowy.h"

plikWejsciowy::plikWejsciowy(const char *name) throw (std::ios_base::failure) {
	
	file.open(name);
	//file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	if(!file.is_open()) throw std::ios_base::failure("Cannot open the file (IN)");
}

plikWejsciowy::~plikWejsciowy() {
	if(file.is_open()) file.close();
}

std::istream & operator>> (plikWejsciowy &in, std::string &str) throw(std::ios_base::failure) {
	std::getline(in.file, str, '\n');
	return in.file;
}

std::istream & operator>> (plikWejsciowy &in, char &ch) throw (std::ios_base::failure) {
	in.file >> ch;
	return in.file;
}

std::istream & operator>> (plikWejsciowy &in, int &number) throw (std::ios_base::failure) {
	in.file >> number;
	return in.file;
}

std::istream & operator>> (plikWejsciowy &in, double &number) throw (std::ios_base::failure) {
	in.file >> number;
	return in.file;
}