.PHONY: test
test:
	g++ ./src/main.cpp -lcurl -o ./bin/example && ./bin/example
