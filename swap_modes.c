void swap_a(struct node **stack_a)
{
  struct node *temp;
  if (!(*stack_a-data) || !(*stack_a)->next->data)
    return;
  temp = (struct node *)malloc(sizeof(struct node));
  if (!temp)
  {
    free(temp);
    return ;
  }
  temp->data = (*stack_a)->data;
  (*stack_a)->data = (*stack_a)->next->data;
  (*stack_a)->next->data = temp->data;
  free(temp);
  return ;
}

void  swap_b(struct node **stack_b)
{
  struct node  *temp;
  if (!(*stack_b) || !(*stack_b)->next)
    return ;
  temp = (struct node *)malloc(sizeof(struct node));
  if (!temp)
  {
    free(temp);
    return ;
  }
  temp->data = (*stack_b)->data;
  (*stack_b)->data = (*stack_b)->next->data;
  (*stack_b)->next->data = temp->data;
  free(temp);
  return ;
}

void  swap_a_and_b(struct node **stack_a, struct node **stack_b)
{
  swap_a(stack_a);
  swap_b(stack_b);
  return;
}

void  push_a(struct node **stack_a, struct node **stack_b)
{
  struct node  *temp;
  if (!(*stack_b))
    return;
  temp = (struct node *)malloc(sizeof(struct node));
  if (!temp)
    return;
  temp->data = (*stack_b)->data;
  if (*stack_a)
  {
    temp->next = *stack_a;
    temp->prev = (*stack_a)->prev;
    (*stack_a)->prev->next = temp;
    (*stack_a)->prev = temp;
  }
  else
  {
    temp->next=temp;
    temp->prev=temp;
    *stack_a = temp;
  }
  if ((*stack_b)->next == *stack_b && (*stack_b)->prev == *stack_b)
  {
    free(*stack_b);
    *stack_b = NULL;
  }
  else
  {
    (*stack_b)->next->prev = (*stack_b)->prev->next;
    (*stack_b)->prev->next = (*stack_b)->next->prev;
    (*stack_b) = (*stack_b)->next;
  }
}
