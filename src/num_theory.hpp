#ifndef NUM_THEORY_H
#define NUM_THEORY_H

#include <vector>
using std::vector;
#include <cmath>

bool is_prime(long int );
long get_prime(long );
int large_mod(int , int , int );
vector <int> haderson_product(vector <int> , vector <int> );
long inner_product(vector <int> , vector <int> );
long inner_product(vector <int> , vector <int> , int);
int vector_power(vector <int> , vector <int> );
int vector_power(vector <int> , vector <int> , int );
vector <int> vector_polynomial_product(vector <int> , vector <int> );
int modInverse(int , int );
int neg_power_mod(int , int , int , int );

#endif