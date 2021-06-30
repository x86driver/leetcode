TARGET = 811
CFLAGS = -Wall -g -std=c11 -fsanitize=address
CPPFLAGS = -Wall -g -fsanitize=address
GTEST = `pkg-config gtest --cflags --libs` -DGOOGLE_TEST

all: $(TARGET)

811:811.cpp
	g++ $(CPPFLAGS) -o $@ $< -D_MAIN_

clean:
	rm -rf $(TARGET)
