#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shortest_path.h"

int main(int argc, char **argv)
{
	// Validate command line input
	if(argc != 6)
	{
		printf("Incorrect command line arguments\nCorrect arguments: <floors> <starting floor> <goal floor> <up interval> <down interval>\n");
		return -1;
	}

	int numFloors = atoi(*(argv + 1));

	if(numFloors == 0 || numFloors > 100)
	{
		printf("Floors must be a number between 1 and 100\n");
		return -1;
	}

	int starting = atoi(*(argv + 2));

	if(starting == 0 || starting > numFloors || starting < 1)
	{
		printf("Starting floor must be a number between 1 and the number of floors\n");
		return -1;
	}

	int goal = atoi(*(argv + 3));
	if(goal == 0 || goal > numFloors || goal < 1)
	{
		printf("Goal floor must be a number between 1 and the number of floors\n");
		return -1;
	}
	if(goal == starting)
	{
		printf("Goal floor should not be the same as starting floor\n");
		return -1;
	}

	int upInterval = atoi(*(argv + 4));
	if(upInterval == 0 && strcmp(*(argv + 4), "0") != 0)
	{
		printf("Up interval must be a number greater than or equal to 0\n");
		return -1;
	}
	if(upInterval < 0)
	{
		printf("Up interval must be a number greater than or equal to 0\n");
		return -1;
	}

	int downInterval = atoi(*(argv + 5));
	if(downInterval == 0 && strcmp(*(argv + 5), "0") != 0)
	{
		printf("Down interval must be a number between 0 and 100\n");
		return -1;
	}
	if(downInterval > 100 || downInterval < 0)
	{
		printf("Down interval must be a number between 0 and 100\n");
		return -1;
	}

	// Floors is an array of integers. The index in the array represents the floor number - 1. The value at that index is the index of the parent floor in the DFS
	int *floors = malloc(sizeof(int) * numFloors);
	int i = 0;

	// Initialize parent of each floor to -1, this will represent undiscovered node
	for(i = 0; i < numFloors; i++)
	{
		*(floors + i) = -1;
	}

	StackNode *path = findShortestPath(floors, numFloors, starting, goal, upInterval, downInterval);

	free(floors);

	if(path == NULL)
	{
		printf("Use the stairs\n");
	}
	else
	{
		outputAndFreeStack(path);
	}

	return 0;
}