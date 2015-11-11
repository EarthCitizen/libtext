#include <stdio.h>
#include <text/text.h>

void mycallback( Text *t, int err )
{
	printf( "Error: " );
	switch ( err )
	{
		case T_ERR_BIN:

			printf( "Binary char\n" );

			break;

		case T_ERR_MAX:

			printf( "Max length exceeded\n" );

			break;

		case T_ERR_NTF:

			printf( "Search item not found\n" );

			break;
	}
}

int main( int argc, char *argv[] )
{
	Text *t = t_newdef( 5, 0, 1, T_ERR_BIN | T_ERR_MAX | T_ERR_MEM, mycallback );
	unsigned int pos = 0;

	t_seterrcall( t, mycallback );

	//PrintTinfo( t );

	pos = t_putfmt( t, "qq%cqq", 1 );

	t->rbin = 0;

	pos = t_putfmt( t, "qq%cqq", 1 );

	t->errmask &= ~T_ERR_MAX; 

	pos = t_putfmt( t, "qqqq" );

	//PrintTinfo( t );

	printf( "pos: %d\n%s\n", pos, t_getall( t ) );

	//PrintTinfo( t );

	t_reverse( t );

	printf( "REVERSED: %s\n", t_getall( t ) );

	t_finds( t, 0, 1, "REVERSED" );

	t->errmask |= T_ERR_NTF;

	t_finds( t, 0, 1, "REVERSED" );

	t_free( t );

	return 0;
}

