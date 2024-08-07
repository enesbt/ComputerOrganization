#ifndef COMMANDS_HPP
#define COMMANDS_HPP
#include<map>
#include <bitset>
#include <string>
#include<iostream>
using namespace std;

struct BitsetComparator {
    bool operator()(const std::bitset<2>& lhs, const std::bitset<2>& rhs) const {
        return lhs.to_ulong() < rhs.to_ulong();
    }
};
struct BitsetComparator2 {
    bool operator()(const std::bitset<6>& lhs, const std::bitset<6>& rhs) const {
        return lhs.to_ulong() < rhs.to_ulong();
    }
};
struct Commands
{
    private:
        map<bitset<2>,string,BitsetComparator> addressmodes;
        map<bitset<6>,string,BitsetComparator2> commands;
    public:
        Commands();
        ~Commands();
        string AddressModeDecoder(bitset<8>);
        string CommandDecoder(bitset<8>);

};


#endif