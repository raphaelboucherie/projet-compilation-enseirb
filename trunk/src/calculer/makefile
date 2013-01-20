all:
	bison -d lexya_a.y
	lex lexya_a.l
	cc -o parser  lex.yy.c   lexya_a.tab.c  -ll

clean:
	rm -rf *~
	rm -rf parser
	rm -rf lexya_a.tab.*
	rm -rf lex.yy.c