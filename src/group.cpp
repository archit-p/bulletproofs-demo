#include <vector>
using std::vector;
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "num_theory.hpp"
#include <string>
using std::stoi;
#include "group.hpp"

//constructor for Group class
Group::Group(int p) 
{
    order = p;
    for(long i = 1; i <= p; i++)
        group.push_back(i);
    generators = find_gens(p);
}

//class functions definitions start from here

vector <int> Group::find_gens(int p)
{
    int q = (p-1)/2;
    int power_check_2, power_check_q;
    vector <int> gens;
    for(int i = 2; i < p; i++) {
        power_check_2 = large_mod(i, 2, p);
        power_check_q = large_mod(i, q, p);
        if(power_check_2 != 1 && power_check_q != 1)
            gens.push_back(i);
        }
    return gens;
}

//helper function returns the order of the group
int Group::get_order()
{
    return Group::order;
}

//helper function returns the group as a vector
vector <int> Group::get_group()
{
    return Group::group;
}

//helper function returns a generator for the group
int Group::get_gen()
{
    return Group::generators[rand()%Group::generators.size()];
}