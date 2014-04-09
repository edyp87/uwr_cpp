#ifndef PLIK_WEJSCIOWY_H
#define PLIK_WEJSCIOWY_H

#include <iostream>
#include <string>
#include <fstream>
#include <exception>

class plikWejsciowy {
	public:
	 plikWejsciowy(const char *name)  throw (std::ios_base::failure);
	 ~plikWejsciowy();

	 inline bool eof() const { return file.eof(); }

	 friend std::istream & operator>> (plikWejsciowy &in, std::string &str) throw (std::ios_base::failure);
	 friend std::istream & operator>> (plikWejsciowy &in, char &ch) throw (std::ios_base::failure); 
     friend std::istream & operator>> (plikWejsciowy &in, int &number)  throw (std::ios_base::failure); 
	 friend std::istream & operator>> (plikWejsciowy &in,  double &number) throw (std::ios_base::failure); 
	private:
	 std::ifstream file;
};


#endif //PLIK_WEJSCIOWY_H