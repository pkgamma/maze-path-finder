CXX = clang++

main : main.cpp
	$(CXX) $? -o $@

.PHONY : run
run :
	./main

clean : 
	rm main