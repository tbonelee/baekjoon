./a.out < input
echo $? > result
./b.out < result
