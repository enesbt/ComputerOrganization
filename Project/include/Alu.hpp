#ifndef ALU_HPP
#define ALU_HPP
#include <iostream>
#include<bitset>
#include "Registers.hpp"
using namespace std;
struct Alu
{
    void Add(Registers&);
    void AddC(Registers&);
    void And(Registers&);
    void Cmp(Registers&);
    void Xor(Registers&);
    void Or(Registers&);
    void Clr(Registers&);
    void Decr(Registers&);
    void Incr(Registers&);
};








#endif