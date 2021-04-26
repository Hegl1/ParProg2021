make > /dev/null

echo "*"
echo "heat_stencil_2D.c"

for i in {100..500..100}
do
    echo "-"
    ./heat_stencil_2D.out $i

done

echo "*"
echo "heat_stencil_2D_parallel.c"

for i in {100..500..100}
do
    echo "-"
    OMP_NUM_THREADS=8 ./heat_stencil_2D_parallel.out $i

done

make clean > /dev/null