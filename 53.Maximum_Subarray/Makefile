TARGET = 53
CFLAGS = -Wall -Werror -g -std=c11 -fsanitize=address
CPPFLAGS = -Wall -g
GTEST = `pkg-config gtest --cflags --libs` -DGOOGLE_TEST

all: $(TARGET)

53:53.c
	gcc $(CFLAGS) -o $@ $<

clean:
	rm -rf $(TARGET)
