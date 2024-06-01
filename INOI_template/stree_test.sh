g++ -o gen gen.cpp
g++ -o sol sol.cpp
g++ -o brute brute.cpp

for((i=1; ; i++)) do
	echo $i
	./gen $i > input
	./brute < input > out1
	./sol < input > out2
	diff -w out1 out2 || break
done