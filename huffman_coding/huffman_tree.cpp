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

void huffman_tree::process_string()
{
    
    for (int i = 0; i < num_chars_; i++)
    {
        if(frequency_map_.count(input_string_[i]))
        {
            frequency_map_[input_string_[i]]++; 
        }
        else
        {
            frequency_map_.insert(std::pair<char, int>(input_string_[i], 1)); 
        }
    }

}

void huffman_tree::print_map()
{
    cout << "*****" << "Printing map"<< "*****"<<endl; 
    for (const auto& elem : frequency_map_)
    {
        cout << elem.first << " : "<<elem.second << " \n"; 
    }
    cout << "*****" << "Map Printed"<< "*****"<<endl; 
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
    num_chars_unique_ = frequency_map_.size();  
    
    min_heap_->size = num_chars_unique_; 
    min_heap_->arr = (struct Node**)malloc(
        min_heap_->size * sizeof(struct Node*));

    for (int i = 0; i < num_chars_unique_; i++)
    {
        min_heap_->arr[i] = new Node; 
    }

    int i = 0;

    for (const auto& characters : frequency_map_)
    {  
        min_heap_->arr[i]->character = characters.first; 
        min_heap_->arr[i]->frequency = characters.second; 
        i++; 
    } 
    min_heap_->current_size = num_chars_unique_; 
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
    int start = min_heap_->size -1; 
    for (int i = (start -1) / 2; i >= 0; i--)
    { 
        heapify(i); 
    }
}

void huffman_tree::print_heap()
{
    cout << "*****" << "Printing heap"<< "*****"<<endl;  
    for (int i = 0; i < min_heap_->size; i++)
    {
        cout << min_heap_->arr[i]->character << ": "; 
        cout << min_heap_->arr[i]->frequency << "\n"; 
    }
    cout << "*****" << "Heap Printed"<< "*****"<<endl; 
}

struct Node* huffman_tree::pop_min()
{
    struct Node* tmp = min_heap_->arr[0]; 
    min_heap_->arr[0] = min_heap_->arr[min_heap_->current_size - 1]; 

    min_heap_->current_size--; 
    heapify(0); 

    return tmp; 

}
