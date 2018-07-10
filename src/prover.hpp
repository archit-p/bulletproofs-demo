#ifndef PROVER_H
#define PROVER_H

#include <vector>
using std::vector;

class Prover{
    public:
        Prover(int , int , int , vector <int>);
        vector <int> get_complement_vector(vector <int>);
        vector <int> get_prime_group();
        int commit_to(int , vector <int> , vector <int> );
        long hash(vector <int>, vector <int>, vector <int>, vector <int>, int , int );
        bool set_t_coefficients(int , int , int);
        long calc_t_cap(int , int , int );
        bool t_commitment();
        int calc_tau_x(int , int );
    private:
        int n, p;
        long v, a, s;
        vector <int> al;
        vector <int> ar;
        vector <int> sl;
        vector <int> sr;
        vector <int> g;
        vector <int> h;
        int alpha, row;
        int a_commit;
        int s_commit;
        int t[3];
        int t_commit[2];
        int tau[2];
        int tau_x;
        vector <int> get_gen_vector(int len);
        vector <int> calc_l(int , int );
        vector <int> calc_r(int , int , int );
};

#endif