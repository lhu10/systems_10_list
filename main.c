#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tv_show.h"

int main(){
    
    struct tv *show1, *show2, *show3;
    printf("Printing empty list:\n");
    print_list(NULL);   
    
    show1 = new_show("Clifford the Big Red Dog", 65);
    show2 = new_show("Avatar: The Last AirBender", 61);
    show3 = new_show("Over the Garden Wall", 10);
     
    show2->next = show1; 
    show1->next = show3; 

    printf("Printing list:\n");
    print_list(show2);

    printf("Inserting Gravity Falls in front:\n");
    struct tv *show0 = insert_front(show2, "Gravity Falls", 40); 
    print_list(show0); 

    printf("Removing Clifford:\n"); 
    show0 = remove_node(show0, "Clifford the Big Red Dog", 65); 
    print_list(show0); 

    printf("Removing Over the Garden Wall:\n"); 
    show0 = remove_node(show0, "Over the Garden Wall", 10); 
    print_list(show0);

    printf("Freeing list:\n");
    show0 = free_list(show0); 
    print_list(show0); 

    return 0; 
}
