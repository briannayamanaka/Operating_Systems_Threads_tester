#!/bin/bash
#echo "hey"

make -f Makefile

################# test1 ######################
#put expected results in r1
./test1 > r1

#put actual results in myr1
./mytest1 > myr1

#remove first line from files
echo "$(tail +2 r1)" > r1
echo "$(tail +2 myr1)" > myr1

#compare the expected with actual
echo "***** Test1 *****"
if cmp -s r1 myr1
then
   echo "PASS"
else
   echo "FAIL"
fi


################# test2 ######################
#put expected results in r1
./test2 > r2
#put actual results in myr1
./mytest2 > myr2

#compare the expected with actual
echo "***** Test2 *****"
if cmp -s r1 myr1
then
   echo "PASS"
else
   echo "FAIL"
fi
