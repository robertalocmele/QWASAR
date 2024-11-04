# Define the detonation_in function to print the countdown message
def detonation_in(seconds_left)
  puts("detonation in... #{seconds_left} seconds.")
end

# Initialize the timer at 10
timer = 10

# Run the countdown loop until timer reaches 0
while timer > 0
  detonation_in(timer)   # Call the function with the current timer value
  timer -= 1             # Decrement the timer
end