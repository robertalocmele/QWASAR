/*
function richestCustomer(accounts) {
  let richestCustomersWealth = 0;
  let accountSum = [];

  for (let person = 0; person < accounts.length; person++) {
    let currentAcc = 0;

    for (let bankAcc = 0; bankAcc < accounts[person].length; bankAcc++) {
      // Corrected the typo in accessing the account
      currentAcc += accounts[person][bankAcc]; // Fixed typo: account -> accounts and changed person[bankAcc] to accounts[person][bankAcc]
    }

    accountSum.push(currentAcc);
  }

  // Find the richest customer's wealth
  for (let i = 0; i < accountSum.length; i++) {
    if (accountSum[i] > richestCustomersWealth) {
      richestCustomersWealth = accountSum[i];
    }
  }

  return richestCustomersWealth; // Return the wealth of the richest customer
}

// Test cases
const accounts1 = [
  [1, 2, 3],
  [3, 2, 1],
];
const accounts2 = [
  [1, 5],
  [7, 3],
  [3, 5],
];
const accounts3 = [
  [2, 8, 7],
  [7, 1, 3],
  [1, 9, 5],
];

console.log(richestCustomer(accounts1)); // Should return 6
console.log(richestCustomer(accounts2)); // Should return 10
console.log(richestCustomer(accounts3)); // Should return 17

console.log(richestCustomer(accounts2));
*/

function richestCustomer(accounts) {
  // Constraint 1: Check number of customers (m)
  if (accounts.length < 1 || accounts.length > 50) {
    throw new Error("The number of customers must be between 1 and 50.");
  }

  let richestCustomersWealth = 0;
  let accountSum = [];

  for (let person = 0; person < accounts.length; person++) {
    // Constraint 2: Check number of accounts (n)
    if (accounts[person].length < 1 || accounts[person].length > 50) {
      throw new Error(
        `Customer ${person + 1} must have between 1 and 50 accounts.`
      );
    }

    let currentAcc = 0;

    for (let bankAcc = 0; bankAcc < accounts[person].length; bankAcc++) {
      // Constraint 3: Check account value
      if (accounts[person][bankAcc] < 1 || accounts[person][bankAcc] > 100) {
        throw new Error(
          `Account value for customer ${person + 1}, account ${
            bankAcc + 1
          } must be between 1 and 100.`
        );
      }

      currentAcc += accounts[person][bankAcc]; // Sum the money in each account
    }

    accountSum.push(currentAcc);
  }

  // Find the richest customer's wealth
  for (let i = 0; i < accountSum.length; i++) {
    if (accountSum[i] > richestCustomersWealth) {
      richestCustomersWealth = accountSum[i];
    }
  }

  return richestCustomersWealth; // Return the wealth of the richest customer
}

// Test cases
try {
  const accounts1 = [
    [1, 2, 3],
    [3, 2, 1],
  ];
  console.log(richestCustomer(accounts1)); // Should return 6

  const accounts2 = [
    [1, 5],
    [7, 3],
    [3, 5],
  ];
  console.log(richestCustomer(accounts2)); // Should return 10

  const accounts3 = [
    [2, 8, 7],
    [7, 1, 3],
    [1, 9, 5],
  ];
  console.log(richestCustomer(accounts3)); // Should return 17

  const invalidAccounts = [[1, 150]]; // Invalid value (150 > 100)
  console.log(richestCustomer(invalidAccounts)); // This will throw an error
} catch (error) {
  console.error(error.message); // Catch and display any error messages
}
