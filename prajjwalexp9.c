#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
    int data;
    struct node *next;
};

struct node* newnode(int num) {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = num;
    temp->next = NULL;
    return temp;
}

struct node* add_last(struct node *head, int num) {
    struct node *temp, *p;
    if (head == NULL) {
        temp = newnode(num);
        return temp;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        p = newnode(num);
        temp->next = p;
        return head;
    }
}

void traverse(struct node *p) {
    while (p != NULL) {
        printf("<-%d->\n", p->data);
        p = p->next;
    }
}

struct node* add_first(struct node *head, int num) {
    struct node *p = newnode(num);
    p->next = head;
    return p;
}

int count(struct node *p) {
    int i = 0;
    while (p != NULL) {
        i++;
        p = p->next;
    }
    return i;
}

void search(struct node *p, int key) {
    while (p != NULL) {
        if (key == p->data) {
            printf("FOUND\n");
            return;
        }
        p = p->next;
    }
    printf("NOT FOUND\n");
}

struct node* ins_pos(struct node *head, int num, int pos) {
    struct node *temp, *q, *insnode;
    int p, items;
    items = count(head);
    if (head == NULL) {
        return newnode(num);
    } else if (pos == 0) {
        return add_first(head, num);
    } else if (pos == items) {
        return add_last(head, num);
    } else {
        temp = head;
        for (p = 0; p < pos - 1 && temp != NULL; p++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Unable to insert node\n");
            return head;
        } else {
            insnode = newnode(num);
            insnode->next = temp->next;
            temp->next = insnode;
            return head;
        }
    }
}

struct node* delete_node(struct node *head) {
    struct node *p;
    while (head != NULL) {
        p = head;
        head = head->next;
        free(p);
    }
    return head;
}

struct node* del_first(struct node *head) {
    struct node *temp;
    if (head == NULL) {
        printf("Unable to delete the node\n");
    } else {
        temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

struct node* del_last(struct node *head) {
    struct node *prev = NULL, *temp;
    if (head == NULL) {
        printf("Unable to delete the node\n");
        return head;
    } else {
        for (temp = head; temp->next != NULL; temp = temp->next) {
            prev = temp;
        }
        if (prev != NULL) {
            prev->next = NULL;
        } else {
            head = NULL;
        }
        free(temp);
    }
    return head;
}

struct node* del_pos(struct node *head, int pos) {
    struct node *temp, *prev;
    int p;
    if (head == NULL) {
        printf("Unable to delete the node\n");
        return head;
    }
    if (pos == 0) {
        return del_first(head);
    }
    temp = head;
    for (prev = NULL, p = 0; temp != NULL && p < pos; prev = temp, temp = temp->next, p++);
    
    if (prev == NULL || temp == NULL) {
        printf("Unable to delete node\n");
    } else {
        prev->next = temp->next;
        free(temp);
    }
    return head;
}

void main() {
    struct node *head = NULL;
    int num, pos, choice;

    clrscr();

    while (1) {
        printf("MENU:\n");
        printf("1. ADD_FIRST\n2. ADD_LAST\n3. INS_AT_POS\n4. DISPLAY\n5. SEARCH\n");
        printf("6. COUNT_NODES\n7. DELETE_LIST\n8. DELETE_FIRST\n9. DELETE_LAST\n");
        printf("10. DELETE_POSITION\n11. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Insertion of element at the first position:\n");
                printf("Enter the element for list:\n");
                scanf("%d", &num);
                head = add_first(head, num);
                break;

            case 2:
                printf("Insertion of element at the last position:\n");
                printf("Enter the element for list:\n");
                scanf("%d", &num);
                head = add_last(head, num);
                break;

            case 3:
                printf("Enter position of element:\n");
                scanf("%d", &pos);
                printf("Enter the element for list:\n");
                scanf("%d", &num);
                head = ins_pos(head, num, pos);
                break;

            case 4:
                if (head == NULL) {
                    printf("List is Empty:\n");
                } else {
                    traverse(head);
                }
                break;

            case 5:
                printf("Enter the element to search:\n");
                scanf("%d", &num);
                search(head, num);
                break;

            case 6:
                printf("Number of nodes in the list are %d\n", count(head));
                break;

            case 7:
                head = delete_node(head);
                break;

            case 8:
                head = del_first(head);
                break;

            case 9:
                head = del_last(head);
                break;

            case 10:
                printf("Enter the position to delete:\n");
                scanf("%d", &pos);
                head = del_pos(head, pos);
                break;

            case 11:
                head = delete_node(head);
                return;

            default:
                printf("WRONG CHOICE\n");
        }
    }
    getch();
}
