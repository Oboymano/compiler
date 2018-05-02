OBJS = bison.y flex.l 

CC = gcc

comp: $(OBJS)
	bison -d bison.y
	flex flex.l
	$(CC) bison.tab.c lex.yy.c 
	./a
bison: bison.y
	bison -d bison.y

clean:
	rm bison.tab.c bison.tab.h lex.yy.c a a.output file.asm