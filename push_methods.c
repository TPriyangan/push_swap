#include "push_swap.h"

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
    *stack_a = temp;
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
    (*stack_b)->prev->next = (*stack_b)->next;
    (*stack_b)->next->prev = (*stack_b)->prev;
    struct node *temp_head = *stack_b;
    *stack_b = (*stack_b)->next;
    free(temp_head);
  }
}

void  push_b(struct node **stack_a, struct node **stack_b)
{
  struct node *temp;

  if (!stack_a)
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
    temp = (*stack_b);
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
}

void  rotate_a(struct node **stack_a)
{
  if (!*stack_a)
    return ;
  *stack_a = (*stack_a)->next;
}

void  rotate_b(struct node **stack_b)
{
  if (!*stack_b)
    return ;
  *stack_b = (*stack_b)->next;
}

void  rotate(struct node **stack_a, struct node **stack_b)
{
  rotate_a(*stack_a);
  rotate_b(*stack_b);
}

void  reverse_rotate_a(struct node **stack_a)
{
  if (!*stack_a)
    return ;
  *stack_a = (*stack_a)->prev;
}

void  reverse_rotate_b(struct node **stack_b)
{
  if (!*stack_b)
    return ;
  *stack_b = (*stack_b)->prev;
}

void  reverse_rotate(struct node **stack_a, struct node **stack_b)
{
  reverse_rotate_a(*stack_a);
  reverse_rotate_b(*stack_b);
}
