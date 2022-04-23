Suppose we have a circular buffer of length N, where N>=4. Write a function <<buffer.getAverage(i)>>
that computes the average of two specific points in the buffer: buffer_(i) and buffer_(i+3). For this
problem, buffer_(0) is defined as the newest (most recently added) data point. Therefore, buffer_(i+3)
is the data that was added three points before buffer_(i). Keep in mind that because of the circular
nature of the buffer, finding either buffer_(i) or buffer(i+3) might require you to wrap around the
buffer. For example, for a 4-element buffer, if we added the following points in order: 3, 2, 5, 8, and 4,
and we do <<buffer.getAverage(0)>>, then we should get back (buffer[0]=4 + buffer[3]=2)/2.0 = 3.0

For the same buffer, if we did <<buffer.getAverage(2)>> the result would be
(buffer[2]=5 + buffer[1]=8)/2.0 = 6.5

I have included circularBuffer.h. You can add whatever class variables or method functions you like.
You will then have to define all those method functions in circularBuffer.cpp.

You will also have to create your own Makefile again.

The code should run by doing
./lab_02 0 (to run testcase 0), etc. There are testcases 0, 1, and 2 for you to try.

Submit your code with ./submit.py
