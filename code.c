#include <Stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;

node* create_node(int data){
    node* new_node =(node*)malloc(sizeof(node));
    if(new_node==NULL){
        return NULL;
    }
    new_node->data=data;
    new_node->next = NULL;
    return new_node;
}
node* insert_at_beginning(node* head, int data){
    node* new = create_node(data);
    new->data=data;
    if(head==NULL){
        new->next=new;
    }
    node* current = head;
    node* tail = NULL;
    while(current->next!=head){
        current = current->next;
    }
    tail = current;
    tail->next = new;
    new->next=head;
    head = new;
    return head;
}
node* remove_at_beginning(node** head){
    if(*head==NULL){
        return NULL;
    }
    if((*head)->next==*head){
        free(*head);
        *head=NULL;
        return NULL;
    }
    node* current  = *head;
    while(current->next!=*head){
        current = current->next;
    }
    current->next=(*head)->next;
    node* new_head = (*head)->next;
    free(*head);
    return new_head;
}
node* insert_at_end(node* head, int data){
    if(head==NULL){
        head = insert_at_beginning(head,data);
        return head;
    }
    node* current = head;
    while(current->next!=head){
        current = current->next;
    }
    node* new = (node*)malloc(sizeof(node));
    if(new==NULL){
        return head;
    }
    new->data = data;
    new->next = head;
    current->next = new;
    return head;
}
node* delete_at_end(node** head){
    node* current = *head;
    if(*head==NULL){
        return NULL;
    }
    if((*head)->next==*head){
        remove_at_beginning(head);
        return NULL;
    }
    node* prev = *head;
    while(current->next!=*head){
        prev = current;
        current = current->next;
    }
    prev->next=*head;
    free(current);
    return *head;
}
node* add_at_pos(node* head, int data, int position){
    if(head==NULL){
        return insert_at_beginning(head,data);
    }
    node* current = head;
    if(current->next == head){
        insert_at_end(head,data);
    }
    int i = 0;
    while(i<position-1&&current->next!=head){
        current = current->next;
        i++;
    }
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = current->next;
    current->next = new;
    return head;
}
void is_circular(node* head){
    if(head==NULL){
        printf("not circular");
    }
    node* current = head;
    while(current==NULL){
        if(current->next!=head){
            printf("is circular");
            return;
        }
        current = current->next;
    }
    printf("not circular");
}
