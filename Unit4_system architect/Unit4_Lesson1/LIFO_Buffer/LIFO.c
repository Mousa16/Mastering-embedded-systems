/*
 * LIFO.c
 *
 *  Created on: ٢٥‏/٠٩‏/٢٠٢٣
 *      Author: محمود
 */

#include <LIFO.h>
LIFO_status LIFO_push_item (LIFO_Buffer_t* lifo_buf , unsigned int item)
{
	//check if lifo is valid
	if (!lifo_buf->base || !lifo_buf->head)
		return LIFO_NULL;

	//check if lifo is full
	if (lifo_buf->count == lifo_buf->length)
		return LIFO_full;

	//Add item
	*(lifo_buf->head) = item;
	lifo_buf->head++;
	lifo_buf->count++;
	return LIFO_no_error;
}
LIFO_status LIFO_pop_item (LIFO_Buffer_t* lifo_buf , unsigned int* item)
{
	//check if lifo is valid
	if (!lifo_buf->base || !lifo_buf->head)
		return LIFO_NULL;

	//check if lifo is empty
	if (lifo_buf->count == 0)
		return LIFO_empty;

	//pop item
	lifo_buf->head--;
	*item= *(lifo_buf->head);
	lifo_buf->count--;
	return LIFO_no_error;
}
LIFO_status LIFO_init (LIFO_Buffer_t* lifo_buf , unsigned int* buf , unsigned int length)
{
	lifo_buf->base = buf;
	lifo_buf->head = buf;
	lifo_buf->length = length;
	lifo_buf->count = 0;
	return LIFO_no_error;
}

