typedef struct DFSQueueNode
{
	int index;
	struct DFSQueueNode *next;
}QueueNode;

typedef struct DFSQueue
{
	QueueNode *head;
	QueueNode *tail;
}Queue;

typedef struct PrintStackNode
{
	int key;
	struct PrintStackNode * next;
}StackNode;

void DFSEnqueue(Queue *queue, int key);
int DFSDequeue(Queue *queue);
void printPush(StackNode **head, int key);
int printPop(StackNode *head);
StackNode* findShortestPath(int *floors, int numFloors, int starting, int goal, int upInterval, int downInterval);
void outputAndFreeStack(StackNode *head);
void freeQueue(Queue *queue);