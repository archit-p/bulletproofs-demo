#ifndef NUM_THEORY_H
#define NUM_THEORY_H

#include <vector>
using std::vector;
#include <cmath>

bool is_prime(long int n);
long get_prime(long q);
int large_mod(int a, int b, int p);
vector <int> haderson_product(vector <int> a, vector <int> b);
long inner_product(vector <int> a, vector <int> b);
long inner_product(vector <int> a, vector <int> b, int order);
int vector_power(vector <int> a, vector <int> b);
vector <int> vector_polynomial_product(vector <int> a, vector <int> b);
int modInverse(int a, int m);
int neg_power_mod(int a, int y, int i, int order);

#endif