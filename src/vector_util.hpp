#ifndef VECTOR_UTIL_H
#define VECTOR_UTIL_H

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <assert.h>

#include <math.h>

#include <algorithm>
using std::reverse;

void get_half(vector <int>& , vector <int>& , vector <int>& );
void pprint_vector(vector <int> );
vector <int> get_k_vector(int , int );
vector <int> get_bit_vector(long );
vector <int> k_product_vector(vector <int> , int );
vector <int> k_product_vector(vector <int> , int k, int );
vector <int> vector_diff(vector <int> , vector <int> );
vector <int> vector_sum(vector <int> , vector <int> );
vector <int> vector_sum(vector <int> , vector <int> , int );
vector <int> random_vector(int ,int );
void pad_vector(vector <int> &, int );

#endif
