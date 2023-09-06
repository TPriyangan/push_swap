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

void  circular_doubly_linked_list(int *a)
{
  struct node  *new_node;
  int  i;
  int  length;
  int  *current;
  
  head = (struct node *)malloc(sizeof(struct node));
  tail = (struct node *)malloc(sizeof(struct node));
  
  if (!head || !tail)
    return (NULL);
  head -> data = a[0];
  head -> prev = &a[ft_strlen(a) - 1];
  head -> next = &a[1]
  tail -> data = a[ft_strlen(a) - 1];
  tail -> next = &a[0];
  tail -> prev = &a[strlen(a) - 2];

  i = 1;
  length = strlen(a) -1;
  current = head;
  while (i != length)
  {
    if (i != length - 1)
    {
      new_node = (struct node *)malloc(sizeof(struct node));
      if (!new_node)
        returnn (NULL);
      new_node->data = a[i];
      new_node->prev = current;
      new_node->next = head;

      current->next = new_node;
      current = new_node;
    }
    i++;
  }
}
