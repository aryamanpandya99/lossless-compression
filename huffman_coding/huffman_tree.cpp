/*
    Definition of functions required to perform Huffman
    encoding 
*/

#include "huffman_tree.hpp"

using namespace std; 

huffman_tree::huffman_tree()
{
    head = nullptr; 
}

huffman_tree::huffman_tree(string input)
{
    process_string(input); 
}

std::map<char, int> huffman_tree::process_string(string input)
{
    
}