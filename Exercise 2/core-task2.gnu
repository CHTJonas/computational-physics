reset
set term png size 1200,900 font "LiberationSans-Regular" 22
set output 'core-task2-q1.png'
set xlabel 'Time/s'
set ylabel 'Angular Speed'
set y2label 'Position'
set y2tics
set title 'Evolution of a pendulum'
f='core-task2-q1.dat'
set border 11
set tics nomirror
plot f using 1:3 w l lc 8 lw 3 title 'angular speed (rad/s)',\
     f using 1:2 axes x1y2 w l lc -1 lw 3 title 'angle (rad)'

reset
set term png size 1200,900 font "LiberationSans-Regular" 22
set output 'core-task2-q5.png'
set xlabel 'Time/s'
set ylabel 'Angular Speed'
set y2label 'Position'
set y2tics
set title 'Evolution of a pendulum'
f='core-task2-q5.dat'
set border 11
set tics nomirror
plot f using 1:3 w l lc 8 lw 3 title 'angular speed (rad/s)',\
     f using 1:2 axes x1y2 w l lc -1 lw 3 title 'angle (rad)'

reset
set term png size 1200,900 font "LiberationSans-Regular" 22
set output 'core-task2-q10.png'
set xlabel 'Time/s'
set ylabel 'Angular Speed'
set y2label 'Position'
set y2tics
set title 'Evolution of a pendulum'
f='core-task2-q10.dat'
set border 11
set tics nomirror
plot f using 1:3 w l lc 8 lw 3 title 'angular speed (rad/s)',\
     f using 1:2 axes x1y2 w l lc -1 lw 3 title 'angle (rad)'

reset
set term png size 1200,900 font "LiberationSans-Regular" 22
set output 'core-task2-F0.5.png'
set xlabel 'Time/s'
set ylabel 'Angular Speed'
set y2label 'Position'
set y2tics
set title 'Evolution of a pendulum'
f='core-task2-F0.5.dat'
set border 11
set tics nomirror
plot f using 1:3 w l lc 8 lw 3 title 'angular speed (rad/s)',\
     f using 1:2 axes x1y2 w l lc -1 lw 3 title 'angle (rad)'

reset
set term png size 1200,900 font "LiberationSans-Regular" 22
set output 'core-task2-F1.2.png'
set xlabel 'Time/s'
set ylabel 'Angular Speed'
set y2label 'Position'
set y2tics
set title 'Evolution of a pendulum'
f='core-task2-F1.2.dat'
set border 11
set tics nomirror
plot f using 1:3 w l lc 8 lw 3 title 'angular speed (rad/s)',\
     f using 1:2 axes x1y2 w l lc -1 lw 3 title 'angle (rad)'

reset
set term png size 1200,900 font "LiberationSans-Regular" 22
set output 'core-task2-F1.44.png'
set xlabel 'Time/s'
set ylabel 'Angular Speed'
set y2label 'Position'
set y2tics
set title 'Evolution of a pendulum'
f='core-task2-F1.44.dat'
set border 11
set tics nomirror
plot f using 1:3 w l lc 8 lw 3 title 'angular speed (rad/s)',\
     f using 1:2 axes x1y2 w l lc -1 lw 3 title 'angle (rad)'

reset
set term png size 1200,900 font "LiberationSans-Regular" 22
set output 'core-task2-F1.465.png'
set xlabel 'Time/s'
set ylabel 'Angular Speed'
set y2label 'Position'
set y2tics
set title 'Evolution of a pendulum'
f='core-task2-F1.465.dat'
set border 11
set tics nomirror
plot f using 1:3 w l lc 8 lw 3 title 'angular speed (rad/s)',\
     f using 1:2 axes x1y2 w l lc -1 lw 3 title 'angle (rad)'
