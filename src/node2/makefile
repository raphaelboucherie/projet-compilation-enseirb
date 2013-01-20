all:
	bison -d lexya_e.y
	lex lexya_e.l
	gcc -g -o parser lex.yy.c lexya_e.tab.c
	#cc -o parser lex.yy.c lexya_b.tab.c  -ll
clean:
	rm -rf *~
	rm -rf parser
	rm -rf lexya_e.tab.*
	rm -rf lex.yy.c