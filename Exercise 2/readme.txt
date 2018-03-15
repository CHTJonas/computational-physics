The differential equations for a driven pendulum were written as a coupled pair and integrated using 4th order Runge-Kutta.
I then wrote the codebase and tested it by setting q=F=0 and plotting solutions for 10,100 & 1000 periods of oscillation.
This seemed okay.
I then overlayed an approximate analytical solution, this also seemed okay.
I then added some code to calculate the period of the pendulum and generated some values of this with hard-coded values in the code.
Finally I added some code to calculate the total energy of the system and plotted this over a long period of time to test energy conservation.

The calculated period for (theta = pi / 2) was 7.42s.

--

In core task 2 I first added some damping wiht values of q = 1, 5, 10 and check that the plots obtained made physical sense.
I then added some driving force by setting F = 0.5, 1.2, 1.44, 1.465 with a constant q = 0.5.
From measuring directly of the graphs, I found that the period remained approximately constant.
All plots have a suffix indicating which value of q or F they relate to.
