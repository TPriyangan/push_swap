#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

/*moves*/
void swap_a(struct node **stack_a);
void  swap_b(struct node **stack_b);
void  swap_a_and_b(struct node **stack_a, struct node **stack_b);
void  push_a(struct node **stack_a, struct node **stack_b);
void  push_b(struct node **stack_a, struct node **stack_b);
void  rotate_a(struct node **stack_a);
void  rotate_b(struct node **stack_b);
void  rotate(struct node **stack_a, struct node **stack_b);
void  reverse_rotate_a(struct node **stack_a);
void  reverse_rotate_b(struct node **stack_b);
void  reverse_rotate(struct node **stack_a, struct node **stack_b);

/* push_swapfiles*/
size_t	ft_strlen(const char *s);
struct node  *circular_doubly_linked_list(int *a);
int	base_sort_check(struct node *stack_a, struct node *stack_b, int mark);
void	sort_both_base(struct node *stack_a, struct node *stack_b);
void	sort_apart(struct node *stack_a);
void	sort_bpart(struct node *stack_b);
void	sort_abpart(struct node *stack_a, struct node *stack_b);
int is_final_sorted(struct node *stack_a, struct node *stack_b);
int is_a_sorted(struct node *stack_a, struct node *stack_b);
int is_b_sorted(struct node *stack_b);
void	final_sort_ab(struct node *stack_a, struct node *stack_b);
void	push_to_a(struct node *stack_a, struct node *stack_b);
void	push_swap(int *a);
#endif
