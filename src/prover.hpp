#ifndef PROVER_H
#define PROVER_H

#include <vector>
using std::vector;

class Prover{
    public:
        Prover(int , int , vector <int>);
        vector <int> get_complement_vector(vector <int>);
        vector <int> get_prime_group();
        int commit_to(int , vector <int> , vector <int> );
        bool set_t_coefficients();
        long calc_t_cap();
        bool t_commitment();
        int calc_tau_x();
        void set_x(int );
        void set_y(int );
        void set_z(int );
	int get_mu();
    private:
        int n, p, v;
        int x, y, z;
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
        vector <int> get_gen_vector(vector <int> gens, int len);
        vector <int> calc_l();
        vector <int> calc_r();
};

#endif
