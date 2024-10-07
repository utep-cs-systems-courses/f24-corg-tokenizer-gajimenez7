# target build
all: tokenizer

# include file dependencies

readTokens.o: readTokens.c tokenizer.h
	cc -c readTokens.c

uimain.o: uimain.c tokenizer.h
	cc -c uimain.c

# prerequisites

tokenizer: uimain.o readTokens.o
	cc -o tokenizer uimain.o readTokens.o
# run

run:
	./tokenizer

# clean

clean:
	rm -f *.o tokenizer
