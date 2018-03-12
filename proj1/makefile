# Project 1, Linux/GCC version
# Authored by Prof. Don Heller and Prof. Bhuvan Urgaonkar
# Files:  proj1.h proj1.c proj1_var.c proj1_func.c makefile

# make -f makefile.linux

proj1: proj1.h proj1.c proj1_var.c proj1_func.c
	gcc          -m32 -o pr1_c89_32 -W -Wall proj1.c proj1_var.c proj1_func.c -lm

clean:
	-rm pr1_c89_32 *.o

Clean: clean
	-rm a.out out.*
