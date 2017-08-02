#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void menu(void);
void display(node*);

int main(int argc, char **argv) {
  int v;
  node* t = NULL;
  int command = 0;

  menu();

  while(1) {
    printf("\nEnter command: ");
    scanf("%d", &command);

    if (command == -1) {
      break;
    }

    switch(command) {
      case 0:
        menu();
        break;
      case 1:
        printf("Enter a number to prepend: ");
        scanf("%d", &v);
        head = prepend(v, head);
        printf("\n Linked list elements: ");
        traverse(head, display);
        printf("\n Amount of nodes: %d\n", getCount(head));
        printf(" Head value is now: %d, Last value is: %d", head ? head->data : 0, last ? last->data : 0);
        break;
      case 2:
        printf("Enter a number to append: ");
        scanf("%d", &v);
        head = append(v, head);
        printf("\n Linked list elements: ");
        traverse(head, display);
        printf("\n Amount of nodes: %d\n", getCount(head));
        printf(" Head value is now: %d, Last value is: %d\n", head ? head->data : 0, last ? last->data : 0);
        break;
      case 3:
        printf("Enter number to find its pointer in a list: ");
        scanf("%d", &v);
        printf("\n Pointer to Value: %d is: %d, lets access it from pointer to be sure: %d\n", v, find(v, head), find(v, head) ? find(v, head)->data : 0);
        break;
      case 4:
        printf("Enter a number to insert after in the list: ");
        scanf("%d", &v);
        t = find(v, head);
        t ? (
            printf("\nEnter a number to insert: "),
            scanf("%d", &v),
            head = insertAfter(head, v, t),
            printf("\n Linked list elements: "),
            traverse(head, display),
            printf("\n Amount of nodes: %d\n", getCount(head)),
            printf(" Head value is now: %d, Last value is: %d\n", head ? head->data : 0, last ? last->data : 0)
          ) : (
            printf("\nNode with value %d not found\n", v)
          );
        break;
      case 5:
        printf("Enter a number to insert before in the list: ");
        scanf("%d", &v);
        t = find(v, head);
        t ? (
            printf("\nEnter a number to insert: "),
            scanf("%d", &v),
            head = insertBefore(head, v, t),
            printf("\n Linked list elements: "),
            traverse(head, display),
            printf("\n Amount of nodes: %d\n", getCount(head)),
            printf(" Head value is now: %d, Last value is: %d\n", head ? head->data : 0, last ? last->data : 0)
          ) : (
            printf("\nNode with value %d not found\n", v)
          );
        break;
      case 6:
        printf("Deleting front node");
        head = removeFront(head);
        printf("\n Linked list elements: "),
        traverse(head, display),
        printf("\n Amount of nodes: %d\n", getCount(head));
        printf(" Head value is now: %d, Last value is: %d\n", head ? head->data : 0, last ? last->data : 0);
        break;
      case 7:
        printf("Deleting rear node");
        head = removeRear(head);
        printf("\n Linked list elements: "),
        traverse(head, display),
        printf("\n Amount of nodes: %d\n", getCount(head));
        printf(" Head value is now: %d, Last value is: %d\n", head ? head->data : 0, last ? last->data : 0);
        break;
      case 8:
        printf("Enter a number to delete from the list: ");
        scanf("%d", &v);
        t = find(v, head);
        t ? (
            printf("\nDeleting value %d from the list", v),
            head = removeByPointer(head, t),
            printf("\n Linked list elements: "),
            traverse(head, display),
            printf("\n Amount of nodes: %d\n", getCount(head)),
            printf(" Head value is now: %d, Last value is: %d\n", head ? head->data : 0, last ? last->data : 0)
          ) : (
            printf("\nNode with value %d not found\n", v)
          );
        break;
      case 9:
        printf("\nAbout to Sort Linked list using Insertion sort.\n");
        head = sort(head);
        printf("\n Linked list elements: ");
        traverse(head, display);
        printf("\n Amount of nodes: %d\n", getCount(head));
        printf(" Head value is now: %d, Last value is: %d\n", head ? head->data : 0, last ? last->data : 0);
        break;
      case 10:
        printf("Aboout to revers Linked List elements in place\n");
        head = reverse(head);
        printf("\n Linked list elements: ");
        traverse(head, display);
        printf("\n Amount of nodes: %d\n", getCount(head));
        printf(" Head value is now: %d, Last value is: %d\n", head ? head->data : 0, last ? last->data : 0);
        break;
    }
  }

  return EXIT_SUCCESS;
}

void menu()
{
    printf("Singly Linked List\n\n");
    printf("0.menu\n");
    printf("1.prepend an element\n");
    printf("2.append an element\n");
    printf("3.search for an element\n");
    printf("4.insert after an element\n");
    printf("5.insert before an element\n");
    printf("6.remove front node\n");
    printf("7.remove back node\n");
    printf("8.remove any node\n");
    printf("9.sort the list\n");
    printf("10.Reverse the linked list\n");
    printf("-1.quit\n");
}

void display(node* node) {
  if (node != NULL) {
    printf("%d ", node->data);
  }
}