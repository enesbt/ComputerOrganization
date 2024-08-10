#include <iostream>
#include "Cpu.hpp"


using namespace std;

// Komutlarin exe safhalari yazilacak
// sub mul div icin komutlari yaz elde biti sorununu cozulecek
int main()
{
    system("cls");
    string file = "C:/Users/Enes/Desktop/ComputerOrganization/Project/data/data.txt";   

    Cpu *cpu = new Cpu(file);
    cpu->StartDecodeCode();
                         

    return 0;
}