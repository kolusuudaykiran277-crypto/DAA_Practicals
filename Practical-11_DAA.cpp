#include <iostream>
using namespace std;
int main() {
 int n;
 cout << "Enter number of vertices: ";
 cin >> n;
 int dist[10][10];
 cout << "Enter adjacency matrix (-1 for no edge):\n";
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 cin >> dist[i][j];
 if (dist[i][j] == -1)
 dist[i][j] = 99999;
 }
 }
 for (int k = 0; k < n; k++)
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 if (dist[i][k] != 99999 &&
 dist[k][j] != 99999 &&
 dist[i][k] + dist[k][j] < dist[i][j]) {
 dist[i][j] = dist[i][k] + dist[k][j];
 }
 }
 }
 cout << "Shortest distance matrix:\n";
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 if (dist[i][j] == 99999)
 cout << "INF ";
 else
 cout << dist[i][j] << " ";
 }
 cout << endl;
 }
 return 0;
}
