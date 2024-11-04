
// Function to test
function can_place_flowers(flowerbed, n) {
  let count = 0; // Counter for planted flowers
  let length = flowerbed.length; // Length of the flowerbed

  for (let i = 0; i < length; i++) {
    // Check if the current plot is empty
    if (flowerbed[i] === 0) {
      // Check neighbors: prev is left neighbor, next is right neighbor
      let prev = i === 0 ? 0 : flowerbed[i - 1]; // If at start, pretend left is empty
      let next = i === length - 1 ? 0 : flowerbed[i + 1]; // If at end, pretend right is empty

      // If both neighbors are empty or out of bounds, we can plant a flower
      if (prev === 0 && next === 0) {
        flowerbed[i] = 1; // Plant the flower
        count++; // Increase flower count

        // Check if we have planted enough flowers
        if (count >= n) {
          return true; // We planted enough flowers
        }
      }
    }
    
  }

  // Final check to see if we planted enough flowers
  return count >= n;
}

// Test cases
function runTests() {
  // Example 1
  console.log(can_place_flowers([1, 0, 0, 0, 1], 1)); // Expected: true

  // Example 2
  console.log(can_place_flowers([1, 0, 0, 0, 1], 2)); // Expected: false

  // Single Plot Cases
  console.log(can_place_flowers([0], 1)); // Expected: true
  console.log(can_place_flowers([1], 1)); // Expected: false

  // All Plots Empty
  console.log(can_place_flowers([0, 0, 0, 0, 0], 3)); // Expected: true

  // All Plots Occupied
  console.log(can_place_flowers([1, 1, 1, 1, 1], 1)); // Expected: false

  // Large Input
  console.log(can_place_flowers([1, 0, 0, 0, 1, 0, 0, 0, 1], 2)); // Expected: true

  // Planting at the Ends
  console.log(can_place_flowers([0, 0, 0, 0, 1], 1)); // Expected: true

  // Edge of Array with One Flower Needed
  console.log(can_place_flowers([0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 5)); // Expected: true

  // Not Enough Space
  console.log(can_place_flowers([0, 0, 1, 0, 0, 0, 1, 0], 2)); // Expected: false

  // Large Enough Space
  console.log(can_place_flowers([0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 4)); // Expected: true
}

// Run tests
runTests();
