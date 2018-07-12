#include <vector>
using std::vector;
#include <cmath>

bool is_prime(long int n)
{
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    if (n%2 == 0 || n%3 == 0) return false;
 
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
 
    return true;
}

long get_prime(long q)
{
    return 2*q+1;
}

int large_mod(int a, int b, int p)
{
    int q = 1;
    while(b > 0) {
        if(b%2 == 1) {
            q *= a;
            q = q%p;
        }
        b /= 2;
        a = (a*a)%p;
    }
    return q;
}

vector <int> haderson_product(vector <int> a, vector <int> b)
{
    vector <int> c;
    vector <int> :: iterator i = a.begin();
    vector <int> :: iterator j = b.begin();

    for(; i!= a.end(), j != b.end(); i++, j++)
        c.push_back((*i)*(*j));
    return c;
}

long inner_product(vector <int> a, vector <int> b)
{
    vector <int> :: iterator i;
    vector <int> :: iterator j;
    long prod = 0;
    int vali, valj;

    //assert (a.size() == b.size());
    for(i = a.begin(), j = b.begin(); i != a.end(), j != b.end(); i++, j++) {
        vali = *i;
        valj = *j;
        prod += vali * valj;
    }
    return prod;
}

long inner_product(vector <int> a, vector <int> b, int order)
{
    vector <int> :: iterator i;
    vector <int> :: iterator j;
    long prod = 0;
    int vali, valj;

    //assert (a.size() == b.size());
    for(i = a.begin(), j = b.begin(); i != a.end(), j != b.end(); i++, j++) {
        vali = *i;
        valj = *j;
        prod += vali * valj;
    }
    return prod%order;
}

int vector_power(vector <int> a, vector <int> b)
{
    vector <int> :: iterator i;
    vector <int> :: iterator j;

    int power = 1;
    int vali;
    int valj;

    //assert (a.size() == b.size());
    for(i = a.begin(), j = b.begin(); i != a.end(), j != b.end(); i++, j++) {
        vali = *i;
        valj = *j;
        power *= pow(vali, valj);
    }
    return power;
}

int vector_power(vector <int> a, vector <int> b, int order)
{
    vector <int> :: iterator i;
    vector <int> :: iterator j;

    int power = 1;
    int vali;
    int valj;

    //assert (a.size() == b.size());
    for(i = a.begin(), j = b.begin(); i != a.end(), j != b.end(); i++, j++) {
        vali = *i;
        valj = *j;
        power *= (int(pow(vali, valj))%order);
    }
    return power;
}

vector <int> vector_polynomial_product(vector <int> a, vector <int> b)
{
    vector <int> g_1;
}

int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;
    if (m == 1)
      return 0;
    while (a > 1)
    {
        int q = a / m;
        int temp = m;
        m = a % m, a = temp;
        temp = y;
        y = x - q * y;
        x = temp;
    }
    if (x < 0)
       x += m0;
    return x;
}

int neg_power_mod(int a, int y, int i, int order)
{
    int y_inv = modInverse(y, order);
    int expt = (int)pow(y_inv, i-1)%order;
    return (int)pow(a, expt)%order;
}