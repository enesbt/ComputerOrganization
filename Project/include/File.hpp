#ifndef FILE_HPP
#define FILE_HPP

#include<iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

struct File
{
    private:
        vector<uint8_t> file;
        
        string fileName;
        

    public:
        int loc;
        uint8_t* fileArray;
        void ReadFile();
        void WriteFile(string);
    
        string getFileName();
        vector<uint8_t> getFile();

        File(string);
        ~File();
};




#endif