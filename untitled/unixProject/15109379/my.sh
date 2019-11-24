#! /bin/sh

sum=0;k=0;c=0
for i
do 
if [ `expr $k % 2` -eq 0 ]
 then
   sum=`expr $sum + $i`
   c=`expr $i + 1`
fi
k=`expr $k + 1`
done
avg=`expr $sum / $c`
echo Total is $sum
echo Average is $avg    $sum/$c 
