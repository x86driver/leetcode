TARGET = 122
CFLAGS = -Wall -g -std=c11 -fsanitize=address
CPPFLAGS = -Wall -g
GTEST = `pkg-config gtest --cflags --libs` -DGOOGLE_TEST

all: $(TARGET)

122:122.c
	gcc $(CFLAGS) -o $@ $<

clean:
	rm -rf $(TARGET)
