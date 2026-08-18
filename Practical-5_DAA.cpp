#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int knapsack(int W, vector<int>& weight, vector<int>& value, int n) {
 // DP table
 vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
 // Build the DP table
 for (int i = 1; i <= n; i++) {
 for (int w = 1; w <= W; w++) {
 // If the current item can fit
if (weight[i - 1] <= w) {
 dp[i][w] = max(
 value[i - 1] + dp[i - 1][w - weight[i - 1]],
 dp[i - 1][w]
 );
 }
 else {
 // Cannot include the current item
 dp[i][w] = dp[i - 1][w];
 }
 }
 }
 return dp[n][W];
}
int main() {
 int n, W;
 cout << "Enter number of items: ";
 cin >> n;
 vector<int> weight(n);
 vector<int> value(n);
 cout << "Enter weights of items: ";
 for (int i = 0; i < n; i++) {
 cin >> weight[i];
 }
 cout << "Enter values of items: ";
 for (int i = 0; i < n; i++) {
 cin >> value[i];
 }
 cout << "Enter maximum capacity of knapsack: ";
 cin >> W;
 int maximumValue = knapsack(W, weight, value, n);

 cout << "Maximum value = " << maximumValue << endl;
 cout<<"kolusu uday kiran\n";
 cout<<"92460118175\n";
 cout<<"5-EN18\n";
 return 0;
}
