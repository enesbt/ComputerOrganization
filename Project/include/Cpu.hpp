#ifndef CPU_HPP
#define CPU_HPP
#include <iostream>
#include "File.hpp"
#include <bitset>
#include "Registers.hpp"
#include "Commands.hpp"
#include "Alu.hpp"
#include "CommandCycle.hpp"
#include <random>
#include <cstdlib>  
#include <ctime>    
#include <vector>

using namespace std;


struct Cpu
{
    File *file;
    Registers *registers;
    Commands *commands;
    Alu *alu;
    CommmandCycle *commandCycle;


    Cpu(string);
    ~Cpu();
    vector<int> RandomValues(int,int);
    void StartDecodeCode();
    void StartIvedi();
    void StartDolayli();
    void StartDirekt();

    
};





#endif