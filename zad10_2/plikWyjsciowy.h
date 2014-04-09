#ifndef PLIK_WYJSCIOWY_H
#define PLIK_WYJSCIOWY_H

#include <iostream>
#include <string>
#include <fstream>
#include <exception>

class plikWyjsciowy {
	public:
	 plikWyjsciowy(const char *name)  throw (std::ios_base::failure);
	 ~plikWyjsciowy();

	 inline bool eof() const { return file.eof(); }

	 friend std::ostream & operator<< (plikWyjsciowy &out, std::string &str) throw (std::ios_base::failure);
	 friend std::ostream & operator<< (plikWyjsciowy &out, char &ch) throw (std::ios_base::failure); 
     friend std::ostream & operator<< (plikWyjsciowy &out, int &number)  throw (std::ios_base::failure); 
	 friend std::ostream & operator<< (plikWyjsciowy &out,  double &number) throw (std::ios_base::failure);
	private:
	 std::ofstream file;
};


#endif //PLIK_WYJSCIOWY_H