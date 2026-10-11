#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    char key[50];
    int value;
    struct Node *next;
};

struct HashTable{
    struct Node *buckets[10];
};

void inittable (struct HashTable *table)
{
    for(int i = 0; i < 10; i++)
    {
        table->buckets[i] = NULL;
    }
}

int hash(char *key)
{
   int sum = 0;
   for(int i = 0; key[i] != '\0'; i++)
   {
       sum += key[i];
   }
   return sum % 10;
}

void insert(struct HashTable *table, char *key, int value) {
    struct Node *newnode = malloc(sizeof(struct Node));
    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(newnode->key,key);
    int hashkey = hash(key);
    newnode->value=value;
    newnode->next=table->buckets[hashkey];
    table->buckets[hashkey]=newnode;
}

int search(struct HashTable *table,char *key)
{
    int hashkey=hash(key);
    struct Node *current_node = table->buckets[hashkey];
    while(current_node != NULL)
    {
        if(strcmp(current_node->key,key)==0)
        {
            return current_node->value;
        }
        current_node=current_node->next;

    }
    return -1;
}

void freeTable(struct HashTable *table)
{
    for(int i =0;i<10;i++)
    {
        struct Node *current_node = table->buckets[i];
        while(current_node!= NULL)
        {
                struct Node *tmp=current_node->next;
                free(current_node);
                current_node=tmp;
        }
        table->buckets[i]=NULL; 
    }
  
}

int removeKey(struct HashTable *table, char *key)
{
    int hashkey=hash(key);
    struct Node *current_node=table->buckets[hashkey];
    struct Node *back_node =NULL;
    if(current_node != NULL)
    {
        while(strcmp(current_node->key,key) != 0)
        {
          if(current_node->next == NULL)
          {
            return 0;
          }
          else
          {
            back_node = current_node;
            current_node =current_node->next;
          }
        }
        if(back_node != NULL)
        {
            back_node->next=current_node->next;
        }
        if(back_node == NULL)
        {
            table->buckets[hashkey]=current_node->next;
        }
        free(current_node);
        return 1;
    }
    return 0;
}

int main (void)
{
    struct HashTable table;
    inittable(&table);
    insert(&table, "mangomango", 32);
    insert(&table, "mango", 12);
    insert(&table, "apple", 5);
    removeKey(&table,"mango");
    printf("%d\n", search(&table, "mangomango"));
    printf("%d\n", search(&table, "mango"));
    printf("%d\n", search(&table, "apple"));
    printf("%d\n", search(&table, "banana"));  
    freeTable(&table);
}

