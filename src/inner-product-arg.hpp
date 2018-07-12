#ifndef INNER_H
#define INNER_H

#include <vector>
using std::vector;

class InnerProdArg
{
    public:
        InnerProdArg(vector <int>, vector <int>, int, int, int);
        char *get_argument();
    private:
        vector <int> a;
        vector <int> b;
        char *final_arg;
        int order;
        int c;
        int x;
        void generate_argument();
};

#endif