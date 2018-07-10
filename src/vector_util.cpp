#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <assert.h>

#include <math.h>

#include <algorithm>
using std::reverse;

#include "vector_util.hpp"

void get_half(vector <int>& a, vector <int>& b, vector <int>& c)
{
    //function clears the values in b and c
    b.clear();
    c.clear();
    vector <int> :: iterator i;
    int l, vali;

    for(i = a.begin(), l = 0; l < a.size(); l++, i++) {
        vali = *i;
        if(l < a.size()/2)
            b.push_back(vali);
        else
            c.push_back(vali);
    }
}

//function to pretty print a vector
template <typename T>
void pprint_vector(vector <T> a)
{
    typename vector <T> :: iterator i;
    cout << "----------" << endl;
    for(i = a.begin(); i != a.end(); i++)
        cout << *i << " ";
    cout << endl << "----------" << endl;
}

//get the haderson product of two vectors
vector <int> get_k_vector(int k, int n)
{
    vector <int> ret;
    for(int i = n-1; i >= 0; i--)
        ret.push_back(pow(k, i));
    return ret;
}

vector <int> get_bit_vector(long v)
{
    vector <int> ret;
    int bit;
    while(v > 0) {
        bit = v&1;
        ret.push_back(bit);
        v >>= 1;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

vector <int> k_product_vector(vector <int> vec, int k)
{
    for(int i = 0; i < vec.size(); i++) {
        vec[i] *= k;
    }
    return vec;
}

vector <int> k_product_vector(vector <int> vec, int k, int order)
{
    for(int i = 0; i < vec.size(); i++) {
        vec[i] *= k;
        vec[i] = vec[i]%order;
    }
    return vec;
}

vector <int> vector_diff(vector <int> a, vector <int> b)
{
    vector <int> c;
    for(int i = 0; i < a.size(); i++) 
        c.push_back(a[i]-b[i]);
    return c;
}

vector <int> vector_sum(vector <int> a, vector <int> b)
{
    vector <int> c;
    for(int i = 0; i < a.size(); i++) 
        c.push_back(a[i]+b[i]);
    return c;
}

vector <int> vector_sum(vector <int> a, vector <int> b, int order)
{
    vector <int> c;
    for(int i = 0; i < a.size(); i++) 
        c.push_back((a[i]+b[i])%order);
    return c;
}

vector <int> random_vector(int len)
{
    vector <int> ret;
    for(int i = 0; i < len; i++)
        ret.push_back(rand()%2);
    return ret;
}

void pad_vector(vector <int> &vec, int len)
{
    while(vec.size() < len) {
        vec.push_back(0);
    }
}