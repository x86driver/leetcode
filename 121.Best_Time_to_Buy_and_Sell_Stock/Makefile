TARGET = 121
CFLAGS = -Wall -g -std=c11
CPPFLAGS = -Wall -g
GTEST = `pkg-config gtest --cflags --libs` -DGOOGLE_TEST

all: $(TARGET)

121:121.c
	gcc $(CFLAGS) -o $@ $<

clean:
	rm -rf $(TARGET)
