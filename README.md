<div align="center">

# push_swap

<a href="https://imgflip.com/i/8rujzu"><img src="https://i.imgflip.com/8rujzu.jpg" width="350px"/></a>

</div>

**Description:**

> This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

## ✔️ Project's requirements

### Mandatory part

#### 1. The rules

You have 2 stacks named `a` and `b`.
* At the beginning:
  * The stack `a` contains a random amount of negative and/or positive numbers which cannot be duplicated.
  * The stack `b` is empty.
* The goal is to sort in ascending order numbers into stack `a`. To do so you have the following operations at your disposal:
  * `sa` (`swap a`):  Swap the first 2 elements at the top of stack `a`. Do nothing if there is only one or no elements.
  * `sb` (`swap b`):  Swap the first 2 elements at the top of stack `b`. Do nothing if there is only one or no elements.
  * `ss` : `sa` and `sb` at the same time.
  * `pa` (`push a`): Take the first element at the top of `b` and put it at the top of `a`. Do nothing if `b` is empty.
  * `pb` (`push b`): Take the first element at the top of `a` and put it at the top of `b`. Do nothing if `a` is empty.
  * `ra` (`rotate a`): Shift up all elements of stack `a` by 1. The first element becomes the last one.
  * `rb` (`rotate b`): Shift up all elements of stack `b` by 1. The first element becomes the last one.
  * `rr` : `ra` and `rb` at the same time.
  * `rra` (`reverse rotate a`): Shift down all elements of stack `a` by 1. The last element becomes the first one.
  * `rrb` (`reverse rotate b`): Shift down all elements of stack `b` by 1. The last element becomes the first one.
  * `rrr` : `rra` and `rrb` at the same time.

#### 2. The "push_swap" program

* You have to turn in a `Makefile` which will compile your source files. It must not relink.
* Global variables are forbidden.
* You have to write a program named `push_swap` that takes as an argument the stack `a` formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).
* The program must display the smallest list of instructions possible to sort the stack `a`, the smallest number being at the top.
* Instructions must be separated by a `\n` and nothing else.
* The goal is to sort the stack with the lowest possible number of operations. During the evaluation process, the number of instructions found by your program will be compared against a limit: the maximum number of operations tolerated. If your program either displays a longer list or if the numbers aren’t sorted properly, your grade will be 0.
* If no parameters are specified, the program must not display anything and give the prompt back.
* In case of error, it must display `"Error"` followed by a `\n` on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer and/or there are duplicates.

#### 3. Benchmark

* For a **minimalist validation** (that implies a minimal grade of 80), you must be able to **sort 100 random numbers in fewer than 700 operations.**
* For **maximal project validation** and thus to be able to achieve the bonuses, you must fulfill the first step above, but also for **500 random numbers**, there should be **no more than 5500 operations.**

---

### Bonus part

* Write a program named `checker` that takes as an argument the stack `a` formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order). If no argument is given, it stops and displays nothing.
* It will then wait and read instructions on the standard input, each instruction will be followed by `\n`. Once all the instructions have been read, the program has to execute them on the stack received as an argument.
* If after executing those instructions, the stack `a` is actually sorted and the stack `b` is empty, then the program must display `"OK"` followed by a `\n` on the standard output.
* In every other case, it must display `"KO"` followed by a `\n` on the standard output.
* In case of error, you must display `"Error"` followed by a `\n` on the **standard error.** Errors include for example: some arguments are not integers, some arguments are bigger than an integer, there are duplicates, an instruction doesn’t exist and/or is incorrectly formatted.

## 🧬 Theory

The `ft_printf()` function takes a string in parameter and can also takes one or several arguments of different types. The basic idea is to browse the string and when a `%` character and just after a character which represents a conversion are encountered, the program must prints the associated value. The original `printf()` function returns the number of characters printed, so the `ft_printf()` must do the same.

## 📝 Code explanation

As you can see in the `main.c` file, there's nothing complicated here, so I won't insult you by explaining what's going on...

### File: push_swap.c

So let's starts by the `push_swap.c` file:

```C
void	push_swap(int argc, char **argv)
{
	char	**parsed_args;
	int	*numbers;
	int	*sort_numbers;
	t_swap	*stack_a;
	t_swap	*stack_b;

	parsed_args = ft_parsing((argc - 1), (argv + 1));
	if (parsed_args == NULL)
		return ;
	numbers = ft_create_numbers(ft_nb_element(parsed_args), parsed_args);
	sort_numbers = ft_create_sort_numbers(ft_nb_element(parsed_args), numbers);
	stack_a = ft_create_list(ft_nb_element(parsed_args), numbers);
	stack_b = NULL;
	ft_indexing(sort_numbers, numbers, ft_nb_element(parsed_args), &stack_a);
	ft_sorting(&stack_a, &stack_b, ft_nb_element(parsed_args));
	ft_free_tab_of_tab(parsed_args);
	free(numbers);
	free(sort_numbers);
	ft_free_list(&stack_a);
	ft_free_list(&stack_b);
}
```

The program's logic is based on **four** main stages: **parsing**, **stacks creation**, **indexing** and **sorting**. We'll not see the **parsing** part because it's not an important part in this project.

1) parsing the arguments
2) create an int* with the parsed args
3) create an int* with the sorted numbers
4) create the stack a
5) indexing the elements with ft_indexing():

This function indexes the elements of stack_a based on their position in the sorted version of the array (sort).

The function compares each element of the unsorted array (unsort) with the sorted array (sort), and when it finds a match, it assigns that position (index) to the corresponding element in the stack (stack_a). 

This indexing is useful for sorting algorithms, where you often want to keep track of each element’s position in the sorted order.

This is a mapping function that transforms the stack’s values into their indices in a sorted sequence, likely preparing for a sorting algorithm that operates based on these indices rather than the raw values.

6) sort the elements

### File: operations.c

Now let's take a look at the different manipulation operations.

<details>

<summary>swap</summary>

<br>

```C
void	swap(t_swap **stack, char c)
{
	int		tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}
```
For the `swap()` function, we first perfom some basic verifications and do a classic swap as we can do with two pointers: a `tmp` variable stores the content of the first node, its content is then set to the content of the second node and finally, the content of the second node is set to the value stored in `tmp`, completing the swap.

</details>

---

<details>

<summary>push</summary>

<br>

```C
void	push(t_swap **from_stack, t_swap **to_stack, char c)
{
	t_swap	*first;
	t_swap	*tmp;

	if (ft_define_nb_element_stack(*from_stack) < 1)
		return ;
	if (*from_stack != NULL)
	{
		first = *from_stack;
		*from_stack = (*from_stack)->next;
	}
	if (*to_stack != NULL)
	{
		tmp = *to_stack;
		first->next = tmp;
		*to_stack = first;
	}
	else
	{
		*to_stack = first;
		first->next = NULL;
	}
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}
```
For the `push()` function, first we check if `from_stack` has at least one element. Then, we remove the top node from `from_stack` and assign it to the variable `first`. This node is then moved to the top of `to_stack`, if `to_stack` is not empty, the current top node of `to_stack` is set as the next node of `first`. On the other hand, if `to_stack` is empty, `first` becomes the new top node with its next pointer set to `NULL`.

</details>

---

<details>

<summary>rotate</summary>

<br>

```C
void	rotate(t_swap **stack, char c)
{
	t_swap	*tmp;

	if ((*stack) == NULL)
		return ;
	if ((*stack)->next != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		ft_stacklast(*stack)->next = tmp;
		tmp->next = NULL;
	}
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}
```
For the `rotate()` function, first we check if `stack` is non-empty. If `stack` has more than one node, we store the current top node in the variable `tmp`, then update the top of `stack` to the next node. We then set the next pointer of the last node in the updated `stack` to `tmp`, making it the new last node, and set `tmp`'s next pointer to `NULL`.

</details>

---

<details>

<summary>reverse rotate</summary>

<br>

```C
void	reverse_rotate(t_swap **stack, char c)
{
	t_swap	*prev;
	t_swap	*last;

	if ((*stack) == NULL)
		return ;
	if ((*stack)->next != NULL)
	{
		prev = *stack;
		last = (*stack)->next;
		while (last->next != NULL)
		{
			prev = last;
			last = last->next;
		}
		last->next = *stack;
		*stack = last;
		prev->next = NULL;
	}
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}
```
For the `reverse_rotate()` function, first we check if `stack` is non-empty. If `stack` has more than one node, we traverse `stack` to find the last node and the node just before it, using `prev` and `last`. Once we reach the last node, we update its next pointer to point to the original top of the stack and make it the new top. We then set `prev`'s next pointer to `NULL` to mark the end of the stack.

</details>

<h2>🧰 Toolbox</h2>

- [Tester](https://gitlab.com/nda-cunh/push_swap-testeur-max)
- [Visualizer](https://gitlab.com/nda-cunh/visualizer-push-swap)

<h2>📚 Resources</h2>

- [Quicksort (Wikipedia)](https://en.wikipedia.org/wiki/Quicksort)
- [QuickSort (GeeksforGeeks)](https://man7.org/linux/man-pages/man3/va_arg.3.html)
