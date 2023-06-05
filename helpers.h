#include <bits/stdc++.h>
using namespace std;
#ifndef HELPERS_H
#define HELPERS_H
static map<char, int> m{{'+', 1}, {'-', 1},  {'*', 2}, {'/', 2},
                        {'^', 3}, {'(', -1}, {')', -2}};
bool is_number(char s);
bool is_char(char s);
bool is_operator(char s);
int find_invers(int a, int c);
void read(string &s);
int gcd(int a, int b);
int lcm(int a, int b);
int mod(int a, int b);
void encode_and_decode(string &s, int a, int b, int c, int choice);
#endif