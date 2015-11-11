#include <stdio.h>
#include <text/text.h>

int main( void )
{
	Text *t = t_new();
	int num;

	t_puts( t, "HelloHellosexyHellohELLObye" );

	PrintTinfo( t );

	t_repposns( t, 0, 1, "" );

	PrintTinfo( t );

	t_zero( t );

	t_puts( t, "HelloHellosexyHellohELLObye" );

	PrintTinfo( t );

	t_toupper( t );

	PrintTinfo( t );

	t_tolower( t );

	//num = t_reps( t, 0, "bye", "<THIS-STRING>" );

	//printf( "Replacements: %d\n", num );

	PrintTinfo( t );

	t_free( t );

	return 0;
}
