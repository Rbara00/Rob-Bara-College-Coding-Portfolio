This lab will let you time the execution speeds of three different sort algorithms.
The sort algorithms have been coded for you already. I have also written code
that counts how many swaps it takes for each sort method to work. In this lab we will
extend that analysis by timing the sorts. This will be a better analysis because
it will include other time consuming steps other than swap.

What to do:

[1] Familiarize yourself with the coding and execution of timing_example.cpp. You can
(and should) compile and run it and see how it works.

[2] Familiarize yourself with the coding and execution of lab_09.cpp. You can (and
should) compile and run it and see how it works.

[3] Modify lab_09.cpp so that in addition to computing the average number of
swaps, you also measure the average execution time for each method as a function
of the number of points being sorted. Be mindful that we only want to time the
sort process. Don't bias your results by including the random number generation
into your timing. Modify the cout statement at the end to including three more
columns: millisecond timing for the three sort methods.

[4] Using Excel or another tool of your choice, create a plot with N on the
x-axis and sort time and n-swaps on the y-axes. Include a sentence or two answering
whether the timing and n-swaps are telling you the same thing or if they follow
different trends, and why.

[5] Include your graph image and/or Excel and/or text file with sentence answers
in your lab_09 dir and submit the whole thing.
