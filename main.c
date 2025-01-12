#include <stddef.h>
#include <stdio.h>

// Testing
#include "vector.h"

int main()
{
   int  error;
   list l;
   INIT_LIST( &l );

   for ( size_t i = 0; i < 10; i++ )
   {
      push_back( &l, i, &error );
   }

   for ( size_t i = 0; i < l.size; i++ )
   {
      printf( "Value: %d\n", l.data[ i ] );
   }

   LIST_FREE( l.data );
}
