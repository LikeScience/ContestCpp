#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "avaliador.h"

using namespace std;

bool correct = false;
int n, q, contador;
int robots[MAXN], found[MAXN];

void end(int type = 0) {
  if (correct)
    cout << "Correto! Usaste " << contador << " testes." << endl;
  else {
    if (type == 0)
      cout << "Incorreto, usaste testes a mais..." << endl;
    else if (type == 1)
      cout << "Incorreto, input invalido..." << endl;
    else if (type == 2)
      cout << "Incorreto, comparacao fora dos limites..." << endl;
    else
      cout << "Incorreto, devolveste a resposta errada ..." << endl;
  }
  exit(0);
}

int testar(int p1, int p2) {
  if (p1 < 1 || p1 > MAXN || p2 < 1 || p2 > MAXN)
    end(2);
  contador++;
  if (robots[p1 - 1] > robots[p2 - 1])
    return 1;
  return 0;
}

int main() {
  cin >> n >> q;

  if (n < 1 || n > MAXN || n % 2 != 1)
    end(1);

  if (q < 1 || q > MAXQ)
    end(1);

  for (int i = 0; i < n; i++)
    cin >> robots[i];

  for (int i = 0; i < n; i++)
    if (robots[i] < 1 || robots[i] > n)
      end(1);

  memset(found, 0, sizeof found);
  for (int i = 0; i < n; i++) {
    if (found[robots[i]])
      end(1);
    found[robots[i]] = 1;
  }

  int resposta = -1;
  for (int i = 0; i < n; i++)
    if (robots[i] == (n + 1) / 2)
      resposta = i + 1;

  contador = 0;
  if (escolher(n) != resposta)
    end(3);
  
  correct = (contador <= q);
  end();

  return 0;
}