#!/bin/bash

# Directory containing test files
TEST_DIR="./test"

# Binary path
CIVICC="./build-debug/civicc"

# Check if the compiler exists
if [ ! -f "$CIVICC" ]; then
    echo "Error: Compiler not found at $CIVICC"
    exit 1
fi

# Run tests
echo "Running tests..."
for file in "$TEST_DIR"/*.cvc; do
    echo "Testing: $file"
    "$CIVICC" "$file"
    echo "--------------------------------"
done

echo "All tests completed."