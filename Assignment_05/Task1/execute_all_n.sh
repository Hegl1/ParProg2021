Make times > /dev/null

echo "*"
echo "Delannoy_ser.c"

for i in {3..15}
do
    echo "-"
    ./delannoy_ser.out $i

done
echo "*"
echo "Delannoy_stupid.c"

for i in {3..15}
do
    echo "-"
    ./delannoy_stupid.out $i

done
echo "*"
echo "Delannoy_par.c"

for i in {3..15}
do
    echo "-"
    ./delannoy_par.out $i 8

done

Make clean > /dev/null