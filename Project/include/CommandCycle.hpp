#ifndef COMMANDCYCLE_HPP
#define COMMANDCYCLE_HPP
#include<iostream>
#include <map>
#include <functional>
#include "Registers.hpp"
#include "Alu.hpp"

using namespace std;


struct CommmandCycle
{
    CommmandCycle();
    string command;
    map<string,function<void(Registers&, Alu&)>>functionCommandMap;

    void Fetch(Registers&); // PC registeri degeri AR registerine atanir.Komut registerine komut atanir.PC degeri artirilir.
    void Decode(Registers&); // komut isleme verisi alma. 1byte lik DOGAL komutlar bu safhaya girmez.

    // ADD
    void IvediAdd(Registers&,Alu&);
    void DirektAdd(Registers&,Alu&);
    void DolayliAdd(Registers&,Alu&);
    // ADDC
    void IvediAddC(Registers&,Alu&);
    void DirektAddC(Registers&,Alu&);
    void DolayliAddC(Registers&,Alu&);
    // AND
    void IvediAnd(Registers&,Alu&);
    void DirektAnd(Registers&,Alu&);
    void DolayliAnd(Registers&,Alu&);
    // CMP
    void IvediCmp(Registers&,Alu&);
    void DirektCmp(Registers&,Alu&);
    void DolayliCmp(Registers&,Alu&);
    // DIV
    void IvediDiv(Registers&,Alu&);
    void DirektDiv(Registers&,Alu&);
    void DolayliDiv(Registers&,Alu&);
    // XOR
    void IvediXor(Registers&,Alu&);
    void DirektXor(Registers&,Alu&);
    void DolayliXor(Registers&,Alu&);
    // OR
    void IvediOr(Registers&,Alu&);
    void DirektOr(Registers&,Alu&);
    void DolayliOr(Registers&,Alu&);
    // SUB
    void IvediSub(Registers&,Alu&);
    void DirektSub(Registers&,Alu&);
    void DolayliSub(Registers&,Alu&);
    // SUBC
    void IvediSubC(Registers&,Alu&);
    void DirektSubC(Registers&,Alu&);
    void DolayliSubC(Registers&,Alu&);
    // MUL
    void IvediMul(Registers&,Alu&);
    void DirektMul(Registers&,Alu&);
    void DolayliMul(Registers&,Alu&);
    // LDA
    void IvediLda(Registers&,Alu&);
    void DirektLda(Registers&,Alu&);
    void DolayliLda(Registers&,Alu&);
    // STA
    void DirektSta(Registers&,Alu&);
    void DolayliSta(Registers&,Alu&);
    // CLR
    void DogalClr(Registers&,Alu&);
    // DECR
    void DogalDecr(Registers&,Alu&);
    // INCR
    void DogalIncr(Registers&,Alu&);
    // CLC
    void DogalClc(Registers&,Alu&);
    // STC
    void DogalStc(Registers&,Alu&);
    
    
    

};





#endif