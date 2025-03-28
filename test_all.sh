#!/usr/bin/env bash

# Directory containing test files
TEST_DIR="./test"

# Binary path
CIVICC="./build-debug/civicc"

# Check if the compiler exists
if [ ! -f "$CIVICC" ]; then
    echo "Error: Compiler not found at $CIVICC"
    exit 1
fi

# Counters
TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0

# Run tests recursively
echo "Running tests..."
while IFS= read -r -d '' file; do
    echo "Testing: $file"
    ((TOTAL_TESTS++))

    # Run the compiler and capture output
    if "$CIVICC" "$file" >/dev/null 2>&1; then
        echo "✅ PASSED"
        ((PASSED_TESTS++))
    else
        echo "❌ FAILED"
        ((FAILED_TESTS++))
        # Show error output
        echo "=== Compiler Output ==="
        "$CIVICC" "$file"
        echo "======================"
    fi

    echo "--------------------------------"
done < <(find "$TEST_DIR" -type f -name "*.cvc" -print0)

# Summary
echo "Test Summary:"
echo "Total tests: $TOTAL_TESTS"
echo "Passed: $PASSED_TESTS"
echo "Failed: $FAILED_TESTS"

# Exit with error if any tests failed
if [ "$FAILED_TESTS" -gt 0 ]; then
    exit 1
fi
exit 0