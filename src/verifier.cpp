#include "verifier.hpp"
#include "vector_util.hpp"
#include "num_theory.hpp"
#include <vector>
int Verifier::calc_delta(int y, int z)
{
	int delta = z-pow(z, 2)*inner_product(get_k_vector(1, n), get_k_vector(y, n))-pow(z, 3)*inner_product(get_k_vector(2, n), get_k_vector(1, n));
	return delta;
}
