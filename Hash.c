#include <stdio.h>
#include <string.h> // Include string .h for strlen
#include <sha256.h> // OpenSSL header that defines SHA functions and types like SHA256_CTX
int main () {
const char * message = " Hello , world ! ";
// Array to store the resulting SHA -256 hash . SHA256_DIGEST_LENGTH is 32 bytes (256 bits ) for SHA -256.
unsigned char hash [ SHA256_DIGEST_LENGTH ];
/* struct defined in OpenSSL , which holds all the internal state of the hash computation .
* Think of ctx as a workspace for the SHA -256 algorithm to keep track of its computation .*/
SHA256_CTX ctx ;
// Initialize the context : Prepares ctx for a new hashing operation .
SHA256_Init (& ctx );
// Update the context with the message
/* Feeds the message into SHA -256.
/* SHA -256 works on blocks ; SHA256_Update can be called multiple times if the message is large .
/* Internally , it breaks the message into 512 - bit blocks and processes each .*/
SHA256_Update (& ctx , message , strlen ( message ));
// Finalize the hash : Completes the computation .
SHA256_Final ( hash , & ctx );
// Print the hash
/* Print the hash in hexadecimal format .
* %02x ensures two hex digits per byte , padded with 0 if necessary .*/
printf (" SHA256 hash : " );
for (int i = 0; i < SHA256_DIGEST_LENGTH ; i ++) {
printf ( " %02 x " , hash [ i ]);
}
printf (" \n" );
return 0;
}
