g++ -o gen gen.cpp
g++ -std=gnu++17 -O2 -Wall -pipe -static -o "sol" "stub.cpp" "sol.cpp"
g++ -std=gnu++17 -O2 -Wall -pipe -static -o "brute" "stub.cpp" "brute.cpp"

for((i=1; ;i++)) do
	echo $i
	./gen $i > input
	./sol < input > output1
	./brute < input > output2
	diff -w output1 output2 || break
done