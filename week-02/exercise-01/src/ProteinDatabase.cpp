#include <iostream>
#include <string>
//#include <chrono>
#include <iomanip>
#include <fstream>
#include "ProteinDatabase.h"

namespace seneca {




    ProteinDatabase::ProteinDatabase(std::string name){
        ProteinDatabase::fileName = name;
        std::ifstream fin;
        fin.open(name);
        char c{};
        std::string line{};

        while (std::getline(fin, line)) {
            if (!line.empty() && line[0] == '>') cnt++;
        }
        // while (fin.get(c)){
        //     if (c == '>')
        //     ProteinDatabase::cnt++;
        // }
        ProteinDatabase::IDs = new std::string[cnt];
        ProteinDatabase::acids = new std::string[cnt];

        fin.clear();
        fin.seekg(0);
        for (int i = 0; i < cnt && !fin.fail(); i++){
            fin.ignore(1000, '|');
            getline(fin, ProteinDatabase::IDs[i], '|');
            //std::cout << ProteinDatabase::IDs[i] << std::endl;
            fin.ignore(1000, '\n');
            std::string temp;
            char mark{};
            std::streampos pos {};
            while (mark != '>' ){
                pos = fin.tellg();
                if (!getline(fin, temp, '\n')) {
                    //std::cout << ProteinDatabase::acids[23011] << std::endl << ProteinDatabase::IDs[23010];
                    break;}
                mark = temp[0];
                if (mark != '>'){
                    ProteinDatabase::acids[i].append(temp);
                    //std::cout << ProteinDatabase::acids[i] << std::endl;
                } else {
                    fin.seekg(pos);
                }
                
            }

        }

    }

    // Destructor
    ProteinDatabase::~ProteinDatabase() {
        delete[] IDs;
        delete[] acids;
    }

    // Copy Constructor
    ProteinDatabase::ProteinDatabase(const ProteinDatabase& src) {
        *this = src; // Use copy assignment operator
    }

    // Copy Assignment
    ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& src) {
        if (this != &src) {
            delete[] IDs;
            delete[] acids;
            cnt = src.cnt;
            fileName = src.fileName;
            if (cnt > 0) {
                IDs = new std::string[cnt];
                acids = new std::string[cnt];
                for (int i = 0; i < cnt; ++i) {
                    IDs[i] = src.IDs[i];
                    acids[i] = src.acids[i];
                }
            } else {
                IDs = nullptr;
                acids = nullptr;
            }
        }
        return *this;
    }

    // Move Constructor
    ProteinDatabase::ProteinDatabase(ProteinDatabase&& src) {
        *this = std::move(src); // Use move assignment operator
    }

    // Move Assignment
    ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& src) {
        if (this != &src) {
            delete[] IDs;
            delete[] acids;
            cnt = src.cnt;
            fileName = std::move(src.fileName);
            IDs = src.IDs;
            acids = src.acids;
            src.IDs = nullptr;
            src.acids = nullptr;
            src.cnt = 0;
        }
        return *this;
    }

    size_t ProteinDatabase::size () {
        return cnt;
    };
        std::string ProteinDatabase::operator[](size_t index) {
            if (index < cnt)
            return acids[index];
            else return "";
        };


        std::string ProteinDatabase::getUID(size_t index) {
            if (index < cnt)
            return IDs[index];
            else return "none";

        };



        // Faster version of the 1-arg constructor
        // ProteinDatabase::ProteinDatabase(std::string name) {
        //     fileName = name;
        //     std::ifstream fin(name);
        //     if (!fin) {
        //         cnt = 0;
        //         IDs = nullptr;
        //         acids = nullptr;
        //         return;
        //     }

        //     // First pass: count proteins
        //     cnt = 0;
        //     std::string line;
        //     while (std::getline(fin, line)) {
        //         if (!line.empty() && line[0] == '>') cnt++;
        //     }

        //     IDs = new std::string[cnt];
        //     acids = new std::string[cnt];

        //     // Second pass: extract IDs and acids
        //     fin.clear();
        //     fin.seekg(0);

        //     int idx = -1;
        //     while (std::getline(fin, line)) {
        //         if (!line.empty() && line[0] == '>') {
        //             idx++;
        //             // Extract ID between first and second '|'
        //             size_t first = line.find('|');
        //             size_t second = line.find('|', first + 1);
        //             if (first != std::string::npos && second != std::string::npos && second > first)
        //                 IDs[idx] = line.substr(first + 1, second - first - 1);
        //             else
        //                 IDs[idx] = "";
        //         } else if (idx >= 0) {
        //             acids[idx] += line;
        //         }
        //     }
        // }


}