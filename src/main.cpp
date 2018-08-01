#include <iostream>
#include <ctime>

#include "prover.hpp"
#include "group.hpp"
#include "verifier.hpp"
#include "inner-product-arg.hpp"
#include "vector_util.hpp"

vector <int> build_gen_vector(Group *g, int len)
{
    vector <int> ret;
    for(int i = 0; i < len; i++)
        ret.push_back(g->get_gen());
    return ret;
}

int main()
{
    //initialize a random number generator for future use
    srand(unsigned(std::time(NULL))); 
    Group *g = new Group(383);
    Prover *p = new Prover(9, 383, build_gen_vector(g, 4));
    return 0;
}
