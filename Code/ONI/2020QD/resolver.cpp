#include "avaliador.h"
#include <iostream>
#include <vector>
#include <random>

using namespace std;

int _N, p, P, tmp, idx;
vector<int> v;

void swap (int a, int b) {
	tmp = v[a];
	v[a] = v[b];
	v[b] = tmp;
	return;
}

int part(int l, int r){
	//cout << "bs"<< endl;
	swap(p, r);
	//cout << l << "l" << p << "r" << r << endl;
	idx = l;
	for (int i = l; i < r; i++) if (testar(v[r], v[i])) {
		//cout << v[r] << "v" << v[i] << endl;
		swap(i, idx);
		idx++;
	}
	swap(idx, r);
	//cout << "huhuhu" << endl;
	return idx;
}

int median (int l, int r, int k) {
	//cout << l << "r" << r << "k" << k << endl;
	//random
	random_device rd;
	default_random_engine e( rd() );
 	p = l + e() % (r-l+1);
	//cout << "p" << p << endl;
	P = part(l, r);
	if (k == P) {return P;}
	else if (k < P) {/*cout << l << "P" << P-1 << endl;*/ if (l > P-1) return 0; return median(l, P - 1, k);}
	else {/*cout << r << "p" << P+1 << endl; */ if (r < P + 1) return 0; return median(P + 1, r, k);}
}

int escolher(int N)
{
	//cout << "1" << endl;
	_N = N;
	for (int i = 1; i <= N; i++) v.push_back(i);
	int x = median(0, _N-1, N/2);
	//cout << v[x] << "M" << endl;
	return v[x];
}

/*int main() {
	srand( (unsigned)time(NULL) );
	cin >> _N;
	cout << rand() % _N << endl;
	return 0;
}*/