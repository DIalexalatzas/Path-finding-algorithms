# Path-finding-algorithms
3rd project of Introduction to Programming class

Suppose we have a rectangular box n × m (n lines and m columns), which we want to traverse from the first line to the last. We start from a square of the first line and
at each step we can go to a square of the next, either directly below, or to one of the diagonals (bottom left or bottom right). We consider that in its extreme columns
the table "folds", so if we are in the rightmost position in one line, we take the leftmost position of the next line as the diagonal lower right of this position.
Corresponding folding can also be done in the left column. The possible transitions from one square of the frame to one of the next row are shown in the adjacent figure 
(above). In this way, we can create paths crossing the frame from the first to the last line, like those shown in the adjacent figure (below). Let us now consider that 
in each square of the box there is a non-negative integer. The question is to find what is the maximum sum of numbers that we can have crossing a path, with this logic.

![example](https://user-images.githubusercontent.com/61728750/235896474-5def3d27-4a7a-4cec-8674-f63534ed8bc7.png)

We will use:
- Recursive method (maxsumrec.c)
- Recursice method with memorization (maxsummem.c)
- Iterative method with dynamic programming (maxsumdp.c)

Extra:
- Calculation of optimal paths (maxsummempath.c , maxsumdppath.c)
