## Overview

This is a small C program that uses breadth first search to find the shortest path between 2 floors in a building given a starting floor, a goal floor, a number of floors one can go up at a time, and a number of floors one can go down at a time. It was created as a project for CS3050.

## Contents

**prog_assign_3.c** - Main program file

**shortest_path.c/shortest_path.h** - Contains functions for breadth first search

## Usage

This project can be compiled using 'make'. 'make clean' can be used to remove all object files and executables, leaving only source code.

```
$ ./HW3 <floors> <starting_floor> <goal_floor> <up_interval> <down_interval>
```

**Note:** The maximum number of floors is 100. The starting and goal floors need to be between 1 and the number of floors, and the goal floor cannot be the same as the starting floor. The up and down intervals must be greater than or equal to zero, and while they can be set to be larger than the number of floors, this will result in no solution being found.
