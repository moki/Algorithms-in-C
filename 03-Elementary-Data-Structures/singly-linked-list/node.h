typedef struct node {
  int data;
  struct node* next;
} node;

extern node* head;
extern node* last;
extern int count;

node* create(int, node*);
node* prepend(int, node*);
node* append(int, node*);

node* find(int, node*);

node* insertAfter(node*, int, node*);
node* insertBefore(node*, int, node*);

node* removeFront(node*);
node* removeRear(node*);
node* removeByPointer(node*, node*);

node* reverse(node*);

node* sort(node*);

void clean(node*);

int getCount(node*);

typedef void (*callback)(node*);

void traverse(node*, callback);