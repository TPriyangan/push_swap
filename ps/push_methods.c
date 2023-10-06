#include "push_swap.h"

void swap_a(struct node *stack_a)
{
  int temp;
  
  if (!(stack_a) || !(stack_a->next))
    return;
  temp = stack_a->data;
  stack_a->data = stack_a->next->data;
  stack_a->next->data = temp;
  write(1, "sa\n", 3);
  return ;
}

void swap_b(struct node *stack_b)
{
  int temp;
  
  if (!(stack_b) || !(stack_b->next))
    return;
  temp = stack_b->data;
  stack_b->data = stack_b->next->data;
  stack_b->next->data = temp;
  write(1, "sa\n", 3);
  return ;
}

void  swap_a_and_b(struct node *stack_a, struct node *stack_b)
{
  swap_a(stack_a);
  swap_b(stack_b);
  write(1, "ss\n", 3);
  return;
}

void  push_a(struct node *stack_a, struct node *stack_b)
{
  struct node  *temp;
  if (!(stack_b))
    return;
  temp = (struct node *)malloc(sizeof(struct node));
  if (!temp)
    return;
  temp->data = (stack_b)->data;
  if (stack_a)
  {
    temp->next = stack_a;
    temp->prev = (stack_a)->prev;
    (stack_a)->prev->next = temp;
    (stack_a)->prev = temp;
    stack_a = temp;
  }
  else
  {
    temp->next=temp;
    temp->prev=temp;
    stack_a = temp;
  }
  if ((stack_b)->next == stack_b && (stack_b)->prev == stack_b)
  {
    free(stack_b);
    stack_b = NULL;
  }
  else
  {
    (stack_b)->prev->next = (stack_b)->next;
    (stack_b)->next->prev = (stack_b)->prev;
    struct node *temp_head = stack_b;
    stack_b = (stack_b)->next;
    free(temp_head);
  }
  write(1, "pa\n", 3);
}

void  push_b(struct node **stack_a, struct node **stack_b)
{
  struct node *temp;
  if (!*stack_a)
    return ;
  temp = (struct node*)malloc(sizeof(struct node*));
  if (!temp)
    return ;
  temp->data = (*stack_a)->data;
  if ((*stack_b))
  {
    temp->prev = (*stack_b)->prev;
    temp->next = (*stack_b);
    (*stack_b)->prev->next = temp;
    (*stack_b)->prev = temp;
  }
  else
  {
    temp->next = temp;
    temp->prev = temp;
    *stack_b = temp;
  }

  if ((*stack_a)->next == *stack_a && (*stack_a)->prev == *stack_a)
  {
    free(*stack_a);
    *stack_a = NULL;
  }
  else
  {
    (*stack_a)->prev->next = (*stack_a)->next;
    (*stack_a)->next->prev = (*stack_a)->prev;
    struct node *temp_head = *stack_a;
    *stack_a = (*stack_a)->next;
    free(temp_head);
  }
  write(1, "pb\n", 3);
}



void  rotate_a(struct node **stack_a)
{
  if (!*stack_a)
    return ;
  *stack_a = (*stack_a)->next;
  write(1, "ra\n", 3);
}

void  rotate_b(struct node **stack_b)
{
  if (!*stack_b)
    return ;
  *stack_b = (*stack_b)->next;
  write(1, "rb\n", 3);
}

void  rotate(struct node **stack_a, struct node **stack_b)
{
  rotate_a(stack_a);
  rotate_b(stack_b);
  write(1, "r\n", 2);
}

void  reverse_rotate_a(struct node **stack_a)
{ 
  if (!*stack_a)
    return ;
  *stack_a = (*stack_a)->prev;
  write(1, "rra\n", 4);
}

void  reverse_rotate_b(struct node **stack_b)
{
  if (!*stack_b)
    return ;
  *stack_b = (*stack_b)->prev;
  write(1, "rrb\n", 4);
}

void  reverse_rotate(struct node **stack_a, struct node **stack_b)
{
  reverse_rotate_a(stack_a);
  reverse_rotate_b(stack_b);
  write(1, "rr\n", 3);
}
