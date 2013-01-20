all:
	bison -d lexya_c.y
	lex lexya_c.l
	gcc -g -o parser lex.yy.c lexya_c.tab.c
	#cc -o parser lex.yy.c lexya_b.tab.c  -ll
clean:
	rm -rf *~
	rm -rf parser
	rm -rf lexya_c.tab.*
	rm -rf lex.yy.c