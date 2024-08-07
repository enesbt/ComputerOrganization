#ifndef ALU_HPP
#define ALU_HPP
#include <iostream>
#include<bitset>
using namespace std;
struct Alu
{
    bitset<8> Add(bitset<8>,bitset<8>);
    void Sub(bitset<8>,bitset<8>);
    void Mul(bitset<8>,bitset<8>);
    void Div(bitset<8>,bitset<8>);
};








#endif