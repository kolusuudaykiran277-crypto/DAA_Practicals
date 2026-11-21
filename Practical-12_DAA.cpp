#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int main() {
 int n;
 cout << "Enter number of cities: ";
 cin >> n;
 int cost[10][10];
 cout << "Enter cost matrix:\n";
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 cin >> cost[i][j];
 }
 }
 int path[10], bestPath[10];
 for (int i = 0; i < n - 1; i++)
 path[i] = i + 1;
 int minCost = INT_MAX;
 do {
 int currentCost = cost[0][path[0]];
 for (int i = 0; i < n - 2; i++)
 currentCost += cost[path[i]][path[i + 1]];
 currentCost += cost[path[n - 2]][0];
 if (currentCost < minCost) {
 minCost = currentCost;
 bestPath[0] = 0;
 for (int i = 0; i < n - 1; i++)
 bestPath[i + 1] = path[i];
 }
 } while (next_permutation(path, path + n - 1));
 cout << "Minimum cost: " << minCost << endl;
 cout << "Optimal tour: ";
 for (int i = 0; i < n; i++)
 cout << bestPath[i] << " -> ";
 cout << "0" << endl;
 return 0;
}
