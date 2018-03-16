In core task 1 I adapted the example program in 'fft2.cc' and adapted it to calculate the FFT of an aperture.
I found there was a discrepancy in the x coordinate of the plotted result that I could no account for.
I took to Wikipedia to try and correct this however I could not.
I beleive that the acutal results are correct, just that the position on the x-axis is scaled compared to real-world coordinates.

I checked the difraction pattern at it appeared to show the correct sinc functionality.
The analytical solution is plotted via gnuplot.

--

In core task 2 I adapted my code from task 1 and added a phase factor to the apperture function.
The result pattern appears to be symetric about the y-axis however I don't know what to compare it to to check this is correct.
I had a slight problem with picking suitable values for n and delta in my code.
