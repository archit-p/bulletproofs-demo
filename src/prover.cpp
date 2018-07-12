#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

#include "vector_util.hpp"
#include "num_theory.hpp"
#include "prover.hpp"

Prover::Prover(int val, int prime, vector <int> gens)
{
    v = val;
    p = prime;
    x = y = z = -1;
    tau[0] = rand()%prime;
    tau[1] = rand()%prime;
    alpha = rand()%prime;
    row = rand()%prime;

    al = get_bit_vector(v);
    ar = get_complement_vector(al);
    n = al.size();

    sl = random_vector(n, 2);
    sr = random_vector(n, 2);

    g = get_gen_vector(gens, n);
    h = get_gen_vector(gens, n);

    a_commit = commit_to(alpha, al, ar);
    s_commit = commit_to(row, sl, sr);
}

vector <int> Prover::get_gen_vector(vector <int> gens, int len)
{
    vector <int> ret;
    int gen;
    for(int i = 0; i < len; i++) {
        gen = gens[rand()%gens.size()];
        ret.push_back(gen);
    }
    return ret;
}

void Prover::set_x(int x)
{
    Prover::x = x;
}

void Prover::set_y(int y)
{
    Prover::y = y;
}

void Prover::set_z(int z)
{
    Prover::z = z;
}

int Prover::calc_tau_x()
{
    if(x == -1 || z == -1) {
        cout << "Set the x and z values before calling";
        return -1;
    }
    return tau[1]*(int)pow(x, 2)+tau[0]*x+z*p;
}

int Prover::commit_to(int alpha, vector <int> a, vector <int> b)
{
    return ((int)pow(g[0], alpha)%p)*(vector_power(g, a)*vector_power(h, b))%p;
}

vector <int> Prover::get_complement_vector(vector <int> al)
{
    vector <int> ar;
    for(int i = 0; i < n; i++) {
        ar.push_back(al[i]-1);
    }
    return ar;
}

vector <int> Prover::calc_l()
{
    if(x == -1 || z == -1) {
        cout << "Set the x and z values before calling";
        return {-1};
    }
    return vector_sum(vector_diff(al, k_product_vector(get_k_vector(1, n), z)), k_product_vector(sl, x));
}

vector <int> Prover::calc_r()
{
    if(x == -1 || z == -1) {
        cout << "Set the x and z values before calling";
        return {-1};
    }
    vector <int> ret = vector_sum(ar, k_product_vector(get_k_vector(1, ar.size()), z));
    ret = vector_sum(ret, k_product_vector(sr, x));
    ret = haderson_product(get_k_vector(y, ar.size()),ret);
    ret = vector_sum(ret, k_product_vector(get_k_vector(2, ar.size()), (int)pow(z, 2))); 
    return ret;
}

long Prover::calc_t_cap()
{
    return inner_product(calc_r(), calc_l());
}

bool Prover::t_commitment()
{
    t_commit[0] = (int)(pow(g[0], t[1])*pow(g[0], tau[0]))%p;
    t_commit[1] = (int)(pow(g[0], t[2])*pow(g[0], tau[1]))%p;
    return true;
}

bool Prover::set_t_coefficients()
{
    if(x == -1 || z == -1 || y == -1) {
        cout << "Set the x and z values before calling";
        return false;
    }
    vector <int> prod = haderson_product(vector_sum(Prover::ar, k_product_vector(get_k_vector(1, ar.size()), z)), get_k_vector(y, ar.size()));
    prod = vector_sum(prod, k_product_vector(get_k_vector(2, ar.size()), (int)pow(z, 2)));
    vector <int> diff = vector_diff(al, k_product_vector(get_k_vector(1, n), z));
    t[0] = inner_product(prod, diff);
    vector <int> haderson_y = haderson_product(get_k_vector(y, ar.size()), sr);
    t[1] = inner_product(diff, haderson_y) + inner_product(sl, prod);
    t[2] = inner_product(sl, sr);
}