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
    Node* left; 
    Node* right;  
}; 

struct minheap {
    int size, current_size; 
    struct Node** arr; 
};

class huffman_tree {

private:
    struct minheap* min_heap_; 
    int num_chars_, num_chars_unique_;  
    std::string input_string_; 
    std::map<char, int> frequency_map_; 

public:
    huffman_tree();
    huffman_tree(string input);
    
    void process_string();  
    void print_map();   
    
    Node* create_node(char character, int frequency); 
    void freq_map_to_minheap(); 
    void swap_nodes(Node** x, Node** y);   
    
    void heapify(int idx); 
    void buildHeap(); 
    void print_heap(); 
    struct Node* pop_min(); 
    void insert_heap_node(Node* a); 

    void build_huffman_tree();

}; 
