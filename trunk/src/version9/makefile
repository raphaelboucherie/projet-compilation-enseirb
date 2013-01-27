CFLAGS=   # -g, -O3 , ... par exemple
LDFLAGS=-ll -ly # les bibliotheques necessaires
CC=gcc

all: rubic

userdef.o:userdef.c
	gcc -c $<
node.o   :node.c
	gcc -c $<
llvm.o  :llvm.c
	gcc -c $<
lex.yy.c: scanner.l
	lex $<
y.tab.c: parse.y
	yacc -d $<
y.tab.o: y.tab.c y.tab.h userdef.o
	$(CC) $(CFLAGS) -c $<
lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) -c $<
rubic: y.tab.o lex.yy.o userdef.o node.o llvm.o
	$(CC) -o $@ $^ $(LDFLAGS)

cal:
	./rubic < ./exemple/cal
var:
	./rubic < ./exemple/var
condition:
	./rubic < ./exemple/condition
boucle:
	./rubic < ./exemple/boucle
def:
	./rubic < ./exemple/def
class:
	./rubic < ./exemple/class

test:
	llvm-as file.ll -f -o file.bc
	llvm-ld -o=file -native file.bc
	./file

clean:
	rm -rf *~
	rm -rf rubic
	rm -rf y.tab.*
	rm -rf lex.yy.*
	rm -rf *.o
	rm -rf \#*
	rm -rf main
	rm -rf a.out
	rm -rf file*
	rm -rf ./exemple/*~
