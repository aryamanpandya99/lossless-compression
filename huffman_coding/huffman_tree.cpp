/*
    Definition of functions required to perform Huffman
    encoding 
*/

#include "huffman_tree.hpp"

using namespace std; 

huffman_tree::huffman_tree()
{
    num_chars_ = 0; 
}

huffman_tree::huffman_tree(string input)
{
    input_string_ = input; 
    num_chars_ = input_string_.length(); 
}

void huffman_tree::process_string(string input)
{
    num_chars_ = input.length(); 
    for (int i = 0; i < num_chars_; i++)
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

    return new_node; 

}

void huffman_tree::swap_nodes(Node** x, Node** y)
{
    Node * tmp; 
    tmp = *x; 
    *x = *y; 
    *y = tmp; 
}

void huffman_tree::freq_map_to_minheap()
{
    min_heap_->arr = new struct Node*[num_chars_]; 
    int i = 0; 
    for (const auto& characters : frequency_map_)
    {
        min_heap_->arr[i]->character = characters.first; 
        min_heap_->arr[i]->frequency = characters.second; 
        i++; 
    } 
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
        swap_nodes(&min_heap_->arr[min], &min_heap_->arr[idx]); 
        heapify(min); 
    }
}

void huffman_tree::buildHeap()
{
    int start = (num_chars_ / 2) - 1; 
    for (int i = start; i >= 0; i--)
    {
        heapify(i); 
    }
}

void huffman_tree::print_heap()
{
    for (int i = 0; i < num_chars_; i++)
    {
        cout << min_heap_->arr[i]->character << ": " << min_heap_->arr[i]->frequency; 
    }
}
