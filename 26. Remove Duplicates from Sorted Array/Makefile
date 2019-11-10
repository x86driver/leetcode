TARGET = 26
CFLAGS = -Wall -g -std=c11 -fsanitize=address
CPPFLAGS = -Wall -g -fsanitize=address
GTEST = `pkg-config gtest --cflags --libs` -DGOOGLE_TEST

all: $(TARGET)

26:26.c
	gcc $(CFLAGS) -o $@ $< -D_MAIN_

clean:
	rm -rf $(TARGET)
