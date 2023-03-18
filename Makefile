CXXFLAGS ?= -Wall -Wextra -pedantic
CFLAGS ?= -std=c89 -Wall -Wextra -pedantic

.PHONY: test clean
test: example_test.c
	@$(CC) $(CFLAGS) -o test example_test.c
	@echo c
	@./test
	@cp example_test.c example_test.cpp
	@echo
	@echo cpp
	@$(CXX) $(CXXFLAGS) -o test_cpp example_test.cpp
	@./test_cpp

clean:
	$(RM) *.o example_test.cpp test test_cpp
