//
// Created by OlegMS on 11.02.2018.
//
#include <stdio.h>
#ifndef BASE64_BASE64CODER_H

#define BASE64_BASE64CODER_H



#define B64_SYNTAX_ERROR        1
#define B64_FILE_ERROR          2
#define B64_FILE_IO_ERROR       3
#define B64_ERROR_OUT_CLOSE     4
#define B64_LINE_SIZE_TO_MIN    5
#define B64_SYNTAX_TOOMANYARGS  6


#define B64_MAX_MESSAGES 7
static char *b64_msgs[ B64_MAX_MESSAGES ] = {
        "b64:000:Invalid Message Code.",
        "b64:001:Syntax Error -- check help (-h) for usage.",
        "b64:002:File Error Opening/Creating Files.",
        "b64:003:File I/O Error -- Note: output file not removed.",
        "b64:004:Error on output file close.",
        "b64:005:linesize set to minimum.",
        "b64:006:Syntax: Too many arguments."
};

#define b64_message( ec ) ((ec > 0 && ec < B64_MAX_MESSAGES ) ? b64_msgs[ ec ] : b64_msgs[ 0 ])

void encodeblock( unsigned char *in, unsigned char *out, int len );

int encode( FILE *infile, FILE *outfile, int linesize );

/*
** decodeblock
**
** decode 4 '6-bit' characters into 3 8-bit binary bytes
*/
void decodeblock( unsigned char *in, unsigned char *out );

/*
** decode
**
** decode a base64 encoded stream discarding padding, line breaks and noise
*/
int decode( FILE *infile, FILE *outfile );

/*
** b64
**
** 'engine' that opens streams and calls encode/decode
*/

int b64( char opt, char *infilename, char *outfilename, int linesize );

/*
** showuse
**
** display usage information, help, version info
*/
void showuse( int morehelp );


#endif //BASE64_BASE64CODER_H
