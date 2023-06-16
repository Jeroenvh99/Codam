#!/bin/bash

make -C ./..
./../megaphone > no_input.txt
output=$(diff no_input.txt feedback.txt)

if [ -n "$output"]
then
	echo 'OK'
else
	echo 'KO'
fi

./../megaphone hei this er a test > hei_test.txt
output=$(diff hei_test.txt hei.txt)

if [ -n "$output"]
then
	echo 'OK'
else
	echo 'KO'
fi

./../megaphone hei thIs "er a" Test > hei_test.txt
output=$(diff hei_test.txt hei.txt)

if [ -n "$output"]
then
	echo 'OK'
else
	echo 'KO'
fi