#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct Stack {
    struct Node *top_node;
    int element_count;
} Stack;

Stack* create_stack() {
    Stack *new_stack = (Stack*)malloc(sizeof(Stack));
    if (!new_stack) {
        exit(EXIT_FAILURE);
    }
    new_stack->top_node = NULL;
    new_stack->element_count = 0;
    return new_stack;
}

Stack* create_stack_vector(int size) {
    Stack *stack_vector = (Stack*)malloc(sizeof(Stack) * size);
    if (!stack_vector) {
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < size; i++) {
        stack_vector[i].top_node = NULL;
        stack_vector[i].element_count = 0;
    }
    return stack_vector;
}

int is_stack_empty(Stack* stack) {
    return (stack == NULL || stack->top_node == NULL);
}

Node* create_node(int value) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void push(Stack* stack, int value) {
    if (stack == NULL) return;
    
    Node *new_node = create_node(value);
    new_node->next = stack->top_node;
    stack->top_node = new_node;
    stack->element_count++;
}

int pop(Stack* stack) {
    if (stack == NULL) return -1;
    if (is_stack_empty(stack)) return -2;
    
    Node *node_to_remove = stack->top_node;
    int removed_value = stack->top_node->value;
    stack->top_node = stack->top_node->next;
    stack->element_count--;
    
    free(node_to_remove);
    return removed_value;
}

int top(Stack* stack) {
    if (stack == NULL) return -1;
    if (is_stack_empty(stack)) return -2;
    return stack->top_node->value;
}

int stack_size(Stack* stack) {
    if (stack == NULL) return 0;
    return stack->element_count;
}

void print_stack(Stack* stack) {
    if (stack == NULL) {
        printf("Stack does not exist!\n");
        return;
    }
    
    printf("Stack (quantity: %d): [", stack->element_count);
    
    Node *current_node = stack->top_node;
    while (current_node) {
        printf("%d", current_node->value);
        if (current_node->next) printf(" -> ");
        current_node = current_node->next;
    }
    printf("]\n");
}

void free_stack(Stack* stack) {
    if (stack == NULL) return;
    
    Node *current_node = stack->top_node;
    while (current_node) {
        Node *temp_node = current_node;
        current_node = current_node->next;
        free(temp_node);
    }
    free(stack);
}

void free_stack_vector(Stack* stack_vector, int size) {
    if (stack_vector == NULL) return;
    
    for (int i = 0; i < size; i++) {
        Node *current_node = stack_vector[i].top_node;
        while (current_node) {
            Node *temp_node = current_node;
            current_node = current_node->next;
            free(temp_node);
        }
    }
    free(stack_vector);
}

Stack* get_coordinates_function(Stack* pegs){
    int initial;
    int final;
    int store = 0;
    printf("\nFrom which stack do you want to remove?");
    scanf("%d", &initial);
    printf("\nNow, in which stack do you want to place?");
    scanf("%d", &final);
    
    if(initial < 1 || initial > 4 || final < 1 || final > 4){
        printf("Invalid stack!!\n");
        return pegs;
    }
    
    initial = initial - 1;
    final = final - 1;
    
    if(pegs[initial].top_node == NULL){
        printf("Source stack is empty!!\n");
        return pegs;
    }
    
    if(pegs[final].top_node == NULL || pegs[initial].top_node->value < pegs[final].top_node->value){
        store = pop(&pegs[initial]);
        push(&pegs[final], store);
    }
    else{
        printf("Invalid move!!\n");
        return pegs;
    }
    
    return pegs;
}

int check_victory(Stack* peg_4){
    if(peg_4 != NULL && peg_4->element_count == 4){
        return 1;  
    }
    else{
        return 0;  
    }
}

void print_function(Stack* pegs) {
    printf("\n*** TOWER OF HANOI ***\n");
    
    for (int i = 0; i < 4; i++) {
        printf("Tower %d: ", i + 1);
        
        if (pegs[i].top_node == NULL) {
            printf("Empty");
        } else {
            Node* current = pegs[i].top_node;
            while (current != NULL) {
                printf("[%d]", current->value);
                if (current->next != NULL) printf(" -> ");
                current = current->next;
            }
        }
        printf("\n");
    }
    
    printf("\nVisual representation:\n");
    int max_height = 4;
    
    for (int level = max_height - 1; level >= 0; level--) {
        for (int tower = 0; tower < 4; tower++) {
            int disk_qty = stack_size(&pegs[tower]);
            
            if (level < disk_qty) {
                Node* current = pegs[tower].top_node;
                for (int j = 0; j < (disk_qty - level - 1); j++) {
                    current = current->next;
                }
                printf("  %d  ", current->value);
            } else {
                printf("  |  ");
            }
        }
        printf("\n");
    }
    
    for (int i = 0; i < 4; i++) {
        printf("-----");
    }
    printf("\n");
    
    for (int i = 0; i < 4; i++) {
        printf("  %d  ", i + 1);
    }
    printf("\n\n");
}

int main(void) {
    Stack* pegs = create_stack_vector(4);
    int victory = 0;
    
    for(int i = 4; i > 0; i--) {
        push(&pegs[0], i);
    }
    
    while(victory == 0){
        print_function(pegs);
        pegs = get_coordinates_function(pegs);
        victory = check_victory(&pegs[3]);
    }
    
    free_stack_vector(pegs, 4);
    return 0;
}
