reset
set term png size 1200,900 font "LiberationSans-Regular" 22
set output 'core-task2.png'
set xlabel 'Position on screen'
set ylabel 'Relative amplitude'
#set xrange [-1:1]
set title 'Farfield diffraction pattern for a sinusoidal phase grating'
f='core-task2.dat'
set border 11
plot f using 1:2 with line linecolor rgb "blue" notitle
