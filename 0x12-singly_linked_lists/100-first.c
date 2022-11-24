#include <stdio.h>
void me_before_main(void) __attribute__((constructor));
/**
 * me_before_main - executes this function before main function
 * Note: To do this task we have to put attribute for these two functions.
 * When the attribute is constructor attribute,
 * then it will be executed before main(),
 * and when the attribute is destructor type,
 * then it will be executed after main().
 */
void me_before_main(void)
{
printf("You're beat! and yet, you must allow,\n");
printf("I bore my house upon my back!\n");
}
