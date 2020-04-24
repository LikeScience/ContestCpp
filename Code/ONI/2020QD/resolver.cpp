//#include "avaliador.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int _N, p;

int median (int l, int r, int k) {
	p = rand() % (r - l + 1);
}

int escolher(int N)
{
	srand( (unsigned)time(NULL) );
	_N = N;
	for (int i = 1; i <= N; i++) v.push_back(i);
	return median(0, _N-1, N/2);
}

/*int main() {
	srand( (unsigned)time(NULL) );
	cin >> _N;
	cout << rand() % _N << endl;
	return 0;
}*/