#include "plikWejsciowy.h"
#include "plikWyjsciowy.h"
#include <vector>
#include <algorithm>
using namespace std;

vector<double> t;

int main() {
	try {
		plikWejsciowy plik("niema");
	} catch(ios_base::failure e) {cout << e.what() << endl; }

	try {
		
		plikWejsciowy plik("test");
		plikWyjsciowy plik2("wyn");
		//getchar();
		try {
			double x;
			while(!plik.eof()) { plik >> x; t.push_back(x); }
		}
		catch(ios_base::failure e) { cout << e.what() << endl; }

		try {
			for(int i = t.size() - 2; i >= 0; i--) {
				cout << t[i] << '\n';
				plik2 << t[i] << '\n';
			}
		}
		catch(ios_base::failure e) { cout << e.what() << endl; }
	}
	catch(ios_base::failure e) { cout << e.what() << endl; }
	getchar();
	return 0;
}
