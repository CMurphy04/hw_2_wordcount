#!/bin/bash
# Created by: Nasseef Abukamail
#       Date: January 5, 2019
#
# Description:
#     Finds the main program and renames to PROGRAM.cc
#

file_name=`egrep -il ' main\s*\(' *.cc *.cpp *.cxx 2>/dev/null`
#sed 's/ main\s*(/ IGNORE(/' $file_name >_TEST/PROGRAM.cc
cp $file_name _TEST/PROGRAM.cc 2>/dev/null
echo '\033[0;33m' '######################################################################'
head _TEST/PROGRAM.cc
echo '\033[0;33m' '######################################################################'
echo '\033[m'
exit 0
