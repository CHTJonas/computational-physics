reset
set term png size 1200,900 font "LiberationSans-Regular" 22
set output 'task1-result.png'
set xlabel 'Number of Monte-Carlo samples'
set ylabel 'Result'
set title 'Result of integral as a function of Monte-Carlo sample number'
f='task1.dat'
set border 11
plot f using 1:2 with points pointtype 28 linecolor rgb "green" notitle

reset
set term png size 1200,900 font "LiberationSans-Regular" 22
set output 'task1-error.png'
set xlabel 'Number of Monte-Carlo samples'
set ylabel 'Error in result'
set title 'Error as a function of Monte-Carlo sample number'
f='task1.dat'
set border 11
plot f using 1:3 with points pointtype 28 linecolor rgb "blue" notitle

reset
set term png size 1200,900 font "LiberationSans-Regular" 22
set output 'task1-error-adjusted.png'
set xlabel 'Number of Monte-Carlo samples'
set ylabel 'Reciprocal square error in result'
set title 'The reciprocal of the error squared as a function of Monte-Carlo sample number'
f='task1.dat'
set border 11
plot f using 1:3**-2 with points pointtype 28 linecolor rgb "red" notitle

reset
set term png size 1200,900 font "LiberationSans-Regular" 22
set output 'task1-error-bars.png'
set xlabel 'Number of Monte-Carlo samples'
set ylabel 'Result'
set title 'Result of integral and error as a function of Monte-Carlo sample number'
f='task1.dat'
set border 11
plot f using 1:2:3 with yerrorbars notitle
