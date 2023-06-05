#include "solvers.h"
#include "convert.h"
#include "helpers.h"
#include <bits/stdc++.h>
using namespace std;

void solve_infix() {
  string expression;
  read(expression);
  solve_postfix(infix_to_postfix(expression));
}
void solve_prefix() {
  string expression;
  read(expression);
  solve_postfix(infix_to_postfix(prefix_to_infix(expression)));
}
void solve_postfix(string expression) {
  if (expression == "") {
    read(expression);
  }
  string number = "";
  stack<double> s;
  double a;
  for (int i = 0; i < expression.length(); ++i) {
    if (is_number(expression[i])) {
      number += expression[i];
    } else if (is_operator(expression[i])) {
      if (number != "") {
        s.push(stod(number));
        number = "";
      }
      if (expression[i] == '+') {
        a = s.top();
        s.pop();
        a = s.top() + a;
        s.pop();
        s.push(a);
      } else if (expression[i] == '-') {
        if (is_number(expression[i + 1])) {
          number = "-";
          continue;
        }
        a = s.top();
        s.pop();
        a = s.top() - a;
        s.pop();
        s.push(a);
      } else if (expression[i] == '*') {
        a = s.top();
        s.pop();
        a = s.top() * a;
        s.pop();
        s.push(a);
      } else if (expression[i] == '/') {
        a = s.top();
        s.pop();
        a = s.top() / a;
        s.pop();
        s.push(a);
      } else if (expression[i] == '^') {
        a = s.top();
        s.pop();
        a = pow(s.top(), a);
        s.pop();
        s.push(a);
      }
    } else if (expression[i] == ' ' && number != "") {
      s.push(stod(number));
      number = "";
    }
  }
  cout << "Result = " << s.top() << endl;
}