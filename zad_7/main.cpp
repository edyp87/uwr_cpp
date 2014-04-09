#include "napis.h"


void testujKonstruktory() {
  std::cout<<"Testowanie konstruktorow:\n";
  Napis t1((std::string)"Napis t1"); std::cout<<"String: "<<t1<<"\n";
  Napis t2(t1); std::cout<<"Kopiujacy: "<<t2<<"\n";
  Napis t3((int)35); std::cout<<"Int: "<<t3<<"\n";
  Napis t4((char)'B'); std::cout<<"Char: "<<t4<<"\n";
  Napis t5((double)-56.899); std::cout<<"Double: "<<t5<<"\n";
  Napis t6((bool)true); std::cout<<"Bool: "<<t6<<"\n";
  std::string tmp = "Napis t7";
  std::string *ptr = &tmp;
  Napis t7((void *)ptr); std::cout<<"Void *: "<<t7<<"\n";
  std::cout<<"\n";
}


void testujOperatoryKonw() {
  std::cout<<"Testowanie operatorow konwertujacych:\n";
  Napis t1((std::string)"7878");
  int t1int = t1;
  std::cout<<"Konwersja na int: "<<t1int<<"\n";
  try {
    t1 = Napis((std::string)"87e83");
    int t1int = t1;
    std::cout<<"Konwersja na int: "<<t1int<<"\n";
  }
  catch(std::bad_cast) { std::cout<<"Rzucony bad_cast\n"; }

  Napis t2((bool)0);
  bool t2bool = t2;
  std::cout<<"Konwersja na bool: "<<t2bool<<"\n";

  Napis t3((char)'/');
  char t3char = t3;
  std::cout<<"Konwersja na char: "<<t3char<<"\n";

  Napis t4((double)0.3434);
  double t4dbl = t4;
  std::cout<<"Konwersja na double: "<<t4dbl<<"\n";

  std::string tmp = "Napis t5";
  std::string *ptr = &tmp;
  Napis t5((void *)ptr);
  void * t5void = t5;
  std::cout<<"Konwersja na void: "<<t5void<<"\n\n";
}


void testujOperacjeNaNapisach() {
  Napis i1((std::string)"0123456789");
  Napis i2((std::string)"4321");
  i1 += (double)3.14159;
  std::cout<<"i1 += (double)3.14159 : "<<i1<<"\n";
  i1 = Napis((std::string)"0123456789");
  i1.append(i2);
  std::cout<<"append : "<<i1<<"\n";
  i1 = Napis((std::string)"0123456789");
  i1.insert(i2, 6);
  std::cout<<"insert : "<<i1<<"\n";
  i1 = Napis((std::string)"0123456789");
  i1.erase(2, 7);
  std::cout<<"erase : "<<i1<<"\n";
  i1 = Napis((std::string)"0123456789");
  i1.replace(i2, 5);
  std::cout<<"replace : "<<i1<<"\n";
  i1 = Napis((std::string)"0123456789");
  i1 = i1.substr(3, 5);
  std::cout<<"substr : "<<i1<<"\n";

  Napis ps((std::string)"998");
  Napis pi((int)999);
  std::cout<<ps<<" <= "<<pi<<" = "<<(ps <= pi)<<"\n";
  std::cout<<ps<<" == "<<pi<<" = "<<(ps == pi)<<"\n";
}


int main() {

  testujKonstruktory();
  testujOperatoryKonw();
  testujOperacjeNaNapisach();
  return 0;
}
