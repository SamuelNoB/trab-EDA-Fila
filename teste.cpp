#include "Queue.h"

void add(Queue*q, int i)
{
	// If there is room then add it.
	if (q->_size < q->_capacity - 1)
	{
		//*(q->_front + q->_size - 1) = i;

		q->_front[q->tail] = i;
		q->_size++;
		q->tail = (q->tail + 1) % q->_capacity;
	}
	else
	{
		int* arr = new int[q->_capacity * 2];

		if ((q->_capacity - q->head) > q->tail) // primeiro caso
		{
			int p = q->head;

			int tail = q->tail + 1;
			int pos = q->head;

			for (int j = 0; j < q->_capacity - 1 ; j++)
			{
				arr[tail] = q->_front[pos];
				pos = (pos + 1) % q->_capacity;
				tail = (tail + 1) % (q->_capacity * 2);
			}

			// adiciona o novo valor na fila.
			arr[tail] = i;
		}
		else if ((q->_capacity - q->head) <= q->tail) // segundo caso
		{
			int p = q->head;

			int tail = (q->_capacity * 2) - (q->_capacity - q->head);
			int pos = q->head;

			for (int j = 0; j < q->_capacity - 1; j++)
			{
				arr[tail] = q->_front[pos];
				pos = (pos + 1) % q->_capacity;
				tail = (tail + 1) % (q->_capacity * 2);
			}

			// adiciona o novo valor na fila.
			arr[tail] = i;
		}
		else if ((q->_capacity - q->head) == q->tail) // terceiro caso
		{
			int b = 3;
		}
		else
		{
			printf("caso invalido!!!!\n");
		}

		q->_capacity *= 2;   // Update parameter.
		delete[] q->_front;  // Delete memory.
		q->_front = arr;      // Point to new array.
		arr = NULL;       // c++11

		q->_size++;          // Same as above when there was room.
		*(q->_front + q->_size - 1) = i;
	}
}

int pop(Queue*q, int *value)
{
	if (q->_size == 0)
	{
		// queue is empty, handle as appropriate
		return 0;
	}
	else
	{
		*value = q->_front[q->head];
		q->_size--;
		q->head = (q->head + 1) % q->_capacity;
	}

	return 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Queue q;

	// debug

	// primeiro caso
	/*q.head = 3;
	q.tail = 3;

	add(&q, 7);
	add(&q, 8);
	add(&q, 5);
	add(&q, 9);
	add(&q, 4);

	add(&q, 3);
	add(&q, 2);*/

	// segundo caso
	q.head = 4;
	q.tail = 4;

	add(&q, 7);
	add(&q, 8);
	add(&q, 5);
	add(&q, 9);
	add(&q, 4);

	add(&q, 3);
	add(&q, 2);

	//add(&q, 1);
	//add(&q, 2);
	//add(&q, 3);
	//add(&q, 4);
	//add(&q, 5);
	//
	//int valor = 0;
	////pop(&q, &valor);
	//
	//add(&q, 6);
	//
	//pop(&q, &valor);
	//pop(&q, &valor);
	//pop(&q, &valor);
	////pop(&q, &valor);
	//
	//add(&q, 6);
	//pop(&q, &valor);
	//pop(&q, &valor);
	//pop(&q, &valor);
	//
	//add(&q, 7);
}
