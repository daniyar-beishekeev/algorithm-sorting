# Rerun test
cycle=10
reportFile="report.txt"

> "${reportFile}"

for ((i=1; i<=cycle; i++)); do
  for file in tests/*; do
    echo "Running ${i} <- ${file}"
    ./main test "${file}" "Run,${i}<-${file}" >> "$reportFile"
    if [ $? -ne 0 ]; then
      echo "Error: Command failed, exiting..."
      exit 1
    fi
  done
done