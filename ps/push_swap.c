#include "push_swap.h"

void	push_swap(int *a, int i)
{
	struct node	*stack_a;
	struct node	*stack_b;
	int doublecheck;
	
	stack_a = circular_doubly_linked_list(a , i);
	if (!stack_a) 
	    free_quit(&stack_a);
	doublecheck = check_multiple(stack_a);
	if (doublecheck(stack_a)
	    free_quit(&stack_a);
	if (is_not_sorted(stack_a))
	    sort_stack(&stack_a);
	free_simple(&stack_a);
	return (0);
}

int	main(int argc, char **argv)
{
      char  **array;
    int   *intarray;
    int   i;
    
    if (argc < 2)
    {
	    write(2, "Error\n",6);
	    return (1);
    }
    if (argc == 2)
        array = ft_split(argv[1], ' ');
    else 
        array = argv;
    i = 0;
    while(array[i])
        i++;
    intarray = (int*)malloc(i * sizeof(int));
    if (!intarray)
        return 1;
    i = 0;
    while (array[i])
    {
        intarray[i] = ft_atoi(array[i]);
        i++;
    }
    push_swap(intarray, i);
    free(intarray);
    return (0);
}
