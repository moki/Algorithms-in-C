#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "node.h"

node* head = NULL;
node* last = NULL;
int count = 0;

node* create(int data, node* next) {
  node* newnode = (node*) malloc(sizeof(node));

  if (!newnode) {
    printf("Error: failed to create new node.\n");
    exit(EXIT_FAILURE);
  }

  newnode->data = data;
  newnode->next = next;

  count++;

  return newnode;
}

node* prepend(int data, node* head) {
  node* newnode = create(data, head);
  
  if (!head) {
    head = last = newnode;
  }

  return head = newnode;
}

node* append(int data, node* head) {
  node* newnode = create(data, NULL);

  if (!head) {
    head = last = newnode;
  } else {
    last->next = newnode;
    last = newnode;
  }

  return head;
}

node* find(int data, node* head) {
  for(node* cursor = head; cursor; cursor = cursor->next) {
    if (cursor->data == data) {
      return cursor;
    }
  }

  return NULL;
}

node* insertAfter(node* head, int data, node* target) {
  if (!target) {
    printf("\nno such target\n");
    return NULL;
  }

  node* newnode;

  if (!target->next) {
    newnode = create(data, NULL);
    last = newnode;
  } else {
    newnode = create(data, target->next);
  }

  target->next = newnode;

  return head;
}

node* insertBefore(node* head, int data, node* target) {
  if (!target) {
    printf("\nno such target\n");
    return NULL;
  }

  node* newnode = create(data, target);

  if (target == head) {
    printf("\ntarget node to insert before is head\n");
    return head = newnode;
  }

  node* cursor = head;

  while (cursor) {
    if (cursor->next == target) {
      break;
    }

    cursor = cursor->next;
  }

  cursor->next = newnode;

  return head;
}


node* removeFront(node* head) {
  if (!head) {
    return NULL;
  }

  if (!head->next) {
    clean(head);
    return head = last = NULL;
  }

  node* newhead = head->next;
  clean(head);

  return head = newhead;
}

node* removeRear(node* head) {
  if (!last) {
    return NULL;
  }

  if (last == head) {
    clean(last);
    return last = head = NULL;
  }

  node* newlast = head;

  while (newlast) {
    if (newlast->next == last) {
      break;
    }

    newlast = newlast->next;
  }
  
  clean(last);
  newlast->next = NULL;
  last = newlast;

  return head;
}


node* removeByPointer(node* head, node* target) {
  if (!target) {
    return NULL;
  }

  if (target == head) {
    return removeFront(head);
  }

  if (target == last) {
    return removeRear(head);
  }

  node* t = head;

  while (t) {
    if (t->next == target) {
      break;
    }

    t = t->next;
  }

  t->next = target->next;
  clean(target);
  
  return head;
}

node* reverse(node* head) {
  if (!head) {
    return NULL;
  }
  
  node* newhead = last;

  while (last != head) {
    node* cursor = head;

    while (cursor) {
      if (cursor->next == last) {
        break;
      }

      cursor = cursor->next;
    }

    last->next = cursor;
    last = cursor;
  }

  last->next = NULL;

  return head = newhead;
}

node* sort(node* head) {
  if (!head) {
    return NULL;
  }

  if (!head->next) {
    return head;
  }

  node *x, *y, *e;

  x = head;
  head = NULL;
 
  while (x) {
    e = x;
    x = x->next;

    if (head) {
      if (e->data > head->data) {
        y = head;

        while (y->next && (e->data > y->next->data)) {
          y = y->next;
        }

        e->next = y->next;
        y->next = e;
      } else {
        e->next = head;
        head = e;
      }
    } else {
      e->next = NULL;
      head = e;
    }
  }
  
  last = e;
  return head;
}


void traverse(node* head, callback f) {
  node* cursor = head;

  while (cursor) {
    f(cursor);
    cursor = cursor->next;
  }
}

int getCount(node* head) {
  return count;
}

void clean(node* nd) {
  free(nd);
  count--;
}