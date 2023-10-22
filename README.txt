# Issues

I could not properly make the free_memory() for my malloc / realloc calls work.
I left it in comments for you to see that I understood the idea of freeing dynamic memory allocation that used malloc.
It would make the application crash if I kept it, so I decided to keep it commented in my code.

Another issue I have is that the amount of columns sometimes cause the program to crash.
However, when using 3 columns, you will see that all my functions to generate data work well.
This is likely due to a memory management issue. I am aware that we need to use "valgrind --leak-check=yes ./myapp"
to see the errors, but I did not have enough time to do so. In summary, I would go to that exact line
given my valgrind and try to fix it.

Finally, I noticed that qsort worked properly when printing in the console, but not when printing to the file.
Thus, my sorting on the first column is not fully functional, but it is still implemented (not commented) nonetheless
as it did not affect the running of the program. I believe this could be related to docker / linux.
