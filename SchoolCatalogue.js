class School {
  constructor(name, level, numberOfStudents) {
    this._name = name;
    if (['Primary', 'Middle', 'High'].includes(level)) {
      this._level = level;
    } else {
      console.log('The level of the school must be: Primary, Middle or High');
    };
    if (typeof numberOfStudents === 'number') {
      this._numberOfStudents = numberOfStudents;
    } else {
      console.log('Invalid input: numberOfStudents must be set to a number');
    }
  }
  
  get name() {
    return this._name;
  }
  
  get level() {
    return this._level;
  }
  
  get numberOfStudents() {
    return this._numberOfStudents;
  }
  
  quickFacts() {
    console.log(`${this.name} educates ${this.numberOfStudents} students at the ${this.level} school level.`);
  }
  
  static pickSubstituteTeacher(substituteTeachers) {
    return substituteTeachers[Math.floor(Math.random() * substituteTeachers.length)];
  }
  
  set numberOfStudents(number) {
    if (typeof numberOfStudents === 'number') {
      this._numberOfStudents = numberOfStudents;
    } else {
      console.log('Invalid input: numberOfStudents must be set to a number');
    }
  }
}


class PrimarySchool extends School {
  constructor(name, numberOfStudents, pickUpPolicy) {
    super(name, 'Primary', numberOfStudents);
    this._pickUpPolicy = pickUpPolicy;
  }
  
  get pickUpPolicy() {
    return this._pickUpPolicy;
  }
}

class MiddleSchool extends School {
  constructor(name, numberOfStudents) {
    super(name, 'Middle', numberOfStudents);
  }
}

class HighSchool extends School {
  constructor(name, numberOfStudents, sportsTeams) {
    super(name, 'High', numberOfStudents);
    this._sportsTeams = [];
    this._sportsTeams.push(sportsTeams);
  }
  
  get sportsTeams() {
    return this._sportsTeams;
  }
  
  set sportsTeams(sportTeam) {
    this._sportsTeams.push(sportTeam);
  }
}


//const escolaDaQuinta = new HighSchool('Escola da Quinta', 20, 'Equipa do Zé');
//escolaDaQuinta.sportsTeams = 'O Galos do Zé';
//EscolaDaQuinta.quickFacts();
//console.log(escolaDaQuinta);
//console.log(School.pickSubstituteTeacher(['Zé', 'Maria', 'Manel', 'Josefina']));

const lorraineHansbury = new PrimarySchool('Lorraine Hansbury', 514, 'Students must be picked up by a parent, guardian, or a family member over the ae of 13.');
lorraineHansbury.quickFacts();
console.log(School.pickSubstituteTeacher(['Jamal Crawford', 'Lou Williams', 'J. R. Smith', 'James Harden', 'Jason Terry', 'Manu Ginobli']));

const alSmith = new HighSchool('Al E. Smith', 415, ['Baseball', 'Basketball', 'Volleyball', 'Track and Field']);
console.log(alSmith.sportsTeams);
