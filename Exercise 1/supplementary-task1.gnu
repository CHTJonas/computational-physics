reset
set term png size 1200,900 font "LiberationSans-Regular" 22
set output 'supplementary-task1-error.png'
set xlabel 'Number of Monte-Carlo samples'
set ylabel 'Error in result'
set title 'Error as a function of Monte-Carlo sample number'
#set yrange [-5:5]
f='supplementary-task1.dat'
set border 11
plot f using 1:2 with points pointtype 28 linecolor rgb "blue" title "error estimated from equation (3)",\
     f using 1:3 with points pointtype 28 linecolor rgb "red" title "error derived from the scatter of points"
