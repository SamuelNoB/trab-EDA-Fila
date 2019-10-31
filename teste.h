#define N 6

class Queue
{
public:
	Queue()
	{
		_front = new int[N];
		_size = 0;
		_capacity = N;
		head = 0;
		tail = 0;
	}
	~Queue()
	{
		delete[] _front;
	}

	int* _front;
	int _size;
	int _capacity;

	int head;  // location to pop from
	int tail;  // location to push to
};
