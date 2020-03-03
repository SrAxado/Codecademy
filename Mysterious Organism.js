// Returns a random DNA base
const returnRandBase = () => {
  const dnaBases = ['A', 'T', 'C', 'G']
  return dnaBases[Math.floor(Math.random() * 4)] 
}

// Returns a random single stand of DNA containing 15 bases
const mockUpStrand = () => {
  const newStrand = []
  for (let i = 0; i < 15; i++) {
    newStrand.push(returnRandBase())
  }
  return newStrand
}


const pAequorFactory = (specimenNum, dna) => {
  return {
    specimenNum,  // keeping the factory function's specifications
    dna,
    mutate() {
      let mutationBase = returnRandBase();
      while (mutationBase === this.dna[0]) {
        mutationBase = returnRandBase();
      }        
      let mutatedDNA = this.dna;
      mutatedDNA[0] = mutationBase;
      
      return mutatedDNA;
    },
    compareDNA(pAequor) {
      let identicalBases = 0;
      for (let i = 0; i < this.dna.length; i++) {
        if (dna[i] === pAequor.dna[i]) {
          identicalBases++;
        }
      }
      console.log(`specimen #${this.specimenNum} and specimen #${pAequor.specimenNum} have ${Math.round(identicalBases*100/15)}% DNA in common`);
    },
    willLikelySurvive() {
      let likelynessToSurvive = 0;
      for (let base of this.dna) {
        if (base === 'C' || base === 'G'){
          likelynessToSurvive++;
        }
      }
      return (likelynessToSurvive/this.dna.length) >= 0.6;
    },
    complementStrand() {
      let complementStrand = this.dna;
      for (let i = 0; i < complementStrand.length; i++) {
        switch (complementStrand[i]) {
          case 'A':
            complementStrand[i] = 'T';
            break;
          case 'T':
            complementStrand[i] = 'A';
            break;
          case 'C':
            complementStrand[i] = 'G';
            break;
          case 'G':
            complementStrand[i] = 'C';
            break;
          default:
            console.log(`[${i}] Invalid Base`);
        }
      }
      return complementStrand;
    }
  }
}


//let organism1 = pAequorFactory(1, mockUpStrand());
//let organism2 = pAequorFactory(2, mockUpStrand());
//Task4
//console.log(`original DNA: ${organism.dna}\nmutated DNA: ${organism.mutate()}`);
//Task5
//organism1.compareDNA(organism2);
//Task6
//console.log(`specimen #${organism1.specimenNum} ${organism1.willLikelySurvive() ? 'is' : 'is not'} likely to survive`);
//console.log(`specimen #${organism2.specimenNum} ${organism2.willLikelySurvive() ? 'is' : 'is not'} likely to survive`);

/*
//Task7
const pAequorChosenGroup = [];

let num = 1;
while (pAequorChosenGroup.length < 30) {
  let pAequor = pAequorFactory(num, mockUpStrand());
  if (pAequor.willLikelySurvive()) {
    pAequorChosenGroup.push(pAequor);
  }
  num++;
}

console.log(pAequorChosenGroup);
*/

//Task9
let organism1 = pAequorFactory(1, mockUpStrand());
let organism2 = pAequorFactory(2, organism1.complementStrand());

organism1.compareDNA(organism2);
