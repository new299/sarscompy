set terminal png size 1024,768 font ",9"
set output 'sars2.repeatscore.png'
#set autoscale yfix
#set autoscale xfix
set xrange [-0.5:25.5]
set yrange [-0.50:25.5]
set pm3d map

set xtics 1
set ytics 1
set cbrange[0:100]
set logscale cb
set xlabel "Sub-string Length"
set ylabel "No. repeats (occurances-1)"
set view map
set nokey

plot 'sars2.repeatscore.rot' matrix using 1:2:3 with image notitle, \
     'sars2.repeatscore.rot' matrix using 1:2:($3 == 0 ? "" : sprintf("%g",$3) ) with labels
