CC = gcc
CFLAGS  = -g -Wall

huffman_coding : huffman_tree.o 
	g++ -o hc main.cpp huffman_tree.o

huffman_tree.o : huffman_tree.cpp
	g++ -c huffman_tree.cpp
