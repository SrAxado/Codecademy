class BookNStuff {
  constructor(title) {
    this._title = title;
    this._isCheckedOut = false;
    this._ratings = [];
  }
  
  get title() {
    return this._title;
  }
  
  get isCheckedOut() {
    return this._isCheckedOut;
  }
  
  // I would say this method is unnecessary
  set isCheckedOut(checkStatus) { 
    this._isCheckedOut = checkStatus;
  }  
  
  get ratings() {
    return this._ratings;
  }
  
  getAverageRating() {
    let sumRatings = this._ratings.reduce(
      (accumulator, currentValue) => accumulator + currentValue, 0);
    return sumRatings / (this._ratings.length + 1);
  }

  addRating(newRating) {
    if (typeof newRating === 'number') {
      if ((newRating > 0) && (newRating <= 5)) {
        this._ratings.push(newRating);
      } else {
        console.log('The rating must be a value between 1 - 5');
      }
    } else {
      for (let rating of newRating) {
        if ((rating > 0) && (rating <= 5)) {
          this._ratings.push(rating);
        } else {
          console.log('The rating must be a value between 1 - 5');
        }
      }
    }
  }

  toggleCheckOutStatus() {
    this._isCheckedOut = !this._isCheckedOut;
  }
}


class Book extends BookNStuff {
  constructor(author, title, pages) {
    super(title);
    this._author = author;
    this._pages = pages;
  }
  
  get author() {
    return this._author;
  }
  
  get pages() {
    return this._pages;
  }
}

class Movie extends BookNStuff {
  constructor(director, title, runtime) {
    super(title);
    this._director = director;
    this._runtime = runtime;
  }
  
  get director() {
    return this._director;
  }
  
  get runtime() {
    return this._runtime;
  }
}

class CD extends BookNStuff {
  constructor(artist, title, songs) {
    super(title);
    this._artist = artist;
    this._songs = songs;
  }
  
  get artist() {
    return this._artist;
  }
  
  get songs() {
    return this._songs;
  }
  
  shuffle() {
    return this._songs[Math.floor(Math.random()*this._songs.length)];
  }
}

const historyOfEverything = new Book('Bill Bryson', 'A Short History of Nearly Everything', 544);

historyOfEverything.toggleCheckOutStatus();
historyOfEverything.addRating([4,5,5]);
historyOfEverything.addRating([4,5,5]);
console.log(historyOfEverything.getAverageRating());
console.log(historyOfEverything);

const speed = new Movie('Jan de Bont', 'Speed', 116);
speed.toggleCheckOutStatus();
console.log(speed.isCheckedOut);
speed.addRating(2);
speed.addRating([1,1,5]);
console.log(speed.getAverageRating());

const basketCase = new CD('GreenDay', 'Basket Case', ['Basket Case', 'On the Wagon', 'Tired of Waiting for You', '409 in Your Coffeemaker']);
console.log(basketCase.shuffle());
