.PHONY: all clean

all: bin/mapper bin/reducer bin/mapper_d bin/reducer_d

bin/mapper:
	mkdir -p bin
	g++ -o $@ mapper.cpp

bin/reducer:
	mkdir -p bin
	g++ -o $@ reducer.cpp

bin/mapper_d:
	mkdir -p bin
	g++ -o $@ mapper_d.cpp

bin/reducer_d:
	mkdir -p bin
	g++ -o $@ reducer_d.cpp

clean:
	rm -rf bin output