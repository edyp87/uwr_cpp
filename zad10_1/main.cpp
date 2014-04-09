#include "zad10_1.h"
#include <vector>
#include <algorithm> //sort()
using namespace std;

bool comp(pair<int, string> a, pair<int, string> b) {
	if(a.second < b.second) return true;
	if(a.second == b.second && a.first <= b.first) return true;
	return false;
}


vector< pair<int, string> > t;

int main() {
	int ind = 0, maxPos = 0;
	string a;

	cin >> clearline >> ignore(5);

	while(getline(cin, a, '\n') ) {
		t.push_back(make_pair(++ind, a));
	}
	for(int tmp = ind; tmp > 0; tmp /= 10) maxPos++;

	sort(t.begin(), t.end(), comp);

	cout << endl << "Test manipulatorow wyjsciowych + sortowanie" << endl;
	for(int i = 0; i < ind; i++)
		 cout <<index(t[i].first, maxPos) << colon << t[i].second << comma << endl;
	getchar();

	
	return 0;
}












/*
Pr¹d przemienny  jest to pr¹d zmienny 
(czyli o zmiennej wartoœci natê¿enia 
w czasie) oraz okresowy, tzn. funkcja 
wartoœci natê¿enia jest okresowa, 
ma okreœlon¹ czêstotliwoœæ. Zazwyczaj 
wartoœæ œrednia natê¿enia z jednego 
okresu jest równa zero. W Polsce 
u¿ywa siê pr¹du przemiennego o 
przebiegu sinusoidalnym, czêstotliwoœci 
50 [Hz] oraz napiêciu skutecznym 230 [V].
Wartoœæ maksymalna napiêcia lub natê¿enia, 
to maksymalna wartoœæ, któr¹ osi¹ga 
– odpowiednio – napiêcie lub natê¿enie. 
Wartoœæ skuteczna natê¿enia jest 
to wartoœæ pr¹du sta³ego, któr¹ w ci¹gu 
czasu równego okresowi pr¹du przemiennego 
spowoduje ten sam efekt cieplny, co dany 
sygna³ pr¹du przemiennego. 

*/