CLSRC=$(wildcard *.cl)
CLASM=$(subst .cl,.cl.s,$(CLSRC))
CSRC=$(wildcard *.c)
CASM=$(subst .c,.c.s,$(CSRC))
ASM=$(CASM)
ASM+=$(CLASM)
OBJS=$(subst .s,.o,$(ASM))

.PRECIOUS: $(ASM)

%.cl.s : %.cl
	clang $(CLFLAGS) -S -x cl -cl-std=CL1.2 -Xclang -finclude-default-header -c $< -o $@

%.c.s : %.c
	clang $(CFLAGS) -S -x c -std=c11 -c $< -o $@

%.o : %.s
	clang -c $< -o $@

thing : $(OBJS)
	clang $(LDFLAGS) -o $@ $^

all: thing

clean :
	rm ./*.o ./*.s ./thing 2>/dev/null