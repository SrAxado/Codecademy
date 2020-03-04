const team = {
  _players: [{firstName: 'Pablo', lastName: 'Sanchez', age: 11},
             {firstName: 'Peblo', lastName: 'Senchez', age: 12},
             {firstName: 'Piblo', lastName: 'Sinchez', age: 13}],
  _games: [{opponent: 'Broncos', teamPoints: 42, opponentPoints: 47},
           {opponent: 'Brincos', teamPoints: 41, opponentPoints: 46},                
           {opponent: 'Brencos', teamPoints: 40, opponentPoints: 45}],
  set players(player) {
    this._players.push(player);
  },
  get players() {
    return this._players;
  },
  set games(game) {
    this._games.push(game);
  },
  get games() {
    return this._games;
  },
  addPlayer(firstName, lastName, age) {
    this.players = {firstName, lastName, age};
  },
  addGame(opponent, teamPoints, opponentPoints) {
    this.games = {opponent, teamPoints, opponentPoints};
  }
}


//team.players = {firstName: 'Poblo', lastName: 'Sonchoz', age: 14};
team.addPlayer('Steph', 'Curry', 28);
team.addPlayer('Lisa', 'Leslie', 44);
team.addPlayer('Bugs', 'Bunny', 76);
team.addGame('Brancos', 43, 44);
team.addGame('Bruncos', 45, 40);
console.log(team.games);
