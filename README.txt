# Issues

I could not properly make the free for my malloc work.
I left it in comments for you to see that I understood the idea of freeing dynamic memory allocation that used malloc.
It would make the application crash if I kept it, so I decided to keep it commented in my code.

Another issue I have is that the amount of columns sometimes cause the program to crash.
However, when using 3 columns, you will see that all my functions to generate data work well.

Finally, I noticed that qsort worked properly when printing in the console, but not when printing to the file.
Thus, my sorting on the first column is not fully functional, but it is still implemented (not commented) nonetheless
as it did not affect the running of the program. I believe this could be related to docker / linux.