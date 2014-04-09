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
Pr�d przemienny  jest to pr�d zmienny 
(czyli o zmiennej warto�ci nat�enia 
w czasie) oraz okresowy, tzn. funkcja 
warto�ci nat�enia jest okresowa, 
ma okre�lon� cz�stotliwo��. Zazwyczaj 
warto�� �rednia nat�enia z jednego 
okresu jest r�wna zero. W Polsce 
u�ywa si� pr�du przemiennego o 
przebiegu sinusoidalnym, cz�stotliwo�ci 
50 [Hz] oraz napi�ciu skutecznym 230 [V].
Warto�� maksymalna napi�cia lub nat�enia, 
to maksymalna warto��, kt�r� osi�ga 
� odpowiednio � napi�cie lub nat�enie. 
Warto�� skuteczna nat�enia jest 
to warto�� pr�du sta�ego, kt�r� w ci�gu 
czasu r�wnego okresowi pr�du przemiennego 
spowoduje ten sam efekt cieplny, co dany 
sygna� pr�du przemiennego. 

*/