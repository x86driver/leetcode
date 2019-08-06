TARGET = 222
CFLAGS = -Wall -g -std=c11
CPPFLAGS = -Wall -g
GTEST = `pkg-config gtest --cflags --libs` -DGOOGLE_TEST

all: $(TARGET)

stringToTreeNode.o:../lib/stringToTreeNode.cpp
	g++ -c $(CPPFLAGS) -o $@ $<

draw_binary_tree.o:../lib/draw_binary_tree.c
	gcc -c $(CFLAGS) -o $@ $<

222:222.cpp stringToTreeNode.o draw_binary_tree.o
	g++ $(CPPFLAGS) -o $@ $^

clean:
	rm $(TARGET)
