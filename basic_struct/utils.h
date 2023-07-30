#ifndef UTILS
#define UTILS
#include <iostream>
#include <stdlib.h>
#include <assert.h>
using namespace std;

template <typename T>
void print_tuple(string k1, T v1, string k2, T v2);

template <typename T>
void print_tuple(string k1, T v1, string k2, T v2, string name);

void print_indent(int n);

void print_indent(int n, string name);

int randint(int low, int high);

#endif  // UTILS