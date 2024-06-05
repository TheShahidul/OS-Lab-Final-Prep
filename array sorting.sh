array=( 10 3 2 20 21 28 64 )
sorted_array=($(printf "%s\n" "${array[@]}" | sort -n ))

echo ${sorted_array[@]}