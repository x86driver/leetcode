TARGET = 53 53_inplace
CFLAGS = -Wall -Werror -g -std=c11 -fsanitize=address
CPPFLAGS = -Wall -g
GTEST = `pkg-config gtest --cflags --libs` -DGOOGLE_TEST

all: $(TARGET)

53:53.c
	gcc $(CFLAGS) -o $@ $<

53_inplace:53_inplace.c
	gcc $(CFLAGS) -o $@ $<

clean:
	rm -rf $(TARGET)
