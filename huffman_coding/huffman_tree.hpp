/*
    Header file containing class definition of tree for huffman encoding 
    
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std; 

struct Node {
    char character; 
    int frequency; 
    int code; 
    Node* right; 
    Node* left; 
}; 

class huffman_tree {

private:
    Node* head; 
    int total_bits; 
    std::map<char, int> frequency_map_; 

public:
    huffman_tree();
    huffman_tree(string input);
    void process_string(string input);  
    void print_map();     
}; 
