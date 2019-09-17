TARGET = 20
CFLAGS = -Wall -g -std=c11
CPPFLAGS = -Wall -g
GTEST = `pkg-config gtest --cflags --libs` -DGOOGLE_TEST

all: $(TARGET)

20:20.cpp
	g++ $(CPPFLAGS) -o $@ $<

clean:
	rm -rf $(TARGET)
