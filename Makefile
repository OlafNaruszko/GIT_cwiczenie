all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all test1 test2 test3

test1: 
	bin/gauss dane/A dane/b

test2: 
	bin/gauss dane/C dane/d
	
test3:
	bin/gauss dane/E dane/f