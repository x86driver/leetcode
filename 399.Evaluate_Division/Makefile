TARGET = 399
CFLAGS = -Wall -g -std=c11
CPPFLAGS = -Wall -g
GTEST = `pkg-config gtest --cflags --libs` -DGOOGLE_TEST

all: $(TARGET)

399:399.cpp
	g++ $(CPPFLAGS) -o $@ $<

clean:
	rm $(TARGET)
