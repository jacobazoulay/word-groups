//
//  word_extractor.hpp
//  word-groups
//
//  Created by Jacob Azoulay on 8/13/22.
//

//#ifndef word_extractor_hpp
//#define word_extractor_hpp
//
//#include <stdio.h>
//
//#endif /* word_extractor_hpp */

#include <vector>
#include <string>
using namespace std;


vector<string> parse_words();
bool distinct(string word, string test_word);
int create_neighbors();
