#!/bin/bash
#echo "hey"

make -f Makefile

################# test1 ######################
#put expected results in a file
./test1 > r1

#put actual results in a file
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
#put expected results in a file
./test2 > r2
#put actual results in a file
./mytest2 > myr2

#remove first line from files
echo "$(tail +2 r2)" > r2
echo "$(tail +2 myr2)" > myr2

#compare the expected with actual
echo "***** Test2 *****"
if cmp -s r2 myr2
then
   echo "PASS"
else
   echo "FAIL"
fi


################# test3 ######################
#put expected results in a file
./test3 > r3
#put actual results in a file
./mytest3 > myr3

#remove first line from files
echo "$(tail +2 r3)" > r3
echo "$(tail +2 myr3)" > myr3

#compare the expected with actual
echo "***** Test3 *****"
if cmp -s r3 myr3
then
   echo "PASS"
else
   echo "FAIL"
fi
