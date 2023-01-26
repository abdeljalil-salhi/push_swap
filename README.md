# push_swap - 42 project

<p align="center">
    <a href="https://projects.intra.42.fr/projects/42cursus-push_swap/projects_users/2904310" alt="absalhi's push_swap">
        <img src="https://user-images.githubusercontent.com/65598953/214836433-4e02b4c3-2a6b-4ca2-93c7-254c49be22a7.png" alt="push_swap" />
    </a>
    <br />
    <a href="https://projects.intra.42.fr/projects/42cursus-push_swap/projects_users/2904310">
        <img src="https://badge42.vercel.app/api/v2/cl9iseqxd00640gl9mg4g0mxp/project/2904310" alt="absalhi's 42 push_swap Score" />
    </a>
</p>

---

<p align="center">
    <img src="https://user-images.githubusercontent.com/65598953/214843798-0be5b450-c9ba-40c3-a074-2b1796f8af8e.gif" alt="push_swap visualizer" />
    <br />
	<i>Visualizing my push_swap ~ 4689 instructions</i>
</p>

## Table of Contents

- [push_swap - 42 project](#push-swap---42-project)
  * [Description](#description)
  * [Instructions](#instructions)
  * [Usage](#usage)
  * [Grading](#grading)
  * [My algorithm](#my-algorithm)
    + [Checking and parsing the arguments](#checking-and-parsing-the-arguments)
    + [Setting the final ranks](#setting-the-final-ranks)
    + [Sorting the stack](#sorting-the-stack)
    + [Sorting the stack - 3 numbers or less](#sorting-the-stack---3-numbers-or-less)
    + [Sorting the stack - more than 3 numbers](#sorting-the-stack---more-than-3-numbers)
    + [Sorting the stack - moving the elements](#sorting-the-stack---moving-the-elements)
  * [Conclusion](#conclusion)
  * [BONUS](#bonus)

## Description

The goal of this project is to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To make this happen, you will have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.

## Instructions

- `sa` : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
- `sb` : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
- `ss` : `sa` and `sb` at the same time.
- `pa` : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- `pb` : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- `ra` : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- `rb` : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- `rr` : `ra` and `rb` at the same time.
- `rra` : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb` : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr` : `rra` and `rrb` at the same time.

## Usage

```bash
$> make
$> ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
OK
$> ARG=`ruby -e "puts (-10000..10000).to_a.shuffle.take(500).join(' ')"`; ./push_swap $ARG | ./checker $ARG
OK
```

## Grading

The grade is on a scale from 0 to 100 (validating the project requires at least 80/100), and is based on the following criteria:

- 3 numbers to sort: no more than 3 instructions.
- 5 numbers to sort: no more than 12 instructions.
- 100 numbers to sort:
    - 5 points for less than 700 instructions.
    - 4 points for less than 900 instructions.
    - 3 points for less than 1100 instructions.
    - 2 points for less than 1300 instructions.
    - 1 point for less than 1500 instructions.
    - 0 point for more than 1500 instructions.
- 500 numbers to sort:
    - 5 points for less than 5500 instructions.
    - 4 points for less than 7000 instructions.
    - 3 points for less than 8500 instructions.
    - 2 points for less than 10000 instructions.
    - 1 point for less than 11500 instructions.
    - 0 point for more than 11500 instructions.

## My algorithm

As many of my friends requested, I decided to write a little walkthrough about my algorithm. I will try to explain it as best as I can, but I'm not a native English speaker, so please bear with me. I will also try to keep it as short as possible, but I can't guarantee that it will be THAAAT short.

### Checking and parsing the arguments

We first check if the input is correct; all the arguments must be integers *(INT_MIN <= n <= INT_MAX)*, and there mustn't be any duplicates. If the input is correct, we parse it into a linked list, and we check if it's already sorted. If it is, we just exit. If it isn't, we continue.

*QUICK NOTE: I used a linked list because it is easier to manipulate its elements, but you can use an array if you want. I will use the term `stack` to refer to the linked list.*

Many of the algorithms I found online use a temporary stack to store the sorted elements, but I decided to sort my numbers directly on the stack, using the power of linked lists. First of all, let me introduce my linked list structure:

```c
typedef struct s_stack
{
    int            content;
    int            pos;
    int            target_pos;
    int            final_rank;
    int            cost_stack_a;
    int            cost_stack_b;
    struct s_stack *next;
}   t_stack;
```

- `content`: the number itself.
- `pos`: the position of the number in the stack *(starting from 0)*.
- `target_pos`: the position the number should be in the stack A *(starting from 0)*.
- `final_rank`: the final rank of the number in the sorted stack *(starting from 1)*.
- `cost_stack_a`: the cost of moving the number to its right position in stack A.
- `cost_stack_b`: the cost of moving the number to the top of stack B.
- `next`: the pointer to the next element in the stack.

So, for example, if we have the following stack:

| pos | content | final_rank |
| --- | ------- | ---------- |
| 0   | 3       | 3          |
| 1   | 0       | 1          |
| 2   | 9       | 4          |
| 3   | 1       | 2          |

We can see that the number `3` should be in the 3rd position, the number `0` should be in the 1st position, the number `9` should be in the 4th position, and the number `1` should be in the 2nd position. That's the logic besides setting final ranks.

So after introducing the linked list structure, we go straight to the algorithm.

### Setting the final ranks

We first set the final ranks in the stack A, this is a convenient way to order our numbers in the stack because we can use the final ranks to compare numbers instead of the actual values. It is up to you to pick the logic that suits you, for me, I chose to set the final ranks in a way that final ranks are assigned from the highest (stack_a_size) to the lowest (1). I used a simple **O(n^2)** algorithm to do that (since time complexity doesn't matter in this project). I iterate through the stack using the `stack_a_size`, I assign it to the biggest number in the stack, then I decrease `stack_a_size` by 1, and I repeat the process until `stack_a_size` is 0.

For example, if we have the following stack:

| pos | content | final_rank |
| --- | ------- | ---------- |
| 0   | 3       | -          |
| 1   | 0       | -          |
| 2   | 9       | -          |
| 3   | 1       | -          |
stack_a_size = 4

I try to find the biggest number in the stack, which is `9`, so I assign the `stack_a_size` _(4)_ to `9`'s final rank, then I decrease `stack_a_size` by 1. Again, I try to find the biggest uninitialized number in the stack, which is `3`, so I assign the `stack_a_size` _(3)_ to `3`'s final rank, then I decrease `stack_a_size` by 1. Again, I try to find the biggest uninitialized number in the stack, which is `1`, so I assign the `stack_a_size` _(2)_ to `1`'s final rank, then I decrease `stack_a_size` by 1. Again, I try to find the biggest uninitialized number in the stack, which is `0`, so I assign the `stack_a_size` _(1)_ to `0`'s final rank, then I decrease `stack_a_size` by 1. Now, `stack_a_size` is 0, so I stop. The final stack will look like this:

| pos | content | final_rank |
| --- | ------- | ---------- |
| 0   | 3       | 3          |
| 1   | 0       | 1          |
| 2   | 9       | 4          |
| 3   | 1       | 2          |

Simple and straight forward, isn't it? Now we can use the final ranks to compare numbers instead of the actual values. For example, if we want to know if the number `3` is bigger than the number `1`, we can just compare their final ranks, and we will know that `3` is bigger than `1`. This is very useful when we want to sort the stack.

### Sorting the stack

We first check if the stack has 3 elements or less. If it does, for 2 numbers a simple swap (`sa`) will be enough, and for 3 numbers you can either hardcode the 5 possible combinations _(sa, sa rra, ra, sa ra, rra)_, or use a simple algorithm I developed.

### Sorting the stack - 3 numbers or less

For 3 numbers, I first get the highest final rank in the stack, if the first element of the stack has the highest final rank, I rotate (`ra`) the stack, else if the second element of the stack has the highest final rank, I reverse rotate (`rra`) the stack, then I just check if I need a quick swap `sa` if the final rank of the first element is bigger than the final rank of the second element.

### Sorting the stack - more than 3 numbers

If the stack has more than 3 numbers, I use one global algorithm; I first push all the elements of the stack A into the stack B, except the 3 last ones (I will sort in place). I push the small values first, then the larger ones _(which is more efficient than just pushing all the elements at once)_. How ?? I go through the stack A, if the current element has a final rank smaller than the median of the stack A `(median = (stack_a_size) / 2)`, I push it (`pb`) to the stack B, else I just rotate it to the bottom (`ra`). I repeat the process until all the numbers with a final rank smaller than the median are pushed to the stack B. Now, the stack A contains only the larger numbers (than the median), and the stack B contains only the smaller numbers (than the median again huh). Now, I can freely push (`pb`) the rest to the stack B except the 3 last ones. I sort the 3 remaining numbers in the stack A using the algorithm I developed for the 3 numbers case.

Now, I can go through the stack B, I assign a target position in stack A to each element of the stack B; the target position is the position where the element of stack B should be in order to be sorted correctly, this position will be used to calculate the cost of moving each element to its target position in the stack A. To get the target positions correctly, for each element in stack B I need to first check if the final rank of this element can be placed somewhere in between the elements of the stack A, by checking whether there is an element in the stack A with a bigger final rank; if not, it finds the element with the smallest final rank in the stack A and assigns that as the target position. An example ?? Let's say we initialized the `target_pos` to `INT_MAX`, and we are trying to find the target position of the element `x` with the final rank `5`, and the stack A has the following final ranks: `8, 7, 4, 3, 1`, so we first have `8 > 5 && 8 < INT_MAX`, so we update the `target_pos` to `8`, then we have `7 > 5 && 7 < 8`, so we update the `target_pos` to `7`, and finally we have `4 < 5 && 4 < 7`, no update !! Which means the `target_pos = 7` is what we are looking for since it is the closest final rank.

We then try to get the cost; we calculate the cost of moving each element of the stack B into its correct place in the stack A, 2 costs are calculated as you can see in the linked list structure;

- `cost_stack_b`: is the cost of getting the element to the top of the stack B.
- `cost_stack_a`: is the cost of getting the element to its right position in the stack A.

If the element is in the bottom half of the stack (`> median`), the cost will be negative (`< 0`), otherwise (`< median`) the cost will be positive (`>= 0`). As simple as it seems, to get the `cost_stack_b`, we use its `pos` if it is in the upper half, else if it is in the bottom half (`pos > stack_b_size / 2`), we use its `-(stack_b_size - pos)`. The same thing for the `cost_stack_a`, we use assign to it its `target_pos` if it is in the upper half, otherwise we assign `-(stack_a_size - target_pos)`.

Then after setting the target positions, and calculating the costs of both stacks, we can finally execute the cheapest move by cost, how ?? Well, again, we go through the stack B to find the element (in B) with the cheapest cost to move to the stack A, basically the element with the smallest costs (`abs(cost_stack_a) + abs(cost_stack_b)`), we, then, use our instructions to put our cheapest stack B element into its correct place of stack A.

_HINT:_ If the costs of moving the stack A and the stack B into position match (_i.e._ both `cost_stack_a` and `cost_stack_b` are negative or both are positive), they both will be rotated (`rr`) or reverse rotated (`rrr`) for efficiency sake !

### Sorting the stack - moving the elements

If both `cost_stack_a` and `cost_stack_b` are negative, we reverse rotate (`rrr`) both stack A and stack B until one of them is in position (`cost == 0`), else if both `cost_stack_a` and `cost_stack_b` are positive, we rotate (`rr`) both of the stacks until one of them is in position. The both stacks might also be rotated separately if the costs don't match, so until the cost reach 0, we rotate (`ra/rb`) if the cost is positive (`cost > 0`), else if the cost is negative (`cost < 0`) we reverse rotate (`rra/rrb`), in the end of these operations, the stack B element is at the top of the stack, and its target position in stack A is as the top of the stack as well, so we only need to push (`pa`) it into place, and we keep doing all of this again and again until the stack B is empty and all the elements in the stack A are successfully sorted.

## Conclusion

I know this isn't that easy to understand, neither that easy to code, but it is what it is, **push_swap** isn't an easy project, so read this documentation again and again, visualize your push_swap operations using the [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer) or visualize your code flow using [python_tutor (C debugger)](https://pythontutor.com/c.html#mode=edit). Use my code as a fonctional example of the explication above if something isn't clear. Write your own code, if it doesn't work, delete it and try again and again until you get it to work. _Because swap_push isn't as natural_. Good luck.

## BONUS

You got your 100/100 in the mandatory part ? Congrats, the bonus is just a freebie in this project, you have to check if the stack is sorted using the given instructions, so we use our function `get_next_line` to read from the `0` _(standard input)_, for each line entered, we compare it with our known instructions (`sa, sb, ...`), if the input doesn't match with any of them, we must display `Error` in the standard error, otherwise we execute the proper instruction on our stack. If the input is empty _(contains only `\n` or `\0`)_ we must check if the stack is sorted (check if the stack B is empty and go through every element of the stack A checking if the current number is bigger than the previous one), if it is; we display `OK`, otherwise we display `KO`.

---

Made by **absalhi**: absalhi@student.1337.ma
