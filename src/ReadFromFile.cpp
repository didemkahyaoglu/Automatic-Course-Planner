#include "ReadFromFile.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

ReadFromFile::ReadFromFile(){};
ReadFromFile::~ReadFromFile(){};

vector<vector<std::string>> ReadFromFile::read_record(string fileName)
{
    ifstream fin;
    vector<vector<string>> csv;
	vector<string> row;
	string line, word;

    try{

        fin.open(fileName, ios::in);

		if(fin.is_open() == false){
			throw "Exception opening/reading/closing file\n";
		}

			while (!fin.eof()) {	//dosya sonuna ulaþýldýðýnda bitiyor.
                getline(fin, line);
                if(line == ""){
					continue;
				}
				stringstream s(line);
				while (getline(s, word, ';')) {

					row.push_back(word);

				}
		            csv.push_back(row);
		            row.clear();
			}
	        fin.close();

         }catch(const char* msg){
            cerr << msg << "\n";
        }
        return csv;

}


