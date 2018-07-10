#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

#include "vector_util.hpp"
#include "num_theory.hpp"
#include "prover.hpp"

Prover::Prover(int val, int size, int prime, vector <int> gens)
{
    v = val;
    n = size;
    p = prime;
    al = get_bit_vector(v);
    ar = get_complement_vector(al);
    tau[0] = rand()%13;
    tau[1] = rand()%13;
    g = g;
    h = h;
    a_commit = commit_to(alpha, al, ar);
    s_commit = commit_to(row, al, ar);
    sl = random_vector(al.size());
    sr = random_vector(al.size());
}

int Prover::calc_tau_x(int x, int z)
{
    return tau[1]*(int)pow(x, 2)+tau[0]*x+z*p;
}

int Prover::commit_to(int x, vector <int> a, vector <int> b)
{
    return ((int)pow(g[0], x)*vector_power(g, a)*vector_power(h, b))%p;
}

vector <int> Prover::get_complement_vector(vector <int> al)
{
    vector <int> ar;
    for(int i = 0; i < al.size(); i++) {
        ar.push_back(al[i]-1);
    }
    return ar;
}

vector <int> Prover::get_gen_vector(int len)
{
    vector <int> ret;
    for(int i = 0; i < len; i++) {
        int gen = Prover::p;
        ret.push_back(gen);
    }
    return ret;
}

vector <int> Prover::calc_l(int x, int z)
{
    return vector_sum(vector_diff(al, k_product_vector(get_k_vector(1, al.size()), z)), k_product_vector(sl, x));
}

vector <int> Prover::calc_r(int x, int y, int z)
{
    vector <int> ret = vector_sum(ar, k_product_vector(get_k_vector(1, ar.size()), z));
    ret = vector_sum(ret, k_product_vector(sr, x));
    ret = haderson_product(get_k_vector(y, ar.size()),ret);
    ret = vector_sum(ret, k_product_vector(get_k_vector(2, ar.size()), (int)pow(z, 2))); 
    return ret;
}

long Prover::calc_t_cap(int x, int y, int z)
{
    return inner_product(calc_r(x, y, z), calc_l(x, z));
}

bool Prover::t_commitment()
{
    t_commit[0] = (int)(pow(g[0], t[1])*pow(g[0], tau[0]))%p;
    t_commit[1] = (int)(pow(g[0], t[2])*pow(g[0], tau[1]))%p;
    return true;
}

long Prover::hash(vector <int> a1, vector <int> a2, vector <int> b1, vector <int> b2, int u, int c)
{
    vector <int> g1, g2, h1, h2;
    get_half(g, g1, g2);
    get_half(h, h1, h2);
    return vector_power(g1, a1)*vector_power(g2, a2)*vector_power(h1, b1)*vector_power(h2, b2)*(int)pow(u, c);
}

bool Prover::set_t_coefficients(int x, int y, int z)
{
    vector <int> prod = haderson_product(vector_sum(Prover::ar, k_product_vector(get_k_vector(1, ar.size()), z)), get_k_vector(y, ar.size()));
    prod = vector_sum(prod, k_product_vector(get_k_vector(2, ar.size()), (int)pow(z, 2)));
    vector <int> diff = vector_diff(al, k_product_vector(get_k_vector(1, al.size()), z));
    t[0] = inner_product(prod, diff);
    vector <int> haderson_y = haderson_product(get_k_vector(y, ar.size()), sr);
    t[1] = inner_product(diff, haderson_y) + inner_product(sl, prod);
    t[2] = inner_product(sl, sr);
}