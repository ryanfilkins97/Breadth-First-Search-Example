typedef struct BFSQueueNode
{
	int index;
	struct BFSQueueNode *next;
}QueueNode;

typedef struct BFSQueue
{
	QueueNode *head;
	QueueNode *tail;
}Queue;

typedef struct PrintStackNode
{
	int key;
	struct PrintStackNode * next;
}StackNode;

void BFSEnqueue(Queue *queue, int key);
int BFSDequeue(Queue *queue);
void printPush(StackNode **head, int key);
int printPop(StackNode *head);
StackNode* findShortestPath(int *floors, int numFloors, int starting, int goal, int upInterval, int downInterval);
void outputAndFreeStack(StackNode *head);
void freeQueue(Queue *queue);