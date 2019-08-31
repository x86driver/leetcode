TARGET = 169
CFLAGS = -Wall -g -std=c11
CPPFLAGS = -Wall -g
GTEST = `pkg-config gtest --cflags --libs` -DGOOGLE_TEST

all: $(TARGET)

169:169.cpp
	g++ $(CPPFLAGS) -o $@ $<

clean:
	rm -rf $(TARGET)
