//
//  main.cpp
//  word-groups
//
//  Created by Jacob Azoulay on 8/9/22.
//

#include "../include/word_extractor.hpp"
#include "../include/solver.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <filesystem>

using namespace std;


int main(int argc, char* argv[]) {
    if (argc == 1){
        ifstream neighbor_file;
        string neighbor_path = filesystem::current_path() / ".." / "assets" / "word_neighbors.csv";
        neighbor_file.open(neighbor_path);

        if (neighbor_file) {
            solve(neighbor_file);
        } else {
            create_neighbors();
        }
        
    } else if (argc == 2 && strcmp(argv[1], "-n") == 0) {
        create_neighbors();
    } else {
        cout << "Invalid arguments.\n";
    }
    
    return 0;
}

// int main() {
//     cout << "Hi";
//     return 0;
// }
