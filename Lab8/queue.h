

typedef char QueueDataType;

struct QNode{ // nodes of the list
	char *data;
	QNode *next;
};
struct Queue {
	QNode *front;
	QNode *back;
	void create();
	void close();
	void enqueue(char*);
	char* dequeue();
	bool isEmpty();
};