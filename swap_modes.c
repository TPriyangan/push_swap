void swap_a(struct node *stack_a)
{
  struct node *temp;
  if (!(*stack_a-data) || !(*stack_a)->next->data)
    return;
  temp = (*stack_a)->data;
  (*stack_a)->data = (*stack_a)->next->data;
  (*stack_a)->next->data = temp;
  return ;
}
