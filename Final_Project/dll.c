#include "dll.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

DLL * createList() {
    DLL *list = (DLL*)malloc(sizeof(DLL));
    if (list != NULL) {
        list->head = NULL; //Indicated an empty list
    }
    return list;
}

int listEmpty(DLL *list) {
    if (list == NULL || list->head == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void insert(DLL *list, Node *newNode) {
    if (list == NULL || newNode == NULL) return;
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    Node *current = list->head;
    Node *previous = NULL;


    while (current != NULL && strcmp(current->data, newNode->data) < 0) {
        previous = current;
        current = current->next;
    }
    //new head (head insertion)
    if (previous == NULL) {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    } else { //middle insertion
        newNode->next = current;
        newNode->prev = previous;
        previous->next = newNode;
        if (current != NULL) {
            current->prev = newNode;
        }
    }
}

void displayList(DLL *list, char startChar) {
    if (listEmpty(list)) {
        printf("This list is empty.\n");
        return;
    }
    printf("List: ");
    Node *current = list->head;
    int firstMatch = 1; //I use this variable to make sure I dont print the delimiter in the wrong place. 
    while (current != NULL) {
        if (current->data[0] > startChar) {
            break;
        }
        if (current->data[0] == startChar) {
            if (!firstMatch) {
                printf(" <-> ");
            }
            printNode(current);
            firstMatch = 0; // printed the first node, so from now on we dont need this check. 
        }
        current = current->next;
    }
    printf("\n");
}

Node *search(DLL *L, char * key) {
    if (L == NULL || L->head == NULL) {
        return NULL; //If the list head or the entire list is empty, then there is nothing we can look for
    }

    Node *current = L->head; //Start the search by from the beginning.
    while (current != NULL) {
        int comparison = strcmp(current->data, key); //this compers the current string with the keyword
        if (comparison == 0) { //If strcmp returns 0, then the ASCII value of the strings are the same, so the match is found
            return current;
        } else if (comparison > 0) { //If the strcmp returns a positive number, that means we stepped out of the interval of the list where we would find the searched eloement, because of alphabetical order. Save time and resources.
            break;
        }
        current = current->next;
    }
    return NULL; //If the loop breaks, then we did not find matching data, so it wa not in the list
}

void Remove(DLL *L, Node *ptr) {
    if (L == NULL || L->head == NULL || ptr == NULL) { //Tested for NULL ptr
        return;
    }
    //We remove the head
    if (L->head == ptr) {
        L->head = ptr->next; //we remove the head of the list, so we just set the head pointer to the next node
    }
    //IF not the first node
    if (ptr->prev != NULL) {
        ptr->prev->next = ptr->next; //Rearrange the prev node's next pointer 
    }

    if (ptr->next != NULL) {
        ptr->next->prev = ptr->prev; //Rearrange the next node's prev pointer
    }
    free(ptr); //After the pointers are changed, delete the node.
}

void loadTextFile(DLL *L, char * filename) {
    if (L == NULL || filename == NULL){ // Simple safety check
        return;
    }

    FILE *file = fopen(filename, "r"); // we open the file for reading
    if (file == NULL) {
        printf("Error occured, file could not be opened. \n");
        return;
    }

    char buffer[17]; //I set the buffer for 17, because task said 15 chars max + the new line character and +1 for the null terminator. 
    while (fgets(buffer, sizeof(buffer), file) != NULL) { //fgets puts text into the buffar that we handle later, (leaves space for null terminator), when it hits the end of the file, returns NULL and terminates. 
        buffer[strcspn(buffer, "\n")] = '\0'; // strcspn reads the srting char by char and stops when it hits \n, then returns the integer of successfully read chars. then overwrited the \n with \0. 

        Node *newNode = createNode(buffer);
        if (newNode != NULL) {
            insert(L, newNode);
        }
    }
    fclose(file);
    printf("Elements are successfully loaded from file.\n");
    
}

void storeTextFile(DLL *L, char * filename) {
    if (L == NULL || filename == NULL) { //Simple check
        return;
    }
    FILE *file = fopen(filename, "w"); //Open file for writing
    if (file == NULL) {
        printf("Error occured, file could not be opened.\n");
        return;
    }

    if (L->head == NULL) { // If the List is empty, we close the file, because there is nothing to save.
        fclose(file);
        return;
    }
    Node *current = L->head; //We go the the beginning of the list and loop through it till the end. 
    while (current->next != NULL) {
        current = current->next;
    }

    while (current != NULL) { // We are at the end of the list, adn we start to go backwards with a loop and save elements, because it will be faster to load them back. (No extensive comparisons needed.)
        fprintf(file, "%s\n", current->data);
        current = current->prev;
    }
    fclose(file);
    printf("Elements successfully saved.");
}

void freeList(DLL *L) {
    if (L == NULL){
        return;
    }
    Node *current = L->head;
        while (current != NULL) {
            Node *temporary = current;
            current = current->next;
            free(temporary);
        }
        free(L);
}
