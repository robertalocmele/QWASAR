function getRandomValueWithinRange(min, max) {
  return Math.floor(Math.random() * (max - min + 1) + min);
}

function getRandomSong() {
  const frank_sinatra_songs = [
    "My Way",
    "New York, New York",
    "Fly Me to the Moon",
    "Strangers in the Night",
    "Come Fly with Me",
    "The Way You Look Tonight",
    "Luck Be a Lady",
    "I Did It My Way",
    "Mack the Knife",
    "Summer Wind",
    "You Make Me Feel So Young",
    "That's Life",
    "For Once in My Life",
    "Witchcraft",
    "Night and Day",
    "I've Got You Under My Skin",
    "It Was a Very Good Year",
    "The Girl from Ipanema",
    "I Get a Kick Out of You",
    "All the Way",
    "One for My Baby (and One More for the Road)",
    "What Is This Thing Called Love?",
    "Embraceable You",
  ];

  const randomIndex = getRandomValueWithinRange(
    0,
    frank_sinatra_songs.length - 1
  );
  return frank_sinatra_songs[randomIndex];
}

module.exports = {
  getRandomSong,
};
