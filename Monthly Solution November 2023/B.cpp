#include<bits/stdc++.h>
using namespace std;

int calculate_Sum (string name) {
  int sum = 0;
  for (char c : name) {
    if (isalpha(c)) {
      sum += tolower(c) - 'a' + 1;
    }
  }
  while (sum > 9) {
    int temp = sum;
    sum = 0;
    while (temp) {
      sum += temp % 10;
      temp /= 10;
    }
  }
  return sum;
}

int main() {
  string name1, name2;
  while (getline(cin, name1) && getline(cin, name2)) {
    int sum1 = calculate_Sum (name1);
    int sum2 = calculate_Sum (name2);
    double ratio = 100.0 * min(sum1, sum2) / max(sum1, sum2);
    printf("%.2f %%\n", ratio);
  }
  return 0;
}
