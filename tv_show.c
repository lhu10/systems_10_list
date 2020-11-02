#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tv_show.h"

struct tv *new_show(char *n, int e){
    struct tv *ns; 
    ns = malloc(sizeof(struct tv)); 
    
    strncpy(ns->series_name, n, sizeof(ns->series_name)-1);  
    ns->eps = e; 
    ns->next = NULL; 

    return ns; 
}

void modify(struct tv *ns, char *name, int ne){
    strncpy(ns->series_name, name, sizeof(ns->series_name)-1);   
    ns->eps = ne; 
}

void watch(struct tv *ns){
    printf("You're now watching:\n"); 
    printf("\t%s with %d episodes\n", ns->series_name, ns->eps); 
}

struct tv *free_tv(struct tv *ns){
    free(ns); 
    return NULL; 
}

void print_list(struct tv *list){
    printf("["); 
    while(list != NULL){
        printf("(%s, %d) \n", list->series_name, list->eps); 
        list = list->next;  
    }
    printf(" "); 
    printf("]\n\n"); 
}

struct tv *insert_front(struct tv *list, char *n, int e){
    struct tv *show0 = new_show(n, e);
    show0->next = list; 
    return show0; 
}

struct tv *free_list(struct tv *list){
    struct tv *next_pointer = list->next;
    struct tv *lp = list;  

    while(lp != NULL){
        lp = free_tv(lp);      
        lp = next_pointer; 
        if(next_pointer != NULL)
            next_pointer = next_pointer->next; 
    }
    list = NULL; 
    return list; 
} 

struct tv *remove_node(struct tv *front, char *n, int e){
    struct tv *next_pointer = front->next;
    struct tv *lp = front;
    struct tv *prev = front;   
    //checking if first one matches
    if(strcmp(n, lp->series_name) == 0 && lp->eps == e){
        front = lp->next; 
        return front; 
    }

    while(next_pointer != NULL){
        lp = next_pointer; 
        if(strcmp(n, lp->series_name) == 0 && lp->eps == e){
            prev->next = lp->next; 
            free(lp);  
        }

        prev = next_pointer;     
        next_pointer = next_pointer->next;  
    }
 
    return front;
    
}
