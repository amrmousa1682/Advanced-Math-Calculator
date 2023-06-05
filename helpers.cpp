#include "helpers.h"
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return (!b) ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int mod(int a, int b) { return ((b + (a % b)) % b); }

bool is_number(char s) {
  if (s >= '0' && s <= '9' || s == '.')
    return 1;
  return 0;
}
bool is_char(char s) {
  if (toupper(s) >= 'A' && toupper(s) <= 'Z')
    return 1;
  return 0;
}
bool is_operator(char s) {
  if (s == '+' || s == '-' || s == '*' || s == '/' || s == '^' || s == '(' ||
      s == ')')
    return 1;
  return 0;
}
int find_invers(int a, int c) {
  for (int i = 1;; i++) {
    if (mod(a * i, 26) == 1)
      return i;
  }
}
void read(string &s) {
  cin.ignore();
  getline(cin, s);
}
void encode_and_decode(string &s, int a, int b, int c, int choice) {
  if (choice) {
    a = find_invers(a, c);
    b = -1 * b;
  }
  for (int i = 0; i < s.length(); i++) {
    if (is_char(s[i])) {
      s[i] = toupper(s[i]);
      if (choice)
        s[i] = mod(a * (s[i] - 65 + b), c) + 65;
      else
        s[i] = mod(a * (s[i] - 65) + b, c) + 65;
    }
  }
  cout << "Result : " << s << endl;
}