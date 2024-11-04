const express = require("express");
const app = express();

const songs = [
  "New York, New York",
  "My Way",
  "Strangers in the Night",
  "Fly Me to the Moon",
  "I've Got You Under My Skin",
  "The Way You Look Tonight",
  "Come Fly with Me",
  "Summer Wind",
  "That's Life",
  "Luck Be a Lady",
  "The Best Is Yet to Come",
  "It Was a Very Good Year",
  "All or Nothing at All",
  "Witchcraft",
  "I Get a Kick Out of You",
  "Young at Heart",
  "One for My Baby",
  "Night and Day",
  "You Make Me Feel So Young",
  "Love and Marriage",
];

const basicAuth = require("express-basic-auth");
const authMiddleware = basicAuth({
  users: { admin: "admin" },
  challenge: true,
  unauthorizedResponse: "Not authorized",
});

app.get("/", (req, res) => {
  const randomSong = songs[Math.floor(Math.random() * songs.length)];
  res.send(randomSong);
});

app.get("/birth_date", (req, res) => {
  res.send("December 12, 1915");
});

app.get("/birth_city", (req, res) => {
  res.send("Hoboken, New Jersey");
});

app.get("/wives", (req, res) => {
  res.send("Nancy Barbato, Ava Gardner, Mia Farrow, Barbara Marx");
});

app.get("/picture", (req, res) => {
  res.redirect(
    "https://en.wikipedia.org/wiki/Frank_Sinatra#/media/File:Frank_Sinatra2,_Pal_Joey.jpg"
  );
});

app.get("/public", (req, res) => {
  res.send("Everybody can see this page");
});

app.get("/protected", authMiddleware, (req, res) => {
  res.send("Welcome, authenticated client");
});

const PORT = 8080;
app.listen(PORT, "0.0.0.0", () => {
  console.log(`Server is running on http://0.0.0.0:${PORT}`);
});
