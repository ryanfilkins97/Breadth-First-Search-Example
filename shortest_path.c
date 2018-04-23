#include <stdio.h>
#include <stdlib.h>

#include "shortest_path.h"

void DFSEnqueue(Queue *queue, int key)
{
	QueueNode *newNode = malloc(sizeof(QueueNode));
	newNode->index = key;
	newNode->next = NULL;

	if(queue->head == NULL)
	{
		queue->head = newNode;
		queue->tail = newNode;
		return;
	}
	else
	{
		queue->tail->next = newNode;
		queue->tail = newNode;
	}
}

int DFSDequeue(Queue *queue)
{
	// Return -1 if queue is empty
	int index = -1;

	QueueNode *node = queue->head;
	if(node != NULL)
	{
		queue->head = node->next;

		if(node == queue->tail)
		{
			queue->tail = NULL;
		}

		index = node->index;
		free(node);
	}

	return index;
}

void printPush(StackNode **head, int key)
{
	StackNode *newNode = malloc(sizeof(StackNode));
	newNode->key = key;
	newNode->next = *head;

	*head = newNode;

	return;
}

StackNode* findShortestPath(int *floors, int numFloors, int starting, int goal, int upInterval, int downInterval)
{
	// Index is one less than actual floor number, floor 1 is index 0, etc.
	int startingIndex = starting - 1;
	int goalIndex = goal - 1;
	int maxIndex = numFloors - 1;

	Queue *queue = malloc(sizeof(Queue));
	queue->head = NULL;
	queue->tail = NULL;

	StackNode *path = NULL;

	DFSEnqueue(queue, startingIndex);
	int currentIndex = 0;

	// Sentinal value for starting index marks as explored but has no valid parent
	*(floors + startingIndex) = -2;

	while((currentIndex = DFSDequeue(queue)) != -1)
	{
		if(currentIndex == goalIndex)
		{
			// push path onto stack
			while(*(floors + currentIndex) != -2)
			{
				// Push floor for current index onto stack, then set current index to the parent floor
				printPush(&path, (currentIndex + 1));
				currentIndex = *(floors + currentIndex);
			}

			// When starting floor is reached, the value of its parent will be -1, which will break the loop, but starting floor still needs ot be pushed
			printPush(&path, starting);

			break;
		}
		else
		{
			// If the current index plus the up interval or minus the down interval is a valid floor index and has not already been discovered, 
			// set its parent to the current floor and add it to the queue
			if(currentIndex + upInterval <= maxIndex && *(floors + currentIndex + upInterval) == -1)
			{
				*(floors + currentIndex + upInterval) = currentIndex;
				DFSEnqueue(queue, (currentIndex + upInterval));
			}
			if(currentIndex - downInterval >= 0 && *(floors + currentIndex - downInterval) == -1)
			{
				*(floors + currentIndex - downInterval) = currentIndex;
				DFSEnqueue(queue, (currentIndex - downInterval));
			}
		}
	}

	freeQueue(queue);

	return path;
}

void outputAndFreeStack(StackNode *head)
{
	StackNode *temp = NULL;
	while(head != NULL)
	{
		printf("%d", head->key);
		temp = head;
		head = head->next;
		free(temp);
		if(head != NULL)
		{
			printf("->");
		}
	}
	printf("\n");
}

void freeQueue(Queue *queue)
{
	QueueNode *node = queue->head;

	while(node != NULL)
	{
		queue->head = node->next;
		free(node);
		node = queue->head;
	}

	free(queue);
}