#include <iostream>
#include <vector>
#include <random>
#include <utility>

using namespace std;

int m, n, p, q;
double entry, mini, c;
pair<int, int> pivot;
vector<double> empty;
vector<vector<double> > table, oldtab;

void choose_pivot(){
	vector<int> negative_columns;
	for (int i = 1; i <= n; i++) {
		if (table[m+1][i] < 0) negative_columns.push_back(i);
	}
	if ((int)negative_columns.size() = 0) {
		p = -1; q = -1;
		return;
	}
	
	return;
}

int main() {
	
	//criar tabela com os valores introduzidos;
	cin >> m >> n;
	empty.assign(n + 2, 0);
	table.assign(m + 2, 0);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; i <= n; j++) {
			cin >> entry;
			table[i][j] = entry;
		}	
	}
	
	//tornar todos os valores positivos;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; i <= n; j++) {
			if (mini > table[i][j]) mini = table[i][j];
		}	
	}
	if (mini <= 0) {
		c = 1 - mini;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; i <= n; j++) {
				table[i][j] += c;
			}	
		}
	}
	
	//colocar as "bordas" a tabela
	for (int i = 1; i <= n; i++) {
		table[0][i] = i;
		table[m+1][i] = -1;
	}
	for (int i = 1; i <= m; i++) {
		table[i][0] = -i;
		table[i][n+1] = 1;
	}
	
	//Loop - escolher pivot, "pivotear" a tabela e alterar a primeira linha e coluna.
	while (1){
		choose_pivot();
		if (p == -1 && q == -1) break;
		
	}
	
}