CC = cc
CFLAGS = -Wall -Wextra -Werror
PROGRAMS = exec1 exec2 exec3 exec4 exec5 my_timeout

all: $(PROGRAMS)

exec1: exec1.c
	$(CC) $(CFLAGS) -o $@ $<

exec2: exec2.c
	$(CC) $(CFLAGS) -o $@ $<

exec3: exec3.c
	$(CC) $(CFLAGS) -o $@ $<

exec4: exec4.c
	$(CC) $(CFLAGS) -o $@ $<

exec5: exec5.c
	$(CC) $(CFLAGS) -o $@ $<

my_timeout: my_timeout.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGRAMS)

.PHONY: all clean
