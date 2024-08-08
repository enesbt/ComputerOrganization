#ifndef ALU_HPP
#define ALU_HPP
#include <iostream>
#include<bitset>
#include "Registers.hpp"
using namespace std;
struct Alu
{
    void Add(Registers&);
    void Sub(bitset<8>,bitset<8>);
    void Mul(bitset<8>,bitset<8>);
    void Div(bitset<8>,bitset<8>);
};








#endif