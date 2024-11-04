# Welcome to My Spaceship
***

## Task
The task is to create a simulator for a spaceship's flight path. The spaceship starts at position (0, 0) facing "up" and can follow three types of commands:

R for turning right,
L for turning left,
A for advancing forward.
The challenge lies in tracking the spaceship’s position (x, y) and its final direction (up, down, left, or right) after following the provided commands. Your function needs to return the final coordinates and direction as a string.

## Description
To solve this problem, I wrote a JavaScript function my_spaceship that:

Starts with the spaceship at position (0, 0) facing "up".
Reads the input string of commands and updates the spaceship’s direction and position as it processes each command.
After all commands are processed, the function returns the final coordinates and direction in the format "{x: X, y: Y, direction: 'DIRECTION'}".
For example:

If the input is "RAALALL", the spaceship will end up at {x: 2, y: -1, direction: 'down'}.

## Installation
There’s no special setup required for this project. Since it's a simple JavaScript function, you just need a way to run JavaScript, such as Node.js or any online JavaScript editor.

## Usage
Once installed, you can run the function and test different flight paths.

Inside the file, you can call the my_spaceship function with the flight path as a string argument:

console.log(my_spaceship("RAALALL")); 

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
