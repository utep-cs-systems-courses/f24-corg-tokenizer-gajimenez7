# target build
all: tokenizer

# include file dependencies

readTokens.o: readTokens.c tokenizer.h
	cc -c readTokens.c

history.o: history.c history.h tokenizer.h
	cc -c history.c

uimain.o: uimain.c tokenizer.h history.h
	cc -c uimain.c

# prerequisites

tokenizer: uimain.o readTokens.o history.o
	cc -o tokenizer uimain.o readTokens.o history.o
# run

run:
	./tokenizer

# clean

clean:
	rm -f *.o tokenizer
