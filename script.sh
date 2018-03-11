#!/bin/bash
#echo "hey"

echo 
echo 
echo 
echo "-----------------"
echo 
echo "RUNNING SCRIPT.SH"
echo 
echo "-----------------"
echo "."
echo "."
echo "."
make clean
echo "."
echo "."
echo "."
echo "CLEANED UP EXECUTABLES"
echo "."
echo "."
echo "."
make -f Makefile
echo "."
echo "."
echo "."
echo "COMPILED ALL FILES"
echo "."
echo "."
echo "."
echo "RUNNING TESTS:"

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
   diff -C 100 r1 myr1 > failure_test1
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
   #put the differences in a file
   diff -C 100 r2 myr2 > failure_test2
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
   #put the differences in a file
   diff -C 100 r3 myr3 > failure_test3
fi


################# test4 ######################
#put expected results in a file
./test4 > r4
#put actual results in a file
./mytest4 > myr4

#remove first line from files
echo "$(tail +2 r4)" > r4
echo "$(tail +2 myr4)" > myr4

#compare the expected with actual
echo "***** Test4 *****"
if cmp -s r4 myr4
then
   echo "PASS"
else
   echo "FAIL"
   #put the differences in a file
   diff -C 100 r4 myr4 > failure_test4

fi



################# test5 ######################
#put expected results in a file
./test5 > r5
#put actual results in a file
./mytest5 > myr5

#remove first line from files
echo "$(tail +2 r5)" > r5
echo "$(tail +2 myr5)" > myr5

#compare the expected with actual
echo "***** Test5 *****"
if cmp -s r5 myr5
then
   echo "PASS"
else
   echo "FAIL"
   #put the differences in a file
   diff -C 100 r5 myr5 > failure_test5
fi


################# test6 ######################
#put expected results in a file
./test6 > r6
#put actual results in a file
./mytest6 > myr6

#remove first line from files
echo "$(tail +2 r6)" > r6
echo "$(tail +2 myr6)" > myr6

#compare the expected with actual
echo "***** Test6 *****"
if cmp -s r6 myr6
then
   echo "PASS"
else
   echo "FAIL"
   #put the differences in a file
   diff -C 100 r6 myr6 > failure_test6
fi

################# test7 ######################
#put expected results in a file
./test7 > r7
#put actual results in a file
./mytest7 > myr7

#remove first line from files
echo "$(tail +2 r7)" > r7
echo "$(tail +2 myr7)" > myr7

#compare the expected with actual
echo "***** Test7 *****"
if cmp -s r7 myr7
then
   echo "PASS"
else
   echo "FAIL"
   #put the differences in a file
   diff -C 100 r7 myr7 > failure_test7
fi



################# test8 ######################
#put expected results in a file
./test8 > r8
#put actual results in a file
./mytest8 > myr8

#remove first line from files
echo "$(tail +2 r8)" > r8
echo "$(tail +2 myr8)" > myr8

#compare the expected with actual
echo "***** Test8 *****"
if cmp -s r8 myr8
then
   echo "PASS"
else
   echo "FAIL"
   #put the differences in a file
   diff -C 100 r8 myr8 > failure_test8
fi
