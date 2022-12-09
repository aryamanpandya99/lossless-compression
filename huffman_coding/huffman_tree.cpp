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

Node* huffman_tree::create_node(char alphaNum, int freq)
{
    Node * new_node; 
    new_node->character = alphaNum; 
    new_node->frequency = freq; 
    new_node-> left = nullptr; 
    new_node->right = nullptr; 

}

void huffman_tree::swap_nodes(Node** x, Node** y)
{
    Node * tmp; 
    tmp = x; 
    *x = *y; 
    *y = tmp; 
}

void huffman_tree::heapify(int idx)
{
    int l, r, min = idx; 
    l = 2 * idx + 1; 
    r = 2 * idx + 2; 

    int size = min_heap_->current_size; 

    if(l < size && min_heap_->arr[l]->frequency < min_heap_->arr[idx]->frequency)
    {
        min = l; 
    }
    if(r < size && min_heap_->arr[r]->frequency < min_heap_->arr[min]->frequency)
    {
        min = r; 
    }

    if(min != idx)
    {
        swap_nodes(&min_heap_->arr[min], &min_heap_->arr[idx])
        heapify(min); 
    }
}
