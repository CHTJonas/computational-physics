reset
set term png size 1200,900 font "LiberationSans-Regular" 22
set output 'core-task1.png'
set xlabel 'Position on screen'
set ylabel 'Relative amplitude'
set xrange [-5:5]
set title 'Farfield diffraction pattern for a single slit'
f='core-task1.dat'
n(x) = 4*400*1100*(sin(3.14159*0.0001*x/0.0000005/1) / (3.14159*0.0001*x/0.0000005/1))**2
set border 11
plot f using 1:2 with line linecolor rgb "blue" title "FFT", \
     n(x) title "Theory" with lines
