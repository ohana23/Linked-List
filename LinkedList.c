/**
 * Linked List
 * University of Central Florida
 * Author: Daniel Ohana
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
} node;

node *createNode(int data)
{
  node *ptr = malloc(sizeof(node));

  if (ptr == NULL)
    exit(1);

  ptr->data = data;
  ptr->next = NULL;

  return ptr;
}

node *insert(node *head, int data)
{
  // It's probably a good idea to create a list before
  // we insert a node into one.
  if (head == NULL)
    return createNode(data);

  // First we have to crawl to the end of our list.
  node *crawl;
  for (crawl = head; crawl->next != NULL; crawl = crawl->next)
    ;

  // Now we can insert a node into the place we're at (the end of the list).
  crawl->next = createNode(data);

  return head;
}

void printList(node *head)
{
  if (head == NULL)
  {
    printf("Your list is empty.");
    return;
  }

  // Crawl through our list, printing every node value we encounter.
  for (; head != NULL; head = head->next)
  {
    // Print a space if we have more to go.
    // Print a new line if we're done.
    printf("%d%c", head->data, (head->next == NULL) ? '\n' : ' ');
  }

  return;
}

int main(void)
{
  node *head = NULL;
  int n;

  printf("\n");
  for (int i = 0; i < 10; i++)
  {
    printf("Number to insert: ");
    scanf("%d", &n);

    if (n < 0)
      break;

    printf("Inserting %d into list...\n", n);
    head = insert(head, n);

    printf("\n\n");
    printList(head);
    printf("\n\n");
  }


  printf("\n\n><><><><><><><><><><><><><><");
  printf("\n   THANK YOU FOR PLAYING!\n");
  printf("><><><><><><><><><><><><><><\n\n");



  return 0;
}
