#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int matrixChainMultiplication(vector<int>& p, int n) {
 // m[i][j] stores the minimum number of
 // scalar multiplications needed to multiply
 // matrices Ai to Aj.
 vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));
 // Chain length
 for (int length = 2; length <= n; length++) {
 for (int i = 1; i <= n - length + 1; i++) {
 int j = i + length - 1;
 m[i][j] = INT_MAX;
 // Try every possible split
 for (int k = i; k < j; k++) {
 int cost = m[i][k]
 + m[k + 1][j]
 + p[i - 1] * p[k] * p[j];
 if (cost < m[i][j]) {
 m[i][j] = cost;
 }
 }
 }
 }
 return m[1][n];
}
int main() {
 int n;
 cout << "Enter number of matrices: ";
 cin >> n;
 vector<int> p(n + 1);
 cout << "Enter dimensions of matrices:\n";
 cout << "For example, for matrices:\n";
 cout << "A1 = 10x20, A2 = 20x30, A3 = 30x40\n";
 cout << "Enter: 10 20 30 40\n\n";
 for (int i = 0; i <= n; i++) {
 cin >> p[i];
 }
 int minimumCost = matrixChainMultiplication(p, n);
 cout << "\nMinimum number of scalar multiplications = "
 << minimumCost << endl;
 cout<<"kolusu uday kiran\n";
 cout<<"92460118175\n";
 cout<<"5-EN18\n";
 return 0;
}
