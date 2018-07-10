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

void get_half(vector <int>& a, vector <int>& b, vector <int>& c);
template <typename T>
void pprint_vector(vector <T> a);
vector <int> get_k_vector(int k, int n);
vector <int> get_bit_vector(long v);
vector <int> k_product_vector(vector <int> vec, int k);
vector <int> k_product_vector(vector <int> vec, int k, int order);
vector <int> vector_diff(vector <int> a, vector <int> b);
vector <int> vector_sum(vector <int> a, vector <int> b);
vector <int> vector_sum(vector <int> a, vector <int> b, int order);
vector <int> random_vector(int len);
void pad_vector(vector <int> &vec, int len);

#endif