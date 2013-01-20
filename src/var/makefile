all:
	bison -d lexya_b.y
	lex lexya_b.l
	gcc -g -o parser lex.yy.c lexya_b.tab.c
	#cc -o parser lex.yy.c lexya_b.tab.c  -ll
clean:
	rm -rf *~
	rm -rf parser
	rm -rf lexya_b.tab.*
	rm -rf lex.yy.c