g++ -o gen gen.cpp
g++ -o sol sol.cpp
g++ -o brute brute.cpp

for((i=1; ;i++)) do
	echo $i
	./gen $i > input
	./sol < input > output1
	./brute < input > output2
	diff -w output1 output2 || break
done