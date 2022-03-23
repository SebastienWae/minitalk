CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
CPPFLAGS = -I../include -I../libft -I../ft_printf/include
LDFLAGS = -L../libft -lft -L../ft_printf -lftprintf -lcmocka

bytetobits.test: bytetobits.test.o bits.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ 
	./$@

bitstobyte.test: bitstobyte.test.o bits.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ 
	./$@

bits.o: ../src/bits.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o ./$@

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

