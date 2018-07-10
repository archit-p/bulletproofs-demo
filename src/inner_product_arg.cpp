#include <iostream>
#include "num_theory.hpp"
#include "vector_util.hpp"
#include "serialize.hpp"

#define ORDER 383
#include "inner-product-arg.hpp"
InnerProdArg::InnerProdArg(vector <int> a, vector <int> b, int c, int x) {
    if(a.size() != b.size())
        return;
    InnerProdArg::a = a;
    InnerProdArg::b = b;
    InnerProdArg::c = c;
    InnerProdArg::x = x;
    generate_argument();
}

void InnerProdArg::generate_argument()
{
    vector <int> a_l, a_r, b_l, b_r, a_prime, b_prime, to_send;
    int x_inv = modInverse(x, ORDER);
    cout << "x_inv value is :" << x_inv << endl;
    int c_prime; 
    while(a.size() > 1) {
        get_half(a, a_l, a_r);
        get_half(b, b_l, b_r);
        a_prime = vector_sum(k_product_vector(a_l, x, ORDER), k_product_vector(a_r, x_inv, ORDER), ORDER);
        b_prime = vector_sum(k_product_vector(b_l, x_inv), k_product_vector(b_r, x), ORDER);
        c_prime = inner_product(a_prime, b_prime, ORDER);
        
        a.clear();
        b.clear();

        a = a_prime;
        b = b_prime;
        to_send.push_back(c_prime);
    }
    to_send.push_back(a[0]);
    to_send.push_back(b[0]);
    final_arg = serialize(to_send);
}

char *InnerProdArg::get_argument()
{
    return final_arg;
}