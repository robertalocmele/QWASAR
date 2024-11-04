function my_spaceship(flightPath) {
  let x = 0;
  let y = 0;
  let directions = ["up", "right", "down", "left"];
  let currentDirectionIndex = 0;

  for (let i = 0; i < flightPath.length; i++) {
    let command = flightPath[i];

    if (command === "R") {
      currentDirectionIndex = (currentDirectionIndex + 1) % 4;
    } else if (command === "L") {
      currentDirectionIndex = (currentDirectionIndex + 3) % 4;
    } else if (command === "A") {
      let currentDirection = directions[currentDirectionIndex];

      if (currentDirection === "up") {
        y -= 1;
      } else if (currentDirection === "down") {
        y += 1;
      } else if (currentDirection === "right") {
        x += 1;
      } else if (currentDirection === "left") {
        x -= 1;
      }
    }
  }

  return `{x: ${x}, y: ${y}, direction: '${directions[currentDirectionIndex]}'}`;
}
