TARGET = 66 #test_66
CFLAGS = -Wall -g -std=c11 -fsanitize=address
CPPFLAGS = -Wall -g -fsanitize=address
GTEST = `pkg-config gtest --cflags --libs` -DGOOGLE_TEST

all: $(TARGET)

66:66.c
	gcc $(CFLAGS) -o $@ $< -D_MAIN_

test_66:test_66.cpp 66.c
	g++ $(CPPFLAGS) -o $@ $^ $(GTEST)

clean:
	rm -rf $(TARGET)
