TARGET = 3
CFLAGS = -Wall -g -std=c11
CPPFLAGS = -Wall -g
GTEST = `pkg-config gtest --cflags --libs` -DGOOGLE_TEST

all: $(TARGET)

3:3.cpp
	g++ $(CPPFLAGS) -o $@ $<

clean:
	rm $(TARGET)
