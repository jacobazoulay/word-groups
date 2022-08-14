//
//  solver.cpp
//  word-groups
//
//  Created by Jacob Azoulay on 8/12/22.
//

#include <iostream>
#include <fstream>
#include <vector>
#include<sstream>
#include <cstdlib>
#include "solver.hpp"
using namespace std;


vector<vector<string> > word_loader(ifstream &csv_file) {
    cout << "----Loading Words from .csv----\n";
    string row=NULL;
    int row_n = 0;
    int row_count = 0;
    string word;
    vector<vector<string> > neighborhoods;
    vector<string> neighborhood;
    
    while (getline(csv_file, row)) {
        row_n++;
    }
    
    csv_file.clear();
    csv_file.seekg(0);
    
    float percent;
    while (getline(csv_file, row)){ //read data from file object and put it into string.
        if (row_count % 100 == 0){
            percent = (row_count * 100) / row_n;
            cout << percent << " %\n";
        }
        stringstream row_stream(row);
        while (getline(row_stream, word, ',')) {
            neighborhood.push_back(word);
        }
        neighborhoods.push_back(neighborhood);
        row_count++;
    }
        
    csv_file.close();
    return neighborhoods;
}


int solve(ifstream &csv_file) {
    vector<vector<string> > neighborhoods = word_loader(csv_file);
    
    cout << "----Finding Distinct Word Neighborhoods----\n";
    
    return 0;
}

