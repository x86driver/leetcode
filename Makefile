TARGET = 5 17 622 654
TARGET += test_5 test_17
CFLAGS = -Wall -g -std=c11
CPPFLAGS = -Wall -g
GTEST = `pkg-config gtest --cflags --libs` -DGOOGLE_TEST

all: $(TARGET)

5:5.Longest_Palindromic_Substring.c
	gcc $(CFLAGS) -o $@ $<

test_5:test_5.cpp 5.Longest_Palindromic_Substring.c
	g++ $(CPPFLAGS) -o $@ $^ $(GTEST)

17:17.Letter_Combinations_of_a_Phone_Number.c
	gcc $(CFLAGS) -o $@ $<

test_17:test_17.cpp 17.Letter_Combinations_of_a_Phone_Number.c
	g++ $(CPPFLAGS) -o $@ $^ $(GTEST)

622:622.Design_Circular_Queue.c
	gcc $(CFLAGS) -o $@ $<

654:654.Maximum_Binary_Tree.c
	gcc $(CFLAGS) -o $@ $<

clean:
	rm -rf $(TARGET)
