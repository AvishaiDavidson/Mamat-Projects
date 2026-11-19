#!/bin/bash
/home/mamat/Projects/HW0/Q2/2sum < \
 /home/mamat/Projects/HW0/Q2/2sum.in |\
 grep -oE "\([0-9]+, [0-9]+\)" |\
 diff - /home/mamat/Projects/HW0/Q2/2sum.out && echo PASS || echo FAIL
