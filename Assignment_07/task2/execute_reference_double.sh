make times_r_double > /dev/null

echo "*"
echo "DOUBLE REFERENCE"

for ((COUNTER=2048; COUNTER<=14336; COUNTER+=2048));
do
    echo "-"
    ./task2_d.out $COUNTER

done

make clean > /dev/null