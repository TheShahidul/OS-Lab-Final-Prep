#!/bin/bash

count_char() {
    input="$1"
    alphabets=$(echo "$input" | tr -dc '[:alpha:]' | wc -c)
    digits=$(echo "$input" | tr -dc '[:digit:]' | wc -c)
    special=$(echo "$input" | tr -dc '[:punct:]' | wc -c)

    echo "Alphabets = $alphabets"
    echo "Digits = $digits"
    echo "Special characters = $special"
}

read -r -p "Enter a string: " input_string

count_char "$input_string"
