#!/bin/bash
echo "Single thread"
./single

echo "Multi thread"
for ((i=1;i<=3;i++)); do
    echo "Number of thread = $i"
    ./multi $i
done
