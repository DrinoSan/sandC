#include "stdio.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "vector.h"

// ----------------------------------------------------------------------------
void INIT_LIST( list* l )
{
   l->data     = NULL;
   l->size     = 0;
   l->capacity = 0;
}

// ----------------------------------------------------------------------------
void* list_reallocate( void* pointer, size_t newSize, int* error )
{
   if ( newSize == 0 )
   {
      free( pointer );
      return NULL;
   }

   void* result = realloc( pointer, newSize );

   if ( result == NULL )
   {
      *error = ERR_OUT_OF_MEMORY;
      return NULL;
   }

   if ( error )
   {
      *error = 0;   // Making sure we dont point to garbage
   }

   return result;
}

// ----------------------------------------------------------------------------
void push_back( list* l, int element, int* error )
{
   // We need to grow the list
   if ( l->size + 1 > l->capacity )
   {
      unsigned int oldCapacity = l->capacity;
      l->capacity              = GROW_CAPACITY( oldCapacity );

      l->data = ( int* ) list_reallocate( l->data, l->capacity * sizeof( int ), error );

      if ( *error != 0 )
      {
         return;
      }
   }

   l->data[ l->size ] = element;
   l->size++;
}
