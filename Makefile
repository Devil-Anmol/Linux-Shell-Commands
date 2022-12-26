# default: ls rm cat date anmol
anmol: ls cat date rm mkdir run
	./run

run : shell.c
	gcc -o run shell.c

ls : ls.c
	gcc -o ls ls.c

rm : rm.c
	gcc -o rm rm.c

cat : cat.c
	gcc -o cat cat.c

date : date.c
	gcc -o date date.c

mkdir : mkdir.c
	gcc -o mkdir mkdir.c

clean:
	rm ls rm cat date mkdir run
