reset

set xzeroaxis
set xtics axis
set xrange [-1:1]
set yzeroaxis
set ytics axis
set yrange [-1:1]

set term png size 1200,900 font "LiberationSans-Regular" 22
set output 'task2.png'
set xlabel ''
set ylabel ''
set y2label ''
set y2tics
set title 'Cornu Spiral'
f='task2.dat'
set border 11
set tics nomirror
plot f using 1:2 w l lc 8 lw 1 notitle
