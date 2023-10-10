#!/bin/bash

make -C ./..
printf 'SEARCH\nEXIT\n' | ./../Phonebook
printf 'ADD\njeroen\nvan\nhalderen\n45\nhoi\nSEARCH\n0\nEXIT\n' | ./../Phonebook
printf 'ADD\nje\nweet\nwel\n45\nhoi\n
ADD\njeroen\nvan\nhalderen\n45\nhoi\n
ADD\njeroen\nvan\nhalderen\n45\nhoi\n
ADD\njeroen\nvan\nhalderen\n45\nhoi\n
ADD\njeroen\nvan\nhalderen\n45\nhoi\n
ADD\njeroen\nvan\nhalderen\n45\nhoi\n
ADD\njeroen\nvan\nhalderen\n45\nhoi\n
ADD\nhi\nvan\nhalderen\n45\nhoi\nSEARCH\n4\n
ADD\njeroen\nvan\nhalderen\n45\nhoi\nSEARCH\n0\nEXIT\n' | ./../Phonebook
make fclean -C ./..