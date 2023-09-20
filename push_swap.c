#include "push_swap.h"

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
  length = ft_strlen(a) -1;
  current = head;
  while (i < length)
  {
    if (i != length - 1)
    {
      new_node = (struct node *)malloc(sizeof(struct node));
      if (!new_node)
      {	
	      struct node *temp;
	      temp = tail->next;
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

int	base_sort_check(struct node *stack_a, struct node *stack_b, int mark)
{
	struct node	*head_a;
	struct node	*head_b;

	if (stack_b)
	{
		head_b = stack_b;
		if (head_b->data >= mark)
			return (1);
		else
		{
			stack_b = stack_b->next;
			while (stack_b != head_b)
			{
				if (stack_b->data >= mark)
					return(1);
				stack_b = stack_b->next;
			}
		}
	}
	head_a = stack_a;
	if (head_a->data < mark)
		return (1);
	else
	{
		stack_a = stack_a->next;
		while(stack_a != head_a)
		{
			if (stack_a->data < mark)
				return (1);
			stack_a = stack_a->next;
		}
	}
	return (0);
}

void	sort_both_base(struct node *stack_a, struct node *stack_b)
{
	int	mark;

	mark = stack_a->data;
	while(base_sort_check(stack_a, stack_b, mark))
	{
		if (mark >= stack_a->data)
			rotate_a(stack_a);
		if (mark < stack_a->data)
			push_b(stack_a, stack_b);
	}
}

void	sort_apart(struct node *stack_a)
{
        if (stack_a->data < stack_a->next->data && stack_a->data < stack_a->prev->data)
	{
		if (stack_a->next->data > stack_a->prev->data)
		{
			reverse_rotate_a(stack_a);
			swap_a(stack_a);
			rotate_a(stack_a);
		}
		else 
		{
			swap_a(stack_a);
			rotate_a(stack_a);
		}
	}
	if (stack_a->data < stack_a->next->data)
	{
		if (stack_a->data < stack_a->next->next->data)
			rotate_a(stack_a);
		else 
		{
			swap_a(stack_a);
			rotate_a(stack_a);
		}

	}
	while (stack_a->data > stack_a->next->data)
		rotate_a(stack_a);
}

void	sort_bpart(struct node *stack_b)
{
	if (stack_b->data > stack_b->next->data && stack_b->data > stack_b->prev->data)
	{ 
		if (stack_b->next->data < stack_b->prev->data)
		{
			reverse_rotate_b(stack_b);
			swap_b(stack_b);
			rotate_b(stack_b);
		}
		else 
		{
			swap_b(stack_b);
			rotate_b(stack_b);
		}
	}
	if (stack_b->data > stack_b->next->data)
	{
		if (stack_b->data > stack_b->next->next->data)
			rotate_b(stack_b);
		else 
		{
			swap_b(stack_b);
			rotate_b(stack_b);
		}

	}
	while (stack_b->data < stack_b->next->data)
		rotate_b(stack_b);
}

void	sort_abpart(struct node *stack_a, struct node *stack_b)
{
        if ((stack_b->data > stack_b->next->data && stack_b->data > stack_b->prev->data) && (stack_a->data < stack_a->next->data && stack_a->data < stack_a->prev->data))
	{ 
		if ((stack_b->next->data < stack_b->prev->data) && (stack_a->next->data > stack_a->prev->data))
		{
			reverse_rotate(stack_a, stack_b);
			swap_a_and_b(stack_a, stack_b);
			rotate(stack_a, stack_b);
		}
		else 
		{
			swap_a_and_b(stack_a, stack_b);
			rotate(stack_a, stack_b);
		}
	}
	if ((stack_b->data > stack_b->next->data) && (stack_a->data < stack_a->next->data))
	{
		if ((stack_b->data > stack_b->next->next->data) && (stack_a->data < stack_a->next->next->data))
			rotate(stack_a, stack_b);
		else 
		{
			swap_a_and_b(stack_a, stack_b);
			rotate(stack_a, stack_b);
		}

	}
	while ((stack_b->data < stack_b->next->data) && (stack_a->data > stack_a->next->data))
		rotate(stack_a, stack_b);
}

int is_final_sorted(struct node *stack_a, struct node *stack_b)
{
	int	i;
	
	i = is_a_sorted(stack_a);
	i = i + is_b_sorted(stack_b);
	if (i >= 1)
		return (1);
	return (0);
}

int is_a_sorted(struct node *stack_a, struct node *stack_b)
{
    struct node *head_a;
    struct node	*min_stack;
    int min;

    head_a = stack_a;
    min = stack_a->data;
    min_stack = stack_a;
    // Find the minimum value and the min node
    while (stack_a != head_a)
    {
        if (stack_a->data < min) {
            min = stack_a->data;
	    min_stack = stack_a;
        }
        stack_a = stack_a->next;
    }
    //loop until min_stack at top
    while (stack_a != min_stack)
	    stack_a = stack_a->next;
    //check if next data < current
    while (*stack_a != min_stack)
    {
	    if (stack_a->data < stack_a->next->data)
		    return (1);
	    stack_a = stack_a->next;
    }
    //part where we modify the stack_a
    while(*stack_a != min_stack)
            rotate_a(stack_a);
    return 0; // Sorted from min to max
}

int is_b_sorted(struct node *stack_b)
{
    struct node *head_b;
    struct node	*max_stack;
    int max;

    head_b = stack_b;
    max = stack_b->data;
    max_stack = stack_b;
    // Find the max value and the max node
    while (stack_b != head_b)
    {
        if (stack_b->data > max) {
            max = stack_b->data;
	    max_stack = stack_b;
        }
        stack_b = stack_b->next;
    }
    //loop until max_stack at top
    while (stack_b != max_stack)
	    stack_b = stack_b->next;
    //check if next data > current
    while (*stack_b != max_stack)
    {
	    if (stack_b->data > stack_b->next->data)
		    return (1);
	    stack_b = stack_b->next;
    }
    //part where we modify the stack_b
    while(*stack_b != max_stack)
            rotate_b(stack_b);
    return 0; // Sorted from max to min
}

void	final_sort_ab(struct node *stack_a, struct node *stack_b)
{
	while (is_final_sorted == 1)
	{
		sort_abpart(stack_a, stack_b);
		sort_apart(stack_a);
		sort_abpart(stack_a, stack_b);
		sort_bpart(stack_a, stack_b);
		sort_abpart(stack_a, stack_b);
		sort_apart(stack_a, stack_b);
		sort_abpart(stack_a, stack_b);
	
}

void	push_to_a(struct node *stack_a, struct node *stack_b)
{
	while (*stack_b)
		push_a(stack_a, stack_b);
}

void	push_swap(int *a)
{
	struct node	*stack_a;
	struct node	*stack_b;

	stack_a = circular_doubly_linked_list(a);
	stack_b = NULL;
	if (!stack_a || !stack_b)
		return;
	sort_both_base(stack_a, stack_b);
	final_sort_ab(stack_a, stack_b);
	push_to_a(stack_a, stack_b);
}
