//
//  word_extractor.cpp
//  word-groups
//
//  Created by Jacob Azoulay on 8/13/22.
//

#include "../include/word_extractor.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <filesystem>

using namespace std;


vector<string> parse_words() {
    string inFile_path = filesystem::current_path() / ".." / "assets" / "words_alpha.txt";
    ifstream inFile;
    vector<string> words;
    
    cout << "----Getting Words----\n";
    
    inFile.open(inFile_path);
    
    
    if (!inFile) {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }
    
    string word;
    while (getline(inFile, word)){ //read data from file object and put it into string.
        word.pop_back();
        if (word.length() == 5) {
            set <char> word_set(begin(word), end(word));
            if (word_set.size() == 5){
                words.push_back(word);
            }
        }
    }
        
    inFile.close();
    return words;
}


bool distinct(string word, string test_word) {
    string concat_word = word + test_word;
    bool distinct;
    set <char> word_set(begin(concat_word), end(concat_word));
    if (word_set.size() == 10) {
        distinct = true;
    } else {
        distinct = false;
    }
    return distinct;
}


int create_neighbors() {
    vector<string> words;
    
    words = parse_words();
    
    vector< vector<string> > neighbors(words.size());
    
    cout << "----Creating Neighbors----\n";
    float percent;
    
    for (int i = 0; i < words.size(); i++) {
        if (i % 100 == 0){
            percent = (i * 100) / words.size();
            cout << percent << " %\n";
        }
        for (int j = 0; j < words.size(); j++) {
            if (distinct(words[i], words[j])) {
                neighbors[i].push_back(words[j]);
            }
        }
    }
    
    ofstream csv_neighbors("word_neighbors.csv");
    for (int i = 0; i < words.size(); i++) {
        csv_neighbors << words[i];
        for (int j = 0; j < neighbors[i].size(); j++) {
            csv_neighbors << "," << neighbors[i][j];
            }
        csv_neighbors << "\n";
        }
    csv_neighbors.close();
    
    return 0;
}
