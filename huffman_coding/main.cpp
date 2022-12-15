/*
    Main file for testing/execution of compression 
    Interactive to some extent 
*/

#include <iostream>
#include <vector>
#include "huffman_tree.hpp"

using namespace std; 

int main()
{
    string input; 
    cout << "Enter a string to compress: ";  
    cin >> input; 

    huffman_tree tree(input); 
    tree.process_string(); 
    tree.print_map(); 
    
    tree.freq_map_to_minheap(); 
    tree.print_heap(); 
    
    tree.buildHeap(); 
    cout << "Turning array to min heap\n"; 
    tree.print_heap(); 

    //Node* tmp = tree.pop_min();
    //tree.print_heap(); 
    Node* root = tree.build_huffman_tree();

}
