#include "napis.h"

Napis::Napis(std::string x) {
    war = x;
}

Napis::Napis(const Napis &np) {
    war = np.war;
}

Napis::Napis(int x) {
    std::string tmp = "";
    if(x < 0) {
        war += "-";
        x = -x;
    }
    do {
        tmp += x % 10 + '0';
        x /= 10;
    } while (x != 0);

    for(int i = tmp.length() - 1; i >= 0; i--)
        war += tmp[i];
}

Napis::Napis(bool x) {
    if(x == true) war = "1";
    else war = "0";
}

Napis::Napis(char x) {
    war += x;
}

Napis::Napis(double x) {
    std::ostringstream tmp;
    tmp << x;
    war = tmp.str();
}

Napis::Napis(void *x) {
    war = *(std::string *) x;
}

Napis::~Napis() {
}

Napis & Napis::operator = (const Napis &np) {
    this->war = np.war;
    return *this;
}

Napis & Napis::operator += (const Napis &np) {
    this->war += np.war;
    return *this;
}

Napis::operator std::string() const {
    return war;
}

Napis::operator int() const {
    int tmp = 0, i = 0;
    bool uj = false;
    if(war.length() != 0 && war[i] == '-') {
        if(war.length() == 1) throw std::bad_cast();
        uj = true;
        i++;
    }
    for(; i < war.length(); i++) {
        if(war[i] >= '0' && war[i] <= '9') {
            tmp *= 10;
            tmp += war[i] - '0';
        }
        else throw std::bad_cast();
    }
    return (!uj ? tmp : -tmp);
}

Napis::operator bool() const {
    double tmp = *this;
    return (bool) tmp;
}

Napis::operator char() const {
    if(war.length() != 1) throw std::bad_cast();
    return war[0];
}

Napis::operator double() const {
	double wyn = 0, tmp = 1;
	int i = 0;
	bool uj = false;
	if(war.length() != 0 && war[i] == '-') {
		if(war.length() == 1) throw std::bad_cast();
		uj = true;
		i++;
	}
	for(; i < war.length(); i++) {
		if(war[i] == '.') break;
		if(war[i] >= '0' && war[i] <= '9') {  
			wyn *= 10;
			wyn += (double)(war[i] - '0');
		}
		else throw std::bad_cast();
	}
	for(i = i+1; i < war.length(); i++) {
		if(war[i] >= '0' && war[i] <= '9') { 
			tmp *= 10;
			wyn += (double)(war[i] - '0') / tmp;
		}
		else throw std::bad_cast();
	}
	return (!uj ? wyn : -wyn);
}

Napis::operator void *() {
    return (void *) &war;
}

int Napis::length() const {
    return war.length();
}

void Napis::append(const Napis &a) {
    war += a.war;
}

void Napis::insert(const Napis &a, int pos) {
    if(pos > length()) throw "Zla pozycja.";
    std::string tmp = "";
    for(int i = 0; i < pos; i++) tmp += war[i];
    for(int i = 0; i < a.length(); i++) tmp += a[i];
    for(int i = pos; i < length(); i++) tmp += war[i];
    war = tmp;
}

void Napis::erase(int spos, int epos) {
    if(spos < 0 || epos >= length() || epos < spos)
        throw "Zla pozycja.";
    std::string tmp = "";
    for(int i = 0; i < spos; i++) tmp += war[i];
    for(int i = epos + 1; i < length(); i++) tmp += war[i];
    war = tmp;
}

void Napis::replace(const Napis &a, int pos) {
    if(pos > length()) throw "Zla pozycja";
    std::string tmp = "";
    for(int i = 0; i < pos; i++) tmp += war[i];
    for(int i = 0; i < a.length(); i++) tmp += a[i];
    for(int i = a.length() + pos; i < length(); i++) tmp += war[i];
    war = tmp;
}

Napis Napis::substr (int pos, int n) {
    if(pos > length() || pos + n > length())
        throw "Zla pozycja.";
    std::string tmp = "";
    for(int i = pos; i < pos + n; i++) tmp += war[i];
    return tmp;
}

Napis operator + (Napis &a, Napis &b) {
    std::string tmp = a.war + b.war;
    return Napis(tmp);
}

bool operator < (const Napis &a, const Napis &b) {
  return (a.war < b.war);
}

bool operator <= (const Napis &a, const Napis &b) {
  return (a.war <= b.war);
}

bool operator == (const Napis &a, const Napis &b) {
  return (a.war == b.war);
}

bool operator >(const Napis &a, const Napis &b) {
  return (a.war > b.war);
}

bool operator >= (const Napis &a, const Napis &b) {
  return (a.war >= b.war);
}

bool operator != (const Napis &a, const Napis &b) {
  return (a.war != b.war);
}

std::ostream & operator << (std::ostream &wy, const Napis &np) {
  std::cout<<np.war;
  return wy;
}
