/*
 * Project Qwoma
 * queue.h
 *
 * This header is part of Qwoma project that intends
 * to offer a flexible queue structure without using
 * memory allocation.
 *
 * Declares functions and macros and defines the queue
 * struct.
 *
 * Created on: 09/07/2013
 * Author: Leandro S. Lima
 * Licence: LGPL
 */
#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"
#include <stdint.h>

#define QUEUE_TAIL (queue->tail % queue->lines)
#define QUEUE_HEAD (queue->head % queue->lines)
#define QUEUE_TAIL_INC (queue->tail++ % queue->lines)
#define QUEUE_HEAD_INC (queue->head++ % queue->lines)

typedef struct
{
	uint32_t lines;
	uint32_t columns;
	uint32_t head;
	uint32_t tail;
	uint32_t size;
	char ** buffer;
} Queue_t;

void Queue_Init(Queue_t * queue, const uint32_t lines, const uint32_t columns,
		char ** buffer);

void Queue_Enqueue(Queue_t * queue, int dataSize, const char * data);

char * Queue_Dequeue(Queue_t * queue);

inline char * Queue_First(Queue_t * queue);

inline bool Queue_HasNext(Queue_t * queue);

inline uint32_t Queue_MaxStrSize(Queue_t * queue);

inline uint32_t Queue_MaxQueueSize(Queue_t * queue);

void Queue_Print(Queue_t * queue);

#endif /* QUEUE_H_ */
