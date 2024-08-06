#include <iostream>
#include "File.hpp"
#include <bitset>
#include "Registers.hpp"
#include "Commands.hpp"
using namespace std;


int main()
{

    File* f = new File("C:/Users/Enes/Desktop/BO/Project/data/data.txt");
    Registers* r = new Registers();



    f->ReadFile();
    vector<uint8_t> x = f->getFile();
    uint8_t  *pc = x.data();
    //bitset<8> bitt = x[0];
    cout<<"X.SIZE(): "<<x.size()<<endl;
    
    for(int i=0;i<x.size();++i)
    {
        cout << "Adres: " << static_cast<void*>(&x[i]) << endl; 
        cout << "Deger (x[i]): " << bitset<8>(x[i]) << endl; 
        cout << "Deger (pc): " << bitset<8>(*(pc + i)) << endl;
        cout << "PC Adres: " << static_cast<void*>(pc) << std::endl;
        pc = pc+1;
        //cout<<"bit: "<<bitt<<endl;
        //cout<<"gg: "<<gg<<endl;
        
    }
    r->setAR(&x[0]);
    
    cout<<"r->getar(): "<<static_cast<void*>(r->getAR())<<endl;

    cout<<"##################################\n";
    Commands* c = new Commands();
    string result = c->CommandDecoder(bitset<8>("11010001"));
    cout<<"result: "<<result<<endl;
    //cout<<bitset<8>("00000100")<<endl;

    // map<bitset<6>, string>::iterator it = c->commands.begin();

    // // Iterate through the map and print the elements
    // while (it != c->commands.end()) {
    //     cout << "Key: " << it->first
    //          << ", Value: " << it->second << endl;
    //     ++it;
    // }

    //c->FindCommand(00000111);
    
    
    // İlk 6 biti al
    

    // Sonuçları ekrana yazdır
   
    // cout << "r->getAR(): " << bitset<8>(r->getAR()) << endl;

    // uint8_t *ar = pc;
    // cout<<"ar: "<<static_cast<int>(*ar)<<endl;
    //     cout << "Son elemanın adresi (binary format): " 
    //      << bitset<sizeof(void*) * 8>(reinterpret_cast<uintptr_t>(&x.back())) 
    //      << endl;

    // void* ptr = static_cast<void*>(&x[0]);

    // // Adresi uintptr_t'e dönüştür
    // uintptr_t address = reinterpret_cast<uintptr_t>(ptr);

    
    // // Adresi binary formatında yazdır
    // cout << "Adres: ";
    //     for (size_t j = 0; j < sizeof(address); ++j) {
    //         // Byte'ları yazdır
    //         uint8_t byte = static_cast<uint8_t>(address >> (j * 8));
    //         cout << bitset<8>(byte) << " ";
    //         x.push_back(byte);
    //     }
    //     cout << endl;


    // cout<<"--------------------------------------------------------\n";
    // for(int i=0;i<x.size();++i)
    // {
    //     cout << "Adres: " << static_cast<void*>(&x[i]) << endl; 
    //     cout << "Deger (x[i]): " << bitset<8>(x[i]) << endl; 
    //     cout << "Deger (pc): " << bitset<8>(*(pc + i)) << endl; 
    // }


    // cout<<"############################################################\n";
    // uint8_t* ptr0 = &x[0];
    // uint8_t* ptr6 = &x[6];

    // // Adresler arasındaki farkı hesapla
    // ptrdiff_t result = ptr6 - ptr0;

    // // Adresleri ve farkı yazdır
    // cout << "x[0]: " << static_cast<void*>(ptr0) << endl;
    // cout << "x[6]: " << static_cast<void*>(ptr6) << endl;
    // cout << "Adres farki (eleman sayisi olarak): " << result << endl;
    // cout<< "x[6]degeri : " << x[0]+result <<endl;
    //bitset<8> ach = bitset<8>(*pc);
    //pc = pc+1;
    //bitset<8> acl = bitset<8>(*pc); 
    //cout<<"ach: "<<ach<<" "<<"acl: "<<acl<<endl;

    // uint16_t value = 0x1234; // 16 bitlik örnek değer

    // // Yüksek değerli 8 bitlik kısmı (MSB) almak için
    // uint8_t high_byte = (value >> 8) & 0xFF;

    // // Düşük değerli 8 bitlik kısmı (LSB) almak için
    // uint8_t low_byte = value & 0xFF;

    // std::cout << "16-bit value: 0x" << std::hex << value << std::endl;
    // std::cout << "High byte (MSB): 0x" << std::hex << (int)high_byte << std::endl;
    // std::cout << "Low byte (LSB): 0x" << std::hex << (int)low_byte << std::endl;




    return 0;
}