// All valid credit card numbers
const valid1 = [4, 5, 3, 9, 6, 7, 7, 9, 0, 8, 0, 1, 6, 8, 0, 8];
const valid2 = [5, 5, 3, 5, 7, 6, 6, 7, 6, 8, 7, 5, 1, 4, 3, 9];
const valid3 = [3, 7, 1, 6, 1, 2, 0, 1, 9, 9, 8, 5, 2, 3, 6];
const valid4 = [6, 0, 1, 1, 1, 4, 4, 3, 4, 0, 6, 8, 2, 9, 0, 5];
const valid5 = [4, 5, 3, 9, 4, 0, 4, 9, 6, 7, 8, 6, 9, 6, 6, 6];
const validTemp = [4, 5, 3, 9, 6, 8, 9, 8, 8, 7, 7, 0, 5, 7, 9, 8];

// All invalid credit card numbers
const invalid1 = [4, 5, 3, 2, 7, 7, 8, 7, 7, 1, 0, 9, 1, 7, 9, 5];
const invalid2 = [5, 7, 9, 5, 5, 9, 3, 3, 9, 2, 1, 3, 4, 6, 4, 3];
const invalid3 = [3, 7, 5, 7, 9, 6, 0, 8, 4, 4, 5, 9, 9, 1, 4];
const invalid4 = [6, 0, 1, 1, 1, 2, 7, 9, 6, 1, 7, 7, 7, 9, 3, 5];
const invalid5 = [5, 3, 8, 2, 0, 1, 9, 7, 7, 2, 8, 8, 3, 8, 5, 4];

// Can be either valid or invalid
const mystery1 = [3, 4, 4, 8, 0, 1, 9, 6, 8, 3, 0, 5, 4, 1, 4];
const mystery2 = [5, 4, 6, 6, 1, 0, 0, 8, 6, 1, 6, 2, 0, 2, 3, 9];
const mystery3 = [6, 0, 1, 1, 3, 7, 7, 0, 2, 0, 9, 6, 2, 6, 5, 6, 2, 0, 3];
const mystery4 = [4, 9, 2, 9, 8, 7, 7, 1, 6, 9, 2, 1, 7, 0, 9, 3];
const mystery5 = [4, 9, 1, 3, 5, 4, 0, 4, 6, 3, 0, 7, 2, 5, 2, 3];

// An array of all the arrays above
const batch = [valid1, valid2, valid3, valid4, valid5, invalid1, invalid2, invalid3, invalid4, invalid5, mystery1, mystery2, mystery3, mystery4, mystery5];


// Add your functions below:

const validateCred = credNumber => {
  const isEven = num => num % 2 === 0;
  
  let doubledCredNumber = [];
  let isCredNumLengthEven = isEven(credNumber.length);
  //console.log(`isEven: ${isCredNumLengthEven} - ${credNumber.length} - ` + credNumber);
  
  for (let n = credNumber.length - 1; n >= 0; n--) {
    if ((isCredNumLengthEven && !isEven(n)) || (!isCredNumLengthEven && isEven(n)))  {
      doubledCredNumber.unshift(credNumber[n]);    
    } else {
      let doubled = credNumber[n] * 2;
      if (doubled > 9) {
        doubled = doubled - 9;
      }
      doubledCredNumber.unshift(doubled);
    }
  }
  /*
  for (let n = credNumber.length - 1; n >= 0; n -= 2) {
    let doubled = credNumber[n - 1] * 2;
    if (doubled > 9) {
      doubled = doubled - 9;
    }
    doubledCredNumber.unshift(doubled, credNumber[n]);
  }
  */
  
  let sum = 0;
  for (let n = 0; n < doubledCredNumber.length; n++) {
   sum +=  doubledCredNumber[n];
  }
  
  let isValid = (sum % 10 === 0);
  //console.log(`isValid: ${isValid} - ${doubledCredNumber}`);
  
  return isValid;
}


const findInvalidCards = cardsList => {
  let invalidCardList = [];
  
  cardsList.forEach(card => {
    if (!validateCred(card)) {
      invalidCardList.push(card);
    }
  });
  
  //console.log(invalidCardList);
  return invalidCardList;
}


const idInvalidCardCompanies = listOfInvalidCards => {
  let listOfInvalidCardCompanies = [];
  
  /*
  let numTotalCards = listOfInvalidCards.length;
  let numCard = 1;
  console.log(listOfInvalidCards);
  */
  
  listOfInvalidCards.forEach(card => {
    switch (card[0]) {
      case 3:
        if (listOfInvalidCardCompanies.indexOf('Amex (American Express)') < 0) {
          listOfInvalidCardCompanies.push('Amex (American Express)');          
        }
        //console.log(`${numCard++}/${numTotalCards}: Amex ${card}`);
        break;
      case 4:
        if (listOfInvalidCardCompanies.indexOf('Visa') < 0) {
          listOfInvalidCardCompanies.push('Visa');
        }
        //console.log(`${numCard++}/${numTotalCards}: Visa ${card}`);
        break;
      case 5:
        if (listOfInvalidCardCompanies.indexOf('Mastercard') < 0) {
          listOfInvalidCardCompanies.push('Mastercard');
        }
        //console.log(`${numCard++}/${numTotalCards}: Mastercard  ${card}`);
        break;
      case 6:
        if (listOfInvalidCardCompanies.indexOf('Discover') < 0) {
          listOfInvalidCardCompanies.push('Discover');
        }
        //console.log(`${numCard++}/${numTotalCards}: Discover ${card}`);
        break;
      default:
        //console.log(`${numCard++}: Invalid Card Company`);
        console.log(`${card[0]}: Invalid Card Company id`);
    }
  });
  
  return listOfInvalidCardCompanies;
};

//console.log(idInvalidCardCompanies(findInvalidCards(batch)));


let batch2 = ['3420129485392492', '420132329485392492', '6201323294853922', 20394829302934];

const checkBatchCards = batchCards => {
  
  const stringToArray = cardString => {
    let cardArray = [];
      for (let n = 0; n < cardString.length; n++) {
        cardArray.push(Number(cardString[n]));
      }
    return cardArray;
  }

  let listOfPossibleValidCards = [];
  
  batchCards.forEach(card => {
    if ((card.length >= 14 && card.length <= 19) || Number.isInteger(card)) {
      switch (typeof card) {
        case 'string':
          listOfPossibleValidCards.push(stringToArray(card));
          break;
        case 'object':
          listOfPossibleValidCards.push(cardArray);
          break;
        case 'number':
          if (card > 10000000000000 && card < 9999999999999999999) {
            listOfPossibleValidCards.push(stringToArray(card.toString()));
          }
          break;
        default:
          console.log(`${card} - unable to determine format`);
          break;
      }
      console.log(listOfPossibleValidCards);
    } else if (card.length === 1) {
      
      
    } else {
      console.log(`Invalid Card Number: ${card}`);
    }
  });
}

checkBatchCards(batch2);
