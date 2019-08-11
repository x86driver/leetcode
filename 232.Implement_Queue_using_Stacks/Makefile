TARGET = 232 test_232
CFLAGS = -Wall -g -std=c11
CPPFLAGS = -Wall -g
GTEST = `pkg-config gtest --cflags --libs` -DGOOGLE_TEST

all: $(TARGET)

232:232.cpp
	g++ $(CPPFLAGS) -o $@ $<

test_232:232.cpp
	g++ $(CPPFLAGS) -o $@ $< $(GTEST)

clean:
	rm -rf $(TARGET)
