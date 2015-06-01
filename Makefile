main:
	clang++ main.cpp -O3 -g -pg -std=c++11 -o main.exe
	#clang++ main.cpp -O0 -g -pg -std=c++11 -o main.exe

clean:
	rm main.exe

graph:
	dot ./lolgraph.gv -Tpdf -o lolgraph.pdf

clean_g:
	rm graph.pdf

clean_f:
	rm filtrations/*