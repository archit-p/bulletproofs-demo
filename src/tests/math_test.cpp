#include <iostream>
#include <cmath>

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

int main()
{
    std::cout << neg_power_mod(3, 2, 2, 11);
}