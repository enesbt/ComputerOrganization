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


string Commands::CommandDecoder(bitset<8> opcode)
{
    
    std::bitset<2> addrMode(opcode.to_ulong() >> 6); // Sağdan 6 bit kaydırma
    std::cout << "addrMode: " << addrMode << std::endl; // Ekrana: 10

    // Son 6 biti almak için
    std::bitset<6> command(opcode.to_ulong() & 0x3F); // Son 6 biti almak için bit maskesi
    std::cout << "command: " << command << std::endl; // Ekrana: 101


    auto it = addressmodes.find(addrMode);
    auto it2 = commands.find(command);

    string addrModeString = "";
    string commandString = "";

    if (it != addressmodes.end()) {
       addrModeString = it->second;
    } else {
        cout << "AdressModu Bulunamadi " <<endl;
    }
    if (it2 != commands.end()) {
       commandString = it2->second;
    } else {
        cout << "Command Bulunamadi " <<endl;
    }

    //cout<<"Adres Modu: "<<addrModeString<<endl;
    //cout<<"Command: "<<commandString<<endl;
    string result = commandString+"."+addrModeString;
    return result;

}

Commands::~Commands()
{
    this->addressmodes.clear();
    this->commands.clear();
}