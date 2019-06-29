TARGET = 17
TARGET += test_17
CFLAGS = -Wall -g
GTEST = `pkg-config gtest --cflags --libs` -DGOOGLE_TEST

all: $(TARGET)

17:17.Letter_Combinations_of_a_Phone_Number.c
	gcc $(CFLAGS) -o $@ $<

test_17:test_17.cpp 17.Letter_Combinations_of_a_Phone_Number.c
	g++ $(CFLAGS) -o $@ $^ $(GTEST)

clean:
	rm -rf $(TARGET)
