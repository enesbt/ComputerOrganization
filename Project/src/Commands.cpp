#include "Commands.hpp"



Commands::Commands()
{
    this->addressmodes[bitset<2>("00")] = "IVEDI";
    this->addressmodes[bitset<2>("01")] = "DIREKT";
    this->addressmodes[bitset<2>("10")] = "DOLAYLI";
    this->addressmodes[bitset<2>("11")] = "DOGAL";

    this->commands[bitset<6>("000001")] = "ADD";
    this->commands[bitset<6>("000010")] = "ADDC";
    this->commands[bitset<6>("000011")] = "AND";
    this->commands[bitset<6>("000100")] = "CMP";
    this->commands[bitset<6>("000101")] = "DIV";
    this->commands[bitset<6>("000110")] = "XOR";
    this->commands[bitset<6>("000111")] = "OR";
    this->commands[bitset<6>("001000")] = "SUB";
    this->commands[bitset<6>("001001")] = "SUBC";
    this->commands[bitset<6>("001010")] = "MUL";
    this->commands[bitset<6>("001011")] = "LDA";
    this->commands[bitset<6>("001100")] = "STA";
    this->commands[bitset<6>("001101")] = "CLR";
    this->commands[bitset<6>("001110")] = "DECR";
    this->commands[bitset<6>("001111")] = "INCR";
    this->commands[bitset<6>("010000")] = "CLC";
    this->commands[bitset<6>("010001")] = "STC";
}


string Commands::AddressModeDecoder(bitset<8>opcode)
{
    bitset<2> addrMode(opcode.to_ulong() >> 6); 
    cout << "addrMode: " << addrMode << endl;
    auto it = addressmodes.find(addrMode);
    string addrModeString = "";
    if (it != addressmodes.end()) {
       addrModeString = it->second;
    } else {
        cout << "AdressModu Bulunamadi " <<endl;
    }
    return addrModeString;
}
string Commands::CommandDecoder(bitset<8> opcode)
{
    bitset<6> command(opcode.to_ulong() & 0x3F);
    cout << "command: " << command << endl; 
    auto it = commands.find(command);
    string commandString = "";
    if (it != commands.end()) {
       commandString = it->second;
    } else {
        cout << "Command Bulunamadi " <<endl;
    }
    return commandString;
}

Commands::~Commands()
{
    this->addressmodes.clear();
    this->commands.clear();
}