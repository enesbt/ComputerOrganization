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
        void ReadFile();
    
        string getFileName();
        vector<uint8_t> getFile();

        File(string);
        ~File();
};




#endif