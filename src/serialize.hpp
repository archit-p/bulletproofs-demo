#ifndef SERIALIZE_H
#define SERIALIZE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <fstream>

char *conv_to_bytes(int n)
{
    char *temp = (char *)malloc(sizeof n);
    std::copy_n(static_cast<const char*>(static_cast<const void*>(&n)),
                    sizeof n,
                        temp);
    //printf("%x\n", temp[0]);
    return temp;
}

char *serialize(std::vector <int> nums)
{
    char *temp, *p, *bytes = (char *)malloc(sizeof(int)* nums.size());
    p = bytes;
    for(int i = 0; i < nums.size(); i++, p += sizeof(int)) {
        temp = conv_to_bytes(nums[i]);
        std::copy_n(temp,
                     sizeof(int),
                      p);
    }
    return bytes;
}

std::vector <int> deserialize(char *bytes, int num_bytes)
{
    std::vector <int> ret;
    int temp;
    num_bytes = num_bytes/sizeof(int);

    for(int i = 0; i < num_bytes; i++) {
        std::copy_n(static_cast<const int*>(static_cast<const void*>(bytes))+i,
                        1,
                            &temp);
        ret.push_back(temp);
    }

    return ret;
}

#endif