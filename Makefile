TARGET = 5 17 138 146 622 654 706
TARGET += test_5 test_17 test_146 test_706
TARGET += list list.o hashmap.o queue.o
CFLAGS = -Wall -g -std=c11
CPPFLAGS = -Wall -g
GTEST = `pkg-config gtest --cflags --libs` -DGOOGLE_TEST

all: $(TARGET)

list:lib/list.c lib/list.h
	gcc $(CFLAGS) -o $@ $<

list.o:lib/list.c lib/list.h
	gcc -c -D_LIB_ $(CFLAGS) -o $@ $<

hashmap.o:lib/hashmap.c lib/hashmap.h
	gcc -c -D_LIB_ $(CFLAGS) -o $@ $<

queue.o:lib/queue.c lib/queue.h
	gcc -c -D_LIB_ $(CFLAGS) -o $@ $<

5:5.Longest_Palindromic_Substring.c
	gcc $(CFLAGS) -o $@ $<

test_5:test_5.cpp 5.Longest_Palindromic_Substring.c
	g++ $(CPPFLAGS) -o $@ $^ $(GTEST)

17:17.Letter_Combinations_of_a_Phone_Number.c
	gcc $(CFLAGS) -o $@ $<

test_17:test_17.cpp 17.Letter_Combinations_of_a_Phone_Number.c
	g++ $(CPPFLAGS) -o $@ $^ $(GTEST)

138:138.Copy_List_with_Random_Pointer.cpp
	g++ $(CPPFLAGS) -o $@ $<

146.o:146.LRU_Cache.c
	gcc -c $(CFLAGS) -o $@ $<

146:146.LRU_Cache.c queue.o hashmap.o
	gcc -D_MAIN_ $(CFLAGS) -o $@ $^

test_146:test_146.cpp 146.o queue.o hashmap.o
	g++ $(CPPFLAGS) -o $@ $^ $(GTEST)

622:622.Design_Circular_Queue.c
	gcc $(CFLAGS) -o $@ $<

654:654.Maximum_Binary_Tree.c
	gcc $(CFLAGS) -o $@ $<

706:706.Design_HashMap.c
	gcc $(CFLAGS) -o $@ $^

test_706:test_706.cpp 706.Design_HashMap.c
	g++ $(CPPFLAGS) -o $@ $^ $(GTEST)

clean:
	rm -rf $(TARGET)
