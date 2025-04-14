echo "Test generator shell:"

mkdir -p tests/

arr_n=(1000 20000 70000 200000 1000000)

types=(
  "3 genPermutation"
  "1 genPermutationSorted"
  "1 genPermutationReversed"
  "1 genIdentical"
  "3 genBalanced"
  "3 genAbsolute"
  "3 genAbsoluteSmall"
)

for idx in "${!arr_n[@]}"; do
  n="${arr_n[$idx]}"
  for entry in "${types[@]}"; do
    read -r num tp <<< "$entry"
    for ((i=1; i<=num; i++)); do
      filename="tests/level$((idx+1))_n${n}_${tp}_v${i}.in"
      echo "Generating: ${filename}"
      ./main gen "$n" "$tp" "${filename}"
    done
  done
done
