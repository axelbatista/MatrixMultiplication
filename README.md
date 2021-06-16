Takes in compatible matrices. I mnetion it in the source text but instead of supplying values for the dimension at run time
you simply change the values of template arguments (row, then col) on the already created matrices objects.
The more tricky one is for the object created upon the performMultiplication, which you do have to supply it correctly for.
In this instance, it's going to be in this order: the first template argument of the first object (the row), with the last argument
of the last object (the col). It's kinda in the shape of a square when you see it, so you can think of it as the top left corner with
the bottom right corner.
