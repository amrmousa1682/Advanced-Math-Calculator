#include "convert.h"
#include "helpers.h"
#include <bits/stdc++.h>
using namespace std;

string infix_to_postfix(string expression) {
  string result = "";
  stack<char> s;
  for (int i = 0; i < expression.length(); ++i) {
    if (is_number(expression[i]) || is_char(expression[i]) ||
        expression[i] == ' ') {
      if (!(expression[i] == ' ' && result[result.length() - 1] == ' '))
        result += expression[i];
    } else if (is_operator(expression[i])) {
      if (expression[i] == '-' && is_number(expression[i + 1])) {
        result += '-';
        continue;
      }
      if (expression[i] == '(')
        s.push(expression[i]);
      else if (s.empty() || m[expression[i]] > m[s.top()])
        s.push(expression[i]);
      else if (expression[i] != ')') {
        while (!s.empty() && m[expression[i]] <= m[s.top()]) {
          result += s.top();
          result += " ";
          s.pop();
        }
        s.push(expression[i]);
      } else {
        while (s.top() != '(') {
          result += s.top();
          result += " ";
          s.pop();
        }
        s.pop();
      }
    }
  }
  while (!s.empty()) {
    if (result[result.length() - 1] != ' ')
      result += " ";
    result += s.top();
    result += " ";
    s.pop();
  }
  return result;
}
string postfix_to_prefix(string expression) {
  stack<string> s;
  string number, a, b;
  for (int i = 0; i < expression.length(); ++i) {
    if (is_number(expression[i])) {
      number += expression[i];
    } else if (is_char(expression[i])) {
      number = expression[i];
    } else if (is_operator(expression[i])) {
      if (expression[i] == '-' &&
          (is_number(expression[i + 1]) || is_char(expression[i + 1]))) {
        number = '-';
        continue;
      }
      if (number != "") {
        s.push(number);
        number = "";
      } else {
        a = s.top();
        s.pop();
        a = " " + s.top() + " " + a;
        s.pop();
        s.push(expression[i] + a);
      }
    } else if (expression[i] == ' ' && number != "") {
      s.push(number);
      number = "";
    }
  }
  return s.top();
}
string prefix_to_infix(string expression) {
  stack<string> s;
  string number, a;
  for (int i = expression.length() - 1; i >= 0; --i) {
    if (is_number(expression[i])) {
      number = expression[i] + number;
    } else if (is_char(expression[i])) {
      number = expression[i];
    } else if (is_operator(expression[i])) {
      if (expression[i] == '-' &&
          (is_number(expression[i + 1]) || is_char(expression[i + 1]))) {
        number = '-' + number;
        continue;
      }
      if (number != "") {
        s.push(number);
        number = "";
      } else {
        a = s.top();
        s.pop();
        a = " ( " + a + " " + expression[i] + " " + s.top() + " ) ";
        s.pop();
        s.push(a);
      }
    } else if (expression[i] == ' ' && number != "") {
      s.push(number);
      number = "";
    }
  }
  return s.top();
}