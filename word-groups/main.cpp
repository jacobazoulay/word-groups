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

using namespace std;


int main(int argc, const char * argv[]) {
    ifstream inFile;
    vector<string> words;
    
    inFile.open("/Users/jacobazoulay/Repos/word-groups/words_alpha.txt");
    
    if (!inFile) {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }
    
    string tp;
    while (getline(inFile, tp)){ //read data from file object and put it into string.
        if (tp.length() == 6) {
            tp.pop_back();
            words.push_back(tp);
        }
    }
    
    for (string i: words) {
        cout << i << '\n';
    }
        
    inFile.close();
    return 0;
    
}
