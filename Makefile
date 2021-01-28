.PHONY: test
test:
	g++ ./src/example.cpp -o ./bin/example && ./bin/example

.PHONY: curl
curl:
	g++ ./src/curl.cpp -lcurl -o ./bin/curl && ./bin/curl
