//
//  main.cpp
//  word-groups
//
//  Created by Jacob Azoulay on 8/9/22.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>

using namespace std;

vector<string> parse_words() {
    ifstream inFile;
    vector<string> words;
    
    inFile.open("/Users/jacobazoulay/Repos/word-groups/words_alpha.txt");
    
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


int main(int argc, const char * argv[]) {
    vector<string> words;
    words = parse_words();
    return 0;
    
}
