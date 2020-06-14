#include <iostream>
#include <vector>
#include <random>
#include <utility>

using namespace std;

int m, n, p, q;
double entry, mini, c, r, newr;
pair<int, int> pivot;
vector<double> empty, horizontal_output, vertical_output;
vector<vector<double> > table, oldtab;

void choose_pivot(){
	random_device rd;
	mt19937 mt(rd());
	vector<int> negative_columns;
	for (int i = 1; i <= n; i++) {
		if (table[m+1][i] < 0) negative_columns.push_back(i);
	}
	if ((int)negative_columns.size() == 0) {
		p = -1; q = -1;
		return;
	}
	uniform_int_distribution<int> dist(0, (int)negative_columns.size() - 1);
	while(1) { //escolher pivot
		bool b = 0;
		q = negative_columns[dist(rd)]; //escolher coluna do pivot
		for (int i = 1; i <= m; i++) {
			if (table[i][q] > 0){
				if (!b) {
					b = 1;
					r = table[i][n+1] / table[i][q];
					p = i; //escolher linha do pivot:
				}
				else {
					newr = table[i][n+1] / table[i][q];
					if (newr < r) {
						r = newr;
						p = i; //escolher linha do pivot
					}
				}
			} 
		}
		if (b) break; 
	}
	return;
}

int main() {
	
	//criar tabela com os valores introduzidos;
	cin >> m >> n;
	empty.assign(n + 2, 0.0);
	table.assign(m + 2, empty);
	cout << m << " i " << n << endl;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cout << i << "P0" << j << endl;
			cin >> entry;
			table[i][j] = entry;
		}	
	}
	cout << "P1" << endl;
	
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
	cout << "P2" << endl;
	
	//colocar as "bordas" a tabela
	for (int i = 1; i <= n; i++) {
		table[0][i] = double(i);
		table[m+1][i] = -1.0;
	}
	for (int i = 1; i <= m; i++) {
		table[i][0] = double(-i);
		table[i][n+1] = 1.0;
	}
	cout << "P3" << endl;
	
	//Loop - escolher pivot, "pivotear" a tabela e alterar a primeira linha e coluna.
	while (1){
		choose_pivot();
		if (p == -1 && q == -1) break; //se nao houver numeros negativos, far-se-a print do resultado
		
		//pivotear os elementos
		oldtab = table;
		for (int i = 1; i <= m+1; i++) {
			for (int j = 1; i <= n+1; j++) {
				if (i == p) {
					if (j == q) {
						table[i][j] = 1 / oldtab[i][j];
					}
					else {
						table[i][j] = oldtab[i][j] / oldtab[p][q];
					}
				}
				else {
					if (j == q) {
						table[i][j] = - oldtab[i][j] / oldtab[p][q];
					}
					else {
						table[i][j] = oldtab[i][j] - (oldtab[i][q] * oldtab[p][j] /oldtab[p][q]);
					}
				}
			}
		}
	cout << "P4" << endl;
		
		//trocar os números na primeira linha e coluna correspondentes ao pivot
		table[0][q] = oldtab[p][0];
		table[p][0] = oldtab[0][q];
	cout << "P5" << endl;
		
	}
	
	//print do resultado
	horizontal_output.assign(m, 0.0);
	vertical_output.assign(n, 0.0);
	cout << "Valor do jogo = " << c + 1/table[m+1][n+1] << endl;
	cout << "Estratégia otimal do jogador horizontal:";	for (int i = 1; i <= n; i++) {
		if(table[0][i] < 0.0) horizontal_output[i-1] = table[m+1][i]/table[m+1][n+1];
	}
	for (int i = 0; i < m; i++) cout << " " << horizontal_output[i];
	cout << endl;
	cout << "Estratégia otimal do jogador vertital:";
	for (int i = 1; i <= m; i++) {
		if(table[i][0] > 0.0) vertical_output[i-1] = table[i][n+1]/table[m+1][n+1];
	}
	for (int i = 0; i < n; i++) cout << " " << vertical_output[i];
	cout << endl;
	
}
