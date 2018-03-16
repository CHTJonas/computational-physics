reset
set term png size 1200,900 font "LiberationSans-Regular" 22
set output 'supplementary-task2.png'
set xlabel 'Position on screen'
set ylabel 'Relative amplitude'
set y2label ''
set y2tics
set title 'Fresnel diffraction pattern from a single slit'
f='supplementary-task2-3.dat'
g='supplementary-task2-5.dat'
h='supplementary-task2-1.dat'
set border 11
set tics nomirror
plot f using 1:2 w l lc 8 lw 1 title "30cm", \
     g using 1:2 w l lc 7 lw 1 title "50cm", \
     h using 1:2 w l lc 6 lw 1 title "100cm"
