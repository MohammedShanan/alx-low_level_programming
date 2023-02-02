#include "hash_tables.h"
/**
 * hash_djb2 - implement djb2 algorithm (one of best string hash functions)
 * source code copied from http://www.cse.yorku.ca/~oz/hash.html
 *
 * @str: value
 * Return: key
 */
unsigned long int hash_djb2(const unsigned char *str)
{
unsigned long int hash;
int c;

hash = 5381;
while ((c = *str++))
{
hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
}
return (hash);
}
