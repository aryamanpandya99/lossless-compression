/*
    Header file containing class definition of tree for huffman encoding 
    
*/

//build a minheap and then use this as a priority queue 

#include <iostream>
#include <vector>
#include <map>
using namespace std; 

struct Node {
    char character; 
    int frequency; 
    int code; 
    Node* left, right; 
}; 

class huffman_tree {

private:
    Node** array; 
    int size, total_size;  
    std::map<char, int> frequency_map_; 

public:
    huffman_tree();
    huffman_tree(string input);
    void process_string(string input);  
    void print_map();   
    void create_node(char character, int frequency); 
    void swap_nodes(Node* x, Node* y);   
    void heapify(int idx); 

}; 
