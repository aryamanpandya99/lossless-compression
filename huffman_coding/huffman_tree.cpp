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

void huffman_tree::process_string(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        if(frequency_map_.count(input[i]))
        {
            frequency_map_[input[i]]++; 
        }
        else
        {
            frequency_map_.insert(std::pair<char, int>(input[i], 1)); 
        }
    }

}

void huffman_tree::print_map()
{
    for (const auto& elem : frequency_map_)
    {
        cout << elem.first << " : "<<elem.second << " \n"; 
    }
}
