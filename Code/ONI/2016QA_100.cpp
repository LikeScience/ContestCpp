#include <iostream>
#include <vector>

using namespace std;

int n, a = 0, k, t = 0;
char c;
vector<int> rem;

int main() {
	cin >> n >> k;
	rem.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (c == 'M') {
			a++;
			i(i+k < n) rem[i + k]++;
		}
		else t += a;
		a -= rem[i];
	}
	cout << t << endl;
}
