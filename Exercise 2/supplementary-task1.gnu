reset
set term png size 1200,900 font "LiberationSans-Regular" 22
set output 'supplementary-task1.png'
set xlabel 'Time/s'
set ylabel 'Position'
set title 'Sensitivity in the evolution of the angle of a pendulum'
f='supplementary-task1-1.dat'
g='supplementary-task1-2.dat'
set border 11
set tics nomirror
plot f using 1:2 w l lc 8 lw 3 title 'F=1.2',\
     g using 1:2 w l lc 6 lw 3 title 'F=1.20001'
