reset
set term png size 1200,900 font "LiberationSans-Regular" 22
set output 'supplementary-task2.png'
set xlabel 'Position on screen'
set ylabel 'Relative amplitude'
set y2label ''
set y2tics
set title 'Fresnel diffraction pattern from a single slit'
f='supplementary-task2.dat'
set border 11
set tics nomirror
plot f using 1:2 w l lc 8 lw 1 notitle
