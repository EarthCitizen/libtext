#include <stdio.h>
#include <text/text.h>

int main( void )
{
	Text *t = t_new();

	t_putspos( t, 0, "1234567890abcdefg" );

	PrintTinfo( t );

	t_repposns( t, 1, 4, "x" );

	PrintTinfo( t );

	t_putspos( t, 0, "1234567890abcdefg" );

	PrintTinfo( t );

	t_repposns( t, 9, 1, "x" );

	PrintTinfo( t );

	t_putspos( t, 0, "1234567890abcdefg" );

	PrintTinfo( t );

	t_repposns( t, 50, 20, "x" );

	PrintTinfo( t );

	t_putspos( t, 0, "1234567890abcdefg" );

	PrintTinfo( t );

	t_repposns( t, 0, 10, "x2x4x6x8x0" );

	PrintTinfo( t );

	t_free( t );

	return 0;
}
