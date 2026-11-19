#!/bin/bash
/home/mamat/Projects/HW0/Q1/digit_freq < \
 /home/mamat/Projects/HW0/Q1/digit_freq.in \
 | diff - /home/mamat/Projects/HW0/Q1/digit_freq.out && echo PASS || echo FAIL