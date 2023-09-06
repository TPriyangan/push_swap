struct node
{
  int  data;
  struct node *prev;
  struct node *next;
}*head,*tail ;

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

struct node  *circular_doubly_linked_list(int *a)
{
  struct node  *new_node;
  int  i;
  int  length;
  struct node	*current;
  
  head = (struct node *)malloc(sizeof(struct node));
  tail = (struct node *)malloc(sizeof(struct node));
  
  if (!head || !tail)
    return (NULL);
  head -> data = a[0];
  head -> prev = NULL;
  head -> next = NULL;
  tail -> data = a[ft_strlen(a) - 1];
  tail -> next = head;
  tail -> prev = NULL;
  i = 1;
  length = strlen(a) -1;
  current = head;
  while (i < length)
  {
    if (i != length - 1)
    {
      new_node = (struct node *)malloc(sizeof(struct node));
if (!new_node)
{
struct node *temp;
temp = tail->next;//new function for free to make
  while (temp != head)
  {
    struct node *prev_node = temp->next;
    free(temp);
    temp = prev_node;
  }
  free(head);
  free(tail);
  return (NULL);
}
      new_node->data = a[i];
      new_node->prev = current;
      new_node->next = head;

      current->next = new_node;
      current = new_node;
    }
    i++;
  }
	return(head);
}

void	push_swap(int *a)
{
	struct node  *mylist;

	mylist = circular_doubly_linked_list(a);
}








