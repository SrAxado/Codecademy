// Foursquare API Info
const clientId = 'LPGGJI3VXWSTJ0NZYZQECFMNDTOBWE34AHHU4KIK15MCDFBW';
const clientSecret = '0LMI3ZPTCDQWJNO2XKGSNLE5ORAOFRTE3FM3IMGE4Y1YZ10E';
const url = 'https://api.foursquare.com/v2/venues/search?near=';

// OpenWeather Info
const openWeatherKey = '570d657b59ee5085dc52920e56e91857';
const weatherUrl = 'https://api.openweathermap.org/data/2.5/weather';

// Page Elements
const $input = $('#city');
const $submit = $('#button');
const $destination = $('#destination');
const $container = $('.container');
const $venueDivs = [$("#venue0"), $("#venue1"), $("#venue2"), $("#venue3"), $("#venue4")];
const $weatherDiv = $("#weather1");
const weekDays = ['Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday'];

// Add AJAX functions herreturn jsonResponse;e:
const getForecast = async () => {
  const urlToFetch = `${weatherUrl}?q=${$input.val()}&appid=${openWeatherKey}`;
  try {
    const response = await fetch(urlToFetch);
    if (response.ok) {
      const jsonResponse = await response.json();
      //console.log(jsonResponse);
      return jsonResponse;
    }
    throw new Error('The weather request failed!');
  }
  catch(error) {
    console.log(error);
  }
}


const getVenues = async () => {
  const city = $input.val();
  const urlToFetch = `${url}${city}&limit=10&client_id=${clientId}&client_secret=${clientSecret}&v=20200320`;
  try {
    const response = await fetch(urlToFetch);
    if (response.ok) {
      const jsonResponse = await response.json();
      //console.log(jsonResponse);
      let venues = jsonResponse.response.venues.map(venue => venue);
      //console.log(venues);
      return venues;
    }
    throw new Error('The venues request failed!');
  }
  catch(error) {
    console.log(error);
  }
}


const imgVenueUrlFetch = async (venues) => {
  //console.log(venues);
  const arrayImgUrl = [];
  
  try {
    venues.forEach((venue, index) => {
      const venueImgrUrlToFetch = `https://api.foursquare.com/v2/venues/${venue.id}/photos?limit=1&group=venue&client_id=${clientId}&client_secret=${clientSecret}&v=20200324`;
      
      const response = fetch(venueImgrUrlToFetch);
      arrayImgUrl.push(response);
    });

    const resultArray = await Promise.all(arrayImgUrl);
    const resultPromiseArray = [];
    resultArray.forEach(response => resultPromiseArray.push(response.json()));
    const resultUrlArray = await Promise.all(resultPromiseArray);
    
    //console.log(resultUrlArray);
    resultUrlArray.forEach((resultUrlVenue, index) => {
      if (resultUrlVenue.meta.code != 429) {
        const responseUrlPhoto = resultUrlVenue.response.photos.items[0];
        venues[index].venueImgSrc = `${responseUrlPhoto.prefix}height100${responseUrlPhoto.suffix}`;
      } else {  // code #429: quota exceeded
        const venueIcon = venues[index]['categories'][0].icon;
        venues[index].venueImgSrc = `${venueIcon.prefix}bg_64${venueIcon.suffix}`;
      }
    });
    //console.log(venues);
    return venues;
    throw new Error('Unable to get the venue\'s image');
  }
  catch(error) {
    console.log(error);
  }
}


// Render functions
const renderVenues = (venues) => {
  let indexVenuesDisplayed = [];
  //console.log(venues);
  $venueDivs.forEach(($venue, index) => {
    // Add your code here:
    let randomIndex = 0;
    //console.log(`venue${index}`);
    do {
      randomIndex = Math.floor(Math.random() * (venues.length - 1));
    } while (indexVenuesDisplayed.indexOf(randomIndex) >= 0);

    indexVenuesDisplayed.unshift(randomIndex);

    const venue = venues[indexVenuesDisplayed[0]];
    //const venueIcon = venue['categories'][0].icon;
    //const venueImgSrc = `${venueIcon.prefix}bg_64${venueIcon.suffix}`;
    //console.log(venueImgSrc);
    /*
    const venueImgSrc = imgVenueUrlFetch(venue).then(imgUrl => {
      console.log(imgUrl);
      return imgUrl
    });
    */

    let venueContent = `<h2>${venue.name}</h2>
  <img class="venueimage" style="display:block; margin-left:auto; margin-right:auto" src="${venue.venueImgSrc}"/>
  <h3>Address:</h3>
  <p>${venue.location.address}</p>
  <p>${venue.location.city}</p>
  <p>${venue.location.country}</p>`;
    //let venueContent = createVenueHTML(venue.name, venue.location, venueImgSrc);
    $venue.append(venueContent);
  });
  //console.log(indexVenuesDisplayed);
  $destination.append(`<h2>${venues[0].location.city}</h2>`);
}


const renderForecast = (day) => {
  // Add your code here:
/*
	let weatherContent = `<h2>High: ${day.main.temp_max}</h2>
    <h2>Low: ${day.main.temp_min}</h2>
    <img src="https://openweathermap.org/img/wn/${day.weather[0].icon}@2x.png" />
    <h2>`;
    */
  let weatherContent = createWeatherHTML(day);
  $weatherDiv.append(weatherContent);
}

////////// -----------------------    ----------------------------------------  ////////////////
const promise1 = () => {
  const objecto = (name, data) => {
    return {
      name,
      data
    }
  }

  const arrayObjectos = [];
  for (let i = 0; i < 10; i++) {
    arrayObjectos.push(objecto(`objecto${i}`, `${i}: something`));
  }

  return new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve(arrayObjectos);
    }, Math.floor(Math.random() * 1000));
  });
  throw Error('Promise1 failed!');
}

const promise2 = (objecto) => {
  const index = +objecto.name[objecto.name.length - 1];  // +converts to number
  objecto.newData = index*1000 + (index === 9 ? 0 : index + 1)*100 + (index === 9 ? 0 : index + 1)*10 + index;
  //console.log(objecto);
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve(objecto);
    }, Math.floor(Math.random() * 1000));
  });
  throw Error('Promise2 failed!');
}


const worker1 = async () => {
  try {
    const firstValue = await promise1();
    return firstValue;
    throw Error('Worker1 found an error!');
  }
  catch(error) {
    console.log(error);
  }
}

const worker2 = async (arrayObjectos) => {
  const arrayPromises = [];
  try {
    arrayObjectos.forEach(objecto => {
      arrayPromises.push(promise2(objecto));
    });
    const resultArray = await Promise.all(arrayPromises);
    resultArray.forEach(objecto => {
      if (objecto.newData.toString()[0] < 9) {
        objecto.newData +=1001;
      } else {
        objecto.newData = 0000;
      }
    })
    //console.log(resultArray);
    //const response = await promise2(objecto);
    //if (response.ok) {
      //response.newData += 1001;
      //console.log(response);
      return resultArray;
    //}
    throw Error('Worker2 found an error!');
  }
  catch(error) {
    console.log(error);
  }
}

const buyer = (objecto) => {
  console.log(`Buyer:`);
  console.log(objecto);
}

//////////// ---------------------------------    ---------------------------------  ////////////

const executeSearch = () => {
  $venueDivs.forEach(venue => venue.empty());
  $weatherDiv.empty();
  $destination.empty();
  $container.css("visibility", "visible");
  //renderVenues(getVenues());
  getVenues().then(venues => imgVenueUrlFetch(venues)).then(venues => renderVenues(venues));
  getForecast().then(day => renderForecast(day)); 
  //worker1().then(value => worker2(value)).then(value => buyer(value));  // test workers chained promises
  return false;
}

$submit.click(executeSearch)