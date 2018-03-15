reset
set term png size 1200,900 font "LiberationSans-Regular" 22
set output 'core-task1.png'
set xlabel 'Time/s'
set ylabel 'Total energy (arb. units)'
##set yrange [44.1:44.2]
set title 'Energy conservation for an initial angle of pi/2 radians'
f='core-task1.dat'
set border 11
set tics nomirror
plot f using 1:4 w l lc 8 lw 3 notitle
