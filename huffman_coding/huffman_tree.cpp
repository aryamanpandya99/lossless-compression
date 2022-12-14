/*
    Definition of functions required to perform Huffman
    encoding 
*/

#include "huffman_tree.hpp"
#include <string>

using namespace std; 

char COUNTER_CHAR = '#'; 

huffman_tree::huffman_tree()
{
    num_chars_ = 0; 
    top_ = new Node;
}

huffman_tree::huffman_tree(string input)
{
    input_string_ = input; 
    num_chars_ = input_string_.length(); 
    top_ = new Node;
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
    
    min_heap_->size = 2 * num_chars_unique_; 
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
    for (int i = 0; i < min_heap_->current_size; i++)
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


void huffman_tree::insert_heap_node(Node* a)
{
    if(min_heap_->current_size == min_heap_->size)
    {
        cout << "Heap Overflow\n"; 
        return; 
    }

    min_heap_->current_size++; 
    int i = min_heap_->current_size - 1; 

    while(i > 0 && min_heap_->arr[(i-1)/2]->frequency > a->frequency)
    {
        min_heap_->arr[i] = min_heap_->arr[(i-1)/2]; 
        i = (i-1) / 2; 
    }

    min_heap_->arr[i] = a; 
}

string huffman_tree::arr_to_str(int tree[], int n)
{
    string out; 
    for(int i = 0; i < n; i++)
    {
        out+=to_string(tree[i]); 
    }
    
    return out; 
}

Node* huffman_tree::build_huffman_tree()
{
    struct Node* left, * right, * top; 
    
    while(min_heap_->current_size != 1)
    {
        left = pop_min(); 
        right = pop_min(); 

        top = new Node; 
 
        top->character = COUNTER_CHAR;
        top->frequency =  left -> frequency + right->frequency; 

        top -> left = left; 
        top -> right = right; 

        insert_heap_node(top);
    }

    return pop_min(); 

}

void huffman_tree::print_huffman_codes(Node* root)
{
    int array[min_heap_->current_size * 2], n = 0;  
    print_tree(root, array, n); 
}

void huffman_tree::print_tree(Node* root, int tree[], int idx)
{ 
    if(root->left)
    {
        tree[idx] = 0; 
        print_tree(root->left, tree, idx+1); 
    }
    if(root->right)
    {
        tree[idx] = 1; 
        print_tree(root->right, tree, idx+1); 
    }

    if(!root->left&&!root->right)
    {
        std::string code = arr_to_str(tree, idx); 
        cout <<"Character: "<<root->character<<", code: "<<code<<endl; 
    }

}
