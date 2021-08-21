# The default target of this Makefile is...
cc = gcc
prom = calc
deps += test.h
deps += func.h
src += func.c
src += test.c
obj = $(src:%.c=%.o) 

$(prom): $(obj)
	$(cc) -g -o $(prom) $(obj)

%.o: %.c $(deps)
	$(cc) -g -c $< -o $@

clean:
	rm -rf $(obj) $(prom)