reset
set term png size 1200,900 font "LiberationSans-Regular" 22
set output 'core-task1-periods.png'
set xlabel 'Amplitude (arb units)'
set ylabel 'Period/s'
set title 'Plot of period versus amplitude'
f='core-task1-periods.dat'
set border 11
set tics nomirror
plot f using 1:2 w l lc 8 lw 3 notitle
