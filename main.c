/*
 * Project Qwoma
 * main.h
 *
 * This source is part of Qwoma project that intends
 * to offer a flexible queue structure without using
 * memory allocation.
 *
 * Shows how to use and tests the queue.
 *
 * Created on: 09/07/2013
 * Author: Leandro S. Lima
 * Licence: LGPL
 */
#include "queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

Queue_t queue;
Queue_t queue2;

void queueTest()
{
	uint32_t i;
	char text[20];

	for (i = 0; i < 30; i++)
	{
		Queue_Enqueue(&queue, sprintf(text, "Entry [%d]", i), text);
		Queue_Enqueue(&queue2, sprintf(text, "Entry [%d]", i), text);
	}

	printf("First queue[%d][%d]:\n", Queue_MaxQueueSize(&queue),
			Queue_MaxStrSize(&queue));
	while (Queue_HasNext(&queue))
		printf("%s\n", Queue_Dequeue(&queue));

	printf("Second queue[%d][%d]:\n", Queue_MaxQueueSize(&queue2),
			Queue_MaxStrSize(&queue2));
	while (Queue_HasNext(&queue2))
		printf("%s\n", Queue_Dequeue(&queue2));
}

void queueInit()
{
#define LNS 20
#define COLS 64

	static char rawData[LNS][COLS];
	static char * linePtrs[LNS];
	int i = 0;
	for (i = 0; i < LNS; i++)
		linePtrs[i] = &rawData[i][0];

	Queue_Init(&queue, LNS, COLS, linePtrs);

	printf("First queue created...\n");
	printf("Size of the raw data: %d bytes\n", (int) sizeof(rawData));
	printf("Size of the array of pointers: %d bytes\n", (int) sizeof(linePtrs));
	printf("Size of queue struct: %d bytes\n", (int) sizeof(queue));
	printf("Overhead of %f per cent.\n", (float)(sizeof(linePtrs) + sizeof(queue))*100/sizeof(rawData));

#undef LNS
#undef COLS

#define LNS 5
#define COLS 1024

	static char rawData2[LNS][COLS];
	static char * linePtrs2[LNS];
	for (i = 0; i < LNS; i++)
		linePtrs2[i] = &rawData2[i][0];

	Queue_Init(&queue2, LNS, COLS, linePtrs2);

	printf("Second queue created...\n");
	printf("Size of the raw data: %d bytes\n", (int) sizeof(rawData2));
	printf("Size of the array of pointers: %d bytes\n", (int) sizeof(linePtrs2));
	printf("Size of queue struct: %d bytes\n", (int) sizeof(queue2));
	printf("Overhead of %f per cent.\n", (float)(sizeof(linePtrs2) + sizeof(queue2))*100/sizeof(rawData2));

#undef LNS
#undef COLS
}

int main()
{
	queueInit();
	queueTest();

	return 0;
}
