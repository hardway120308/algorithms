#include "bits/stdc++.h"

using namespace std;
int N;
int not_in_it[30];

void in(int n);

void out(int n) {
  if (not_in_it[n]) return;
  if (n==1) {
      not_in_it[n] = true;
      cout << "Move ring 1 out\n";
      return;
  }
  in(n-1);
  // remove ring 1 to n-2
  for (int i = n - 2; i >= 1;--i) {
      out(i);
  }

  // check if n-1 ring in THE PILLAR

  not_in_it[n] = true;
  cout << "Move ring " << n << " out\n";  
}

void in(int n) {
  if (!not_in_it[n]) return;
  if (n==1) {
    not_in_it[n] = false;
    cout << "Move ring 1 in\n";
    return;
  }

  in(n-1);

  // remove ring 1 to n-2
  for (int i = n-2;i>=1;--i) {
    out(i);
  }

  // check if ring n-1 in the pillar
  
  

  not_in_it[n]=false;
  cout << "Move ring " << n << " in\n";
}

signed main() {
  cin >> N;
  memset(not_in_it, 0, N);
  for(int i = N; i >= 1;i--) {
    out(i);
  }
  return 0;
}
