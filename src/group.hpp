#ifndef GROUP_H
#define GROUP_H

class Group
{
    private:
        int order;
        vector <int> group;
        vector <int> generators;
        vector <int> find_gens(int p);
    public:
        Group(int p);
        int get_order();
        vector <int> get_group();
        int get_gen();
};

#endif