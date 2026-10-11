# Hash-Table
This is a simple hash table built to better understand data structures and the use of malloc and free.Its an array of 10 buckets which contains
pointers to nodes which contain 3 values(1.the key 2.value 3.pointer to the next node)collisions are handled by chaining the items in a linked list 
It has fucntions to search through the buckets and nodes for a given key, to insert any key into the table using a hash function to turn t he key into 
a number between 0 to 9, remove function to remove any key from the table and a free table function to free all memory after the program is done 
so there are no memory leaks.The limitations are that theres only 10 buckets, it currently dosent update when an existing key when one of the same 
key is entered,the hash function is weak as it only adds up the ascii values of the letters and takes the modulus of 10,and needs to add a way to take user input as the inputs are hardcoded in.
