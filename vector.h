#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdlib.h>

// INIT_LIST
// PUSH_BACK
// POP_BACK
// PUSH_FRONT -- MAYBE

// Error codes
#define ERR_OUT_OF_MEMORY 1

// ----------------------------------------------------------------------------
#define GROW_CAPACITY( capacity ) ( ( capacity ) < 8 ? 8 : ( capacity ) * 2 )

// ----------------------------------------------------------------------------
#define LIST_FREE( pointer ) free( pointer )

// ----------------------------------------------------------------------------
typedef struct
{
   int*   data;
   size_t size;
   size_t capacity;
   // bool sorted;
} list;

// ----------------------------------------------------------------------------
void INIT_LIST( list* l );

// ----------------------------------------------------------------------------
void push_back( list* l, int element, int* error );

#endif
