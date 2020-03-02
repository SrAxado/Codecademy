const menu = {
  _courses: {
    _appetizers: [],
    _mains: [],
    _desserts: [],
    set appetizers(appetizer) {
      this._appetizers.push(appetizer);
      /*
      switch (typeof appetizer) {
        case 'object':
          for (const singleAppetizer of appetizer) {
            this._appetizers.push(singleAppetizer);
          }
          break;
        case 'string':
          this._appetizers.push(appetizer);
          break;
        default:
          console.log('Unidentified appetizer');
      }
      //console.log(this._appetizers);
      */
    },
    get appetizers() {
      return this._appetizers;
      /*for (const key of this._appetizers) {
        return `${key}`;
      }*/
    },
    set mains(main) {
      this._mains.push(main);
    },
    get mains() {
      return this._mains;
    },
    set desserts(dessert) {
      this._desserts.push(dessert);
    },
    get desserts() {
      return this._desserts;
    }
  },
  get courses() {
    //return `${this.appetizers} + ${this.mains} + ${this.desserts}`;
    /*for (let [key, value] of this.appetizers.entries()) {
      console.log(`${key}: ${value}`);
    }*/
    let completeCourses = {};
    if (this._courses.appetizers.length) {
      //let appetizers = Object.assign({}, this._courses.appetizers);
      //completeCourses = {'Appetizers': appetizers};
      //completeCourses = {'Appetizers': Object.entries(this._courses.appetizers)};
      completeCourses = {'Appetizers': this._courses.appetizers};
      //completeCourses = Object.assign({'Appetizers': Object.entries(this._courses.appetizers)});
    }
    if (this._courses.mains.length) {
      completeCourses = Object.assign({'Mains': this._courses.mains}, completeCourses);
    }
    if (this._courses.desserts.length) {
      completeCourses = Object.assign({'Desserts': this._courses.desserts}, completeCourses);
    }
    return completeCourses;
  },
  set courses(course) {
    this._courses.appetizers = course;
  },
  addDishToCourse(courseName, dishName, dishPrice) {
    let dish = {name: dishName, price: dishPrice};
    switch (courseName) {
      case 'appetizer':
        this._courses.appetizers = dish;
        break;
      case 'main':
        this._courses.mains = dish;
        break;
      case 'dessert':
        this._courses.desserts = dish;
        break;
      default:
        console.log('Invalid course name');
    }
  },
  getRandomDishFromCourse(courseName) {
    let dishes = [];
    switch (courseName) {
      case 'appetizer':
        dishes = this._courses.appetizers;
        break;
      case 'main':
        dishes = this._courses.mains;
        break;
      case 'dessert':
        dishes = this._courses.desserts;
        break;
      default:
        console.log('Invalid course name');
    }
    const randomDish = Math.floor(Math.random() * dishes.length);
    return dishes[randomDish];
  },
  generateRandomMeal() {
    const appetizer = this.getRandomDishFromCourse('appetizer');
    const main = this.getRandomDishFromCourse('main');
    const dessert = this.getRandomDishFromCourse('dessert');
    
    let fullPrice = appetizer.price + main.price + dessert.price;
    
    return `    ${appetizer.name}\t\t${appetizer.price}€\n    ${main.name}\t\t${main.price}€\n    ${dessert.name}\t\t${dessert.price}€\n ---------------------------------\n\t\t\t${fullPrice}€`;
  }
}

//menu.courses = ['something good', 'other thing'];
//console.log(menu.appetizers);
//menu.courses = ['something 2', 'something 3', 'something 4'];
//menu._courses.mains = ['main1', 'main2'];
//menu._courses.desserts = ['dessert1', 'dessert2', 'dessert3', 'dessert4', 'dessert5'];
menu.addDishToCourse('appetizer', 'Azeitonas', 1);
menu.addDishToCourse('appetizer', 'Pão de água', 0.7);
menu.addDishToCourse('appetizer', 'Queijo', 0.5);
menu.addDishToCourse('main', 'Feijoada', 7);
menu.addDishToCourse('main', 'Sardinha', 10);
menu.addDishToCourse('main', 'Açorda', 5);
menu.addDishToCourse('dessert', 'Mousse', 3);
menu.addDishToCourse('dessert', 'Arroz Doce', 3);
menu.addDishToCourse('dessert', 'Aletria', 3);
//console.log(menu.appetizers);
//console.log(menu.courses);
//console.log(menu.getRandomDishFromCourse('dessert'));
let meal = menu.generateRandomMeal();
console.log(meal);
