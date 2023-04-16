# push_swap

<p align="center">
    <img src="https://img.shields.io/github/languages/count/fleizean/push_swap?style=for-the-badge"/>
    <img src="https://img.shields.io/github/last-commit/fleizean/push_swap?style=for-the-badge"/>
    <img src="https://img.shields.io/github/forks/fleizean/push_swap?style=for-the-badge"/>
    <img src="https://img.shields.io/github/followers/fleizean?style=for-the-badge"/>
    <img src="https://img.shields.io/github/watchers/fleizean/push_swap?style=for-the-badge"/>
</p>

<p align="center">
    <img src="https://badge42.vercel.app/api/v2/cl13ejq4y000909mke5sxpjan/stats?cursusId=21&coalitionId=233"/>
</p>

<h3 align="center">
  push_swap
</h3>

<p align="center">
    push_swap is a 42 school algorithm project where we must sort a given list of random numbers with a limited set of instructions, using the lowest possible number of actions.
</p>

### Usage


Git clone the repository and cd into it. Then use ```make``` to compile.

Then run it with :

```shell
./push_swap <numbers>
```


### Rules


The program is only allowed two stacks to work with, stack A and stack B. All the numbers are initially added to stack A, and B is empty.

The possible actions are:

* ```pa``` (push A): Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
* ```pb``` (push B): Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
* ```sa``` (swap A): Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
* ```sb``` (swap B): Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
* ```ss```: ```sa``` and ```sb``` at the same time.
* ```ra``` (rotate A): Shift all elements of stack A up by 1. The first element becomes the last one.
* ```rb``` (rotate B): Shift all elements of stack B up by 1. The first element becomes the last one.
* ```rr```: ```ra``` and ```rb``` at the same time.
* ```rra``` (reverse rotate A): Shift all elements of stack A down by 1. The last element becomes the first one.
* ```rrb``` (reverse rotate B): Shift all elements of stack b down by 1. The last element becomes the first one.
* ```rrr``` : ```rra``` and ```rrb``` at the same time.


<h2 align="center">
  Evaluation
</h2>

<p align="center">
  <img src="https://badge42.vercel.app/api/v2/cl13ejq4y000909mke5sxpjan/project/2617243"/>
</p>
