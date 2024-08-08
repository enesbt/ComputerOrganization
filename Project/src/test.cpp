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

using namespace std;

// Komutlarin exe safhalari yazilacak
// Kontrol Paneli olusturulacak.
// kontrol panelinde belirlenen adresleme moduna göre main program islensin
// dogal adresleme icin dosyaya yazma islemi gerceklesmesin.
// adresleme tipine gore islemler degissin.

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    
    // 20 ile 100 arasında rastgele bir değer üret
    int min = 20;
    int max = 80;
    int randomValue =  min + rand() % (max - min + 1);
    int random = randomValue+5;
    int randomValue2 = random + rand() % (max - random + 1);
    
    // Sonucu ekrana yazdır
    
    File* f = new File("C:/Users/Enes/Desktop/ComputerOrganization/Project/data/data.txt");
    Registers* r = new Registers();


    vector<uint8_t> x = f->getFile();
    f->ReadFile();
  

    
    // direkt ve dolayli adresleme icin belirli bir adrese ornek veri eklenir.
    // bu adres dizi(ram) içerinsen rastgele seçilir adres bilgisi programın devamına eklenir.
    // veri ise random olarak belirlenen adrese eklenir.

    void* yazilacakAddress =  static_cast<void*>(&f->fileArray[randomValue]);
    uintptr_t address = reinterpret_cast<uintptr_t>(&f->fileArray[randomValue]);
    bitset<sizeof(uintptr_t) * 8> addressBits(address);
    uint8_t* ptr = reinterpret_cast<uint8_t*>(address);
    cout << "Bit olarak adres: " << addressBits << endl;
    cout << "Yazilcak Address: " << yazilacakAddress << endl;
    cout << "Address: " << address << endl;
    
    // belirlenen adrese veri girişi
    // *ptr = static_cast<uint8_t>(bitset<8>("11111111").to_ulong());
    // ptr = ptr+1; 
    // *ptr = static_cast<uint8_t>(bitset<8>("11000011").to_ulong());

    //cout << "Bit olarak adres: " << addressBits.to_string() << endl;

    //dolayli adress icin 2 adres secilir biriin bulunduğu yere digeri yazilacak
    // yazilan yerde data olacak
    
    void* yazilacakAddress2 = static_cast<void*>(&f->fileArray[randomValue2]);
    uintptr_t address2 = reinterpret_cast<uintptr_t>(&f->fileArray[randomValue2]);
    bitset<sizeof(uintptr_t) * 8> addressBits2(address2);
    uint8_t* ptr2 = reinterpret_cast<uint8_t*>(address2);
    cout << "Bit olarak adres: " << addressBits2 << endl;
    cout << "Yazilcak Address: " << yazilacakAddress2 << endl;
    cout << "Address: " << address2 << endl;
    
    
    const int BITS_IN_BYTE = 8;
    std::bitset<BITS_IN_BYTE> part1, part2, part3, part4;
    
    for (int i = 0; i < BITS_IN_BYTE; ++i) {
        part1[i] = addressBits2[i];
        part2[i] = addressBits2[i + BITS_IN_BYTE];
        part3[i] = addressBits2[i + 2 * BITS_IN_BYTE];
        part4[i] = addressBits2[i + 3 * BITS_IN_BYTE];
    }
    std::cout << "Address bits: " << addressBits2 << std::endl;
    std::cout << "Part 1: " << part1 << std::endl;
    std::cout << "Part 2: " << part2 << std::endl;
    std::cout << "Part 3: " << part3 << std::endl;
    std::cout << "Part 4: " << part4 << std::endl;
    
    *ptr = static_cast<uint8_t>(bitset<8>(part4).to_ulong());
    ptr = ptr+1; 
    *ptr = static_cast<uint8_t>(bitset<8>(part3).to_ulong());
    ptr = ptr+1; 
    *ptr = static_cast<uint8_t>(bitset<8>(part2).to_ulong());
    ptr = ptr+1; 
    *ptr = static_cast<uint8_t>(bitset<8>(part1).to_ulong());


    *ptr2 = static_cast<uint8_t>(bitset<8>("11111111").to_ulong());
    ptr2 = ptr2+1; 
    *ptr2 = static_cast<uint8_t>(bitset<8>("11000011").to_ulong());


    // adres bilgisi dosyaya eklenir.
    f->WriteFile(addressBits.to_string());
    f->ReadFile();

    for(int i=0;i<100;++i)
    {
        cout<<"i: "<<i<<endl;
        cout << "Dongude Adres: " << static_cast<void*>(&f->fileArray[i])<< endl; 
        //uintptr_t address = reinterpret_cast<uintptr_t>(&x[i]);
        cout<<"Deger: "<<bitset<8>(f->fileArray[i])<<endl;
    }



    

        
    // for(int i=0;i<f->getFile().size();++i)
    // {
    //     cout<<"i: "<<i<<endl;
    //     cout << "Dongude Adres: " << static_cast<void*>(&f->getFile()[i]) << endl; 
    //     //uintptr_t address = reinterpret_cast<uintptr_t>(&x[i]);
    //     cout<<"Deger: "<<bitset<8>(f->getFile()[i])<<endl;

    //     // bitset<sizeof(uintptr_t) * 8> addressBits(address);
    //     // uint8_t* ptr = reinterpret_cast<uint8_t*>(address);
    //     // *ptr = 0b00010000;
        
    //     // cout << "Bit olarak adres: " << addressBits << std::endl;
    //     // cout << "Deger: " <<static_cast<int>(*ptr) << std::endl;
    // }



    
    //vector<uint8_t> x = f->getFile();

    // //komutların baslangici PC registerine kaydedilir
    // // pc degeri adress registerine kaydedilir T0
    // // T1: adres registerindeki deger IR regiseteriene atanır pc degeri 1 artırlır

    uint8_t  *PC= r->getPC();
    // //PC = x.data();
    r->setPC(f->fileArray);
    // // //OPCODE degeri IR registerine kaydedilir.
    r->setIR(*r->getPC());
    // // //cout<<"IR: "<<r->getIR()<<endl;


    Commands* c = new Commands();
    string mode = c->AddressModeDecoder(r->getIR());
    string  com = c->CommandDecoder(r->getIR());
    cout<<"mode: "<<mode<<endl;
    cout<<"com: "<<com<<endl;

    Alu* a = new Alu();
    // //bitset<8> b1("00011010"); // İlk bitset
    // //bitset<8> b2("00100101"); // İkinci bitset

    // //a->Add(*r);

    // //cout << "Sum: " << r->getACH()<<r->getACL() << std::endl;

    CommmandCycle* cc = new CommmandCycle();
    
    auto it = cc->functionCommandMap.find("DOLAYLI.ADD");
    if (it != cc->functionCommandMap.end()) {
        it->second(*r,*a);  // Fonksiyonu çağırmak
    } else {
        std::cout << "Command not found." << endl;
    }


    // //bitset<8> bitt = x[0];
    // // cout<<"X.SIZE(): "<<x.size()<<endl;
    
    // for(int i=0;i<x.size();++i)
    // {
    //     cout << "Adres: " << static_cast<void*>(&x[i]) << endl; 
    //     uintptr_t address = reinterpret_cast<uintptr_t>(&x[i]);

    //     // Bellek adresini bit setine dönüştür
    //     bitset<sizeof(uintptr_t) * 8> addressBits(address);
        
    //     cout << "Bit olarak adres: " << addressBits << std::endl;



    //     cout << "Deger (x[i]): " << bitset<8>(x[i]) << endl; 
    //     cout << "Deger (pc): " << bitset<8>(*(r->getPC() + i)) << endl;
    //     cout << "PC Adres: " << static_cast<void*>(r->getPC()) << std::endl;
    //     r->setPC(r->getPC()+1);
    //     //cout<<"bit: "<<bitt<<endl;
    //     //cout<<"gg: "<<gg<<endl;
        
    // }

    // int xx = 10;
    // int* ptr = &xx;

    // Bellek adresini uintptr_t türüne dönüştür
   

    // r->setAR(&x[0]);
    
    // cout<<"r->getar(): "<<static_cast<void*>(r->getAR())<<endl;

    // cout<<"##################################\n";
    // Commands* c = new Commands();
    // string result = c->CommandDecoder(bitset<8>("11010001"));
    // cout<<"result: "<<result<<endl;
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