g++ -o gen ./gen.cpp
g++ -o sol ./sol.cpp
g++ -o brute ./brute.cpp

for((i=1; ; ++i)); do
	echo $i
	./gen $i > input
	./sol < input > out2
	./brute < out2 > out_brute
	diff -w out_brute input || break
done