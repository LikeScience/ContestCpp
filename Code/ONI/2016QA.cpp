#include <iostream>
#include <vector>

using namespace std;

int n, a, k, t = 0;
char c;
vector<int> rem;

int main() {
	cin >> n >> k;
	rem.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (c == 'M') {
			a++;
			rem[i + k]++;
		}
		else t += a;
		a -= rem[i];
	}
	cout << t << endl;
}
