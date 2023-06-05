#include "menus.h"
#include "convert.h"
#include "helpers.h"
#include "solvers.h"
#include <bits/stdc++.h>

using namespace std;

void main_menu() {
  int choice;
  cout << "Math 2 calculator" << endl
       << "1-solve expression" << endl
       << "2-convert expression" << endl
       << "3-Mod(a%b)" << endl
       << "4-Gcd(a,b)" << endl
       << "5-Lcm(a,b)" << endl
       << "6-Encryption" << endl
       << "7-Decoding" << endl
       << "8-Exit" << endl
       << "Enter your choice : ";
  cin >> choice;
  switch (choice) {
  case 1:
    solve_menu();
    break;
  case 2:
    convert_menu();
    break;
  case 3:
    mod_gcd_lcm_menu(choice - 2);
    break;
  case 4:
    mod_gcd_lcm_menu(choice - 2);
    break;
  case 5:
    mod_gcd_lcm_menu(choice - 2);
    break;
  case 6:
    encode_and_decode_menu(choice - 6);
    break;
  case 7:
    encode_and_decode_menu(choice - 6);
    break;
  case 8:
    exit(0);
    break;
  default:
    cout << "Enter valid choice" << endl;
    break;
  }
}
void solve_menu() {
  int choice;
  cout << "solve expression :-" << endl
       << "1-prefix solver" << endl
       << "2-infix solver" << endl
       << "3-postfix solver" << endl
       << "Enter your choice : ";
  cin >> choice;
  switch (choice) {
  case 1:
    cout << "example : * + 10 6 - 5 3 \nEnter expression : ";
    solve_prefix();
    break;
  case 2:
    cout << "example : ( 10 + 5 ) * 5 + 3\nEnter expression : ";
    solve_infix();
    break;
  case 3:
    cout << "example : 6 6 + 5 13 - *\nEnter expression : ";
    solve_postfix("");
    break;
  default:
    cout << "Enter valid choice\n";
    break;
  }
}
void convert_menu() {
  int from, to;
  cout << "convert expression :-" << endl
       << "1-convert from prefix expression" << endl
       << "2-convert from infix  expression" << endl
       << "3-convert from postfix expression" << endl
       << "Enter your choice : ";
  cin >> from;
  cout << "convert expression :-" << endl
       << "1-convert to prefix expression" << endl
       << "2-convert to infix  expression" << endl
       << "3-convert to postfix expression" << endl
       << "Enter your choice : ";
  cin >> to;
  string expression;

  if (from == 1 && to == 2) {
    cout << "example : * + 10 6 - 5 3 \nEnter expression :";
    read(expression);
    cout << "Expression = " << prefix_to_infix(expression) << endl;
  } else if (from == 1 && to == 3) {
    cout << "example : * + 10 6 - 5 3 \nEnter expression : ";
    read(expression);
    cout << "Expression = " << infix_to_postfix(prefix_to_infix(expression))
         << endl;
  } else if (from == 2 && to == 1) {
    cout << "example : ( 10 + 5 ) * 5 + 3\nEnter expression :";
    read(expression);
    cout << "Expression = " << postfix_to_prefix(infix_to_postfix(expression))
         << endl;
  } else if (from == 2 && to == 3) {
    cout << "example : ( 10 + 5 ) * 5 + 3\nEnter expression :";
    read(expression);
    cout << "Expression = " << infix_to_postfix(expression) << endl;
  } else if (from == 3 && to == 2) {
    cout << "example : 6 6 + 5 13 - *\nEnter expression : ";
    read(expression);
    cout << "Expression = " << prefix_to_infix(postfix_to_prefix(expression))
         << endl;
  } else if (from == 3 && to == 1) {
    cout << "example : 6 6 + 5 13 - *\nEnter expression : ";
    read(expression);
    cout << "Expression = " << postfix_to_prefix(expression) << endl;
  } else {
    cout << "NOT VALID" << endl;
  }
}
void encode_and_decode_menu(int choice) {
  int a, b, c;
  string code;
  cout << "(a(X)+b)mod c" << endl;
  cout << "Enter a : ";
  cin >> a;
  cout << "Enter b : ";
  cin >> b;
  cout << "Enter c : ";
  cin >> c;
  cout << "Enter string : ";
  read(code);
  encode_and_decode(code, a, b, c, choice);
}
void mod_gcd_lcm_menu(int choice) {
  int a, b;
  if (choice == 1) {
    cout << "mod(a%b):-" << endl;
    cout << "Enter a : ";
    cin >> a;
    cout << "Enter b : ";
    cin >> b;
    cout << "Result : " << mod(a, b) << endl;
  } else if (choice == 2) {
    cout << "gcd(a,b):-" << endl;
    cout << "Enter a : ";
    cin >> a;
    cout << "Enter b : ";
    cin >> b;
    cout << "Result : " << gcd(a, b) << endl;
  } else {
    cout << "lcm(a,b):-" << endl;
    cout << "Enter a : ";
    cin >> a;
    cout << "Enter b : ";
    cin >> b;
    cout << "Result : " << lcm(a, b) << endl;
  }
}