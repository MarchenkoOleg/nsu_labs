#include <stdio.h>
#include <stdlib.h>


#define B64_DEF_LINE_SIZE   72
#define B64_MIN_LINE_SIZE    4

#define THIS_OPT(ac, av) ((char)(ac > 1 ? av[1][0] == '-' ? av[1][1] : 0 : 0))
#include "base64coder.h"
/*
** main
**
** parse and validate arguments and call b64 engine or help
*/
int main( int argc, char **argv )
{
    char opt = (char) 0;
    int retcode = 0;
    int linesize = B64_DEF_LINE_SIZE;
    char *infilename = NULL, *outfilename = NULL;

    while( THIS_OPT( argc, argv ) != (char) 0 ) {
        switch( THIS_OPT(argc, argv) ) {
            case 'l':
                linesize = atoi( &(argv[1][2]) );
                if( linesize < B64_MIN_LINE_SIZE ) {
                    linesize = B64_MIN_LINE_SIZE;
                    printf( "%s\n", b64_message( B64_LINE_SIZE_TO_MIN ) );
                }
                break;
            case '?':
            case 'h':
                opt = 'h';
                break;
            case 'e':
            case 'd':
                opt = THIS_OPT(argc, argv);
                break;
            default:
                opt = (char) 0;
                break;
        }
        argv++;
        argc--;
    }
    if( argc > 3 ) {
        printf( "%s\n", b64_message( B64_SYNTAX_TOOMANYARGS ) );
        opt = (char) 0;
    }
    switch( opt ) {
        case 'e':
        case 'd':
            infilename = argc > 1 ? argv[1] : NULL;
            outfilename = argc > 2 ? argv[2] : NULL;
            retcode = b64( opt, infilename, outfilename, linesize );
            break;
        case 0:
            if( argv[1] == NULL ) {
                showuse( 0 );
            }
            else {
                retcode = B64_SYNTAX_ERROR;
            }
            break;
        case 'h':
            showuse( (int) opt );
            break;


    }
    if( retcode != 0 ) {
        printf( "%s\n", b64_message( retcode ) );
    }

    return( retcode );
}