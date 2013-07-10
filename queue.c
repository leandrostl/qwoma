/*
 * Project Qwoma
 * queue.c
 *
 * This source is part of Qwoma project that intends
 * to offer a flexible queue structure without using
 * memory allocation.
 *
 * Implements functions to access queue data.
 *
 * Created on: 09/07/2013
 * Author: Leandro S. Lima
 * Licence: LGPL
 */
#include "queue.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



void Queue_Init(Queue_t * queue, const uint32_t lines, const uint32_t columns, char ** buffer)
{
    queue->lines = lines;
    queue->columns = columns;
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
    queue->buffer = buffer;
}

void Queue_Enqueue(Queue_t * queue, int dataSize, const char * data)
{
    if(dataSize >= queue->columns)
        dataSize = queue->columns - 1;

    if (QUEUE_TAIL == QUEUE_HEAD && (queue->size + 1) > queue->lines)
            queue->head++;

    queue->buffer[QUEUE_TAIL][dataSize] = '\0';

    memcpy(queue->buffer[QUEUE_TAIL_INC], data, dataSize);

    if(queue->size < queue->lines)
        queue->size++;
}

char * Queue_Dequeue(Queue_t * queue)
{
    if(Queue_HasNext(queue))
        queue->size--;

    return queue->buffer[QUEUE_HEAD_INC];
}

void Queue_Print(Queue_t * queue)
{
  int size = queue->size;
  int head = queue->head;
  while(size > 0)
  {
    printf("%s\n", queue->buffer[(head++ % queue->lines)]);
    size--;
  }
}

inline char * Queue_First(Queue_t * queue)
{
    return queue->buffer[QUEUE_HEAD];
}

inline bool Queue_HasNext(Queue_t * queue)
{
    return (queue->size > 0);
}

inline uint32_t Queue_MaxStrSize(Queue_t * queue)
{
  return queue->columns;
}

inline uint32_t Queue_MaxQueueSize(Queue_t * queue)
{
	return queue->lines;
}
