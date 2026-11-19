#!/bin/bash
./dist/digit_freq < digit_freq.in | diff - digit_freq.out && echo PASS ||\
 echo FAIL
#/home/mamat/Projects/HW0/Q1digit_freq <\
# /home/mamat/Projects/HW0/Q1digit_freq.in\
# | diff - /home/mamat/Projects/HW0/Q1digit_freq.out && echo PASS || echo FAIL