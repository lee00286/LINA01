/************************************************************************
 * Phonetics Common Feature Finder - the English Consonants and Vowels
 * (c) Yena Lee, Jun. 2020
 *  - No part of this code may be reproduced without written authorization
 *
 *
 * This code searches for the common feature between consonants or vowels.
 * A number is assigned for each consonant and vowel for easier input.
 * The code will ask three questions to answer. Proper error-checking
 * is not provided, so please read and type-in the input carefully.
 *
 *
 * Chart of assigned numbers:
 * || =============================================== ||
 * ||     CONSONANTS      ||||         VOWELS         ||
 * || =============================================== ||
 * || 1: p                |||| 1: i                   ||
 * || 2: b                |||| 2: ɪ                   ||
 * || 3: m                |||| 3: u                   ||
 * || 4: f                |||| 4: ʊ                   ||
 * || 5: v                |||| 5: e/ej                ||
 * || 6: θ                |||| 6: ɛ                   ||
 * || 7: ð                |||| 7: ə                   ||
 * || 8: t                |||| 8: ʌ                   ||
 * || 9: d                |||| 9: o/ow                ||
 * || 10: n               |||| 10: ɔj                 ||
 * || 11: s               |||| 11: ɔ                  ||
 * || 12: z               |||| 12: æ                  ||
 * || 13: l               |||| 13: aj                 ||
 * || 14: r               |||| 14: aw                 ||
 * || 15: ʃ               |||| 15: ɑ                  ||
 * || 16: ʒ               ||||                        ||
 * || 17: ʧ               ||||                        ||
 * || 18: ʤ               ||||                        ||
 * || 19: j               ||||                        ||
 * || 20: k               ||||                        ||
 * || 21: g               ||||                        ||
 * || 22: ŋ               ||||                        ||
 * || 23: w               ||||                        ||
 * || 24: ʔ               ||||                        ||
 * || 25: h               ||||                        ||
 * || =============================================== ||
 *
 *
 * Common features of Consonants:
 *  - Place of Articulation (Labial, Dental, Alveolar, Alveopalatal, Palatal, Velar, Glottal)
 *  - Manner of Articulation (Stop, Nasal Stop, Fricative, Affricate, Liquid, Glide)
 *  - Voicing (Voiced, Voiceless)
 *
 *
 * Common features of Vowels:
 *  - Height of the Tongue (High, Mid, Low)
 *  - Backness of the Tongue (Front, Central, Back)
 *  - Tenseness of the Vocal Tract (Tensed, Laxed)
 *  - Roundedness of the Lips (Rounded, Unrounded)
 *  - Simple Vowels/Diphthong (Simple Vowel, Major Diphthong, Minor Diphthong)
 *
 *
 * Notes:
 *  - This code is only for the English consonants and vowels
 *  - Some features are excluded
 *    - e.g. "Lateral Liquid" and "Retroflex Liquid" are combined as "Liquid"
 *  - Place of articulation for the consonant w is set as "Labial", instead of "Bilabial"
 *  - Finding a common feature between consonants and vowels is not supported in this code
 *
 *
 * How to compile and run the code:
 *  $> gcc commonFeatureFinder.c -o commonFeature
 *  $> ./commonFeature (on Mac)
 *  $> .\commonFeature.exe (on Windows)
 *
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//===================================================================//
//==================== Consonant Helper Function ====================//
//===================================================================//
void conPlaceArticulation(int intArray[], int num) {
  char place[20];
  char subPlace[20] = "";
  char previousPlace[20] = "";
  char previousSubPlace[20] = "";
  int i = 0;

  while (i < num) {
    // printf("i = %d, intArray[i] = %d\n", i, intArray[i]);
    if (intArray[i] == 1 || intArray[i] == 2 || intArray[i] == 3) {
      strcpy(place, "Labial");
      strcpy(subPlace, "Bilabial");
    }
    else if (intArray[i] == 4 || intArray[i] == 5) {
      strcpy(place, "Labial");
      strcpy(subPlace, "Labiodental");
    }
    else if (intArray[i] == 6 || intArray[i] == 7) {
      strcpy(place, "Dental");
      strcpy(subPlace, "");
    }
    else if (intArray[i] == 8 || intArray[i] == 9 ||
             intArray[i] == 10 || intArray[i] == 11 ||
             intArray[i] == 12 || intArray[i] == 13 || intArray[i] == 14) {
      strcpy(place, "Alveolar");
      strcpy(subPlace, "");
    }
    else if (intArray[i] == 15 || intArray[i] == 16 ||
             intArray[i] == 17 || intArray[i] == 18) {
      strcpy(place, "Alveopalatal");
      strcpy(subPlace, "");
    }
    else if (intArray[i] == 19) {
      strcpy(place, "Palatal");
      strcpy(subPlace, "");
    }
    else if (intArray[i] == 20 || intArray[i] == 21 || intArray[i] == 22) {
      strcpy(place, "Velar");
      strcpy(subPlace, "");
    }
    else if (intArray[i] == 23) {
      strcpy(place, "Labial");
      strcpy(subPlace, "Velar");
    }
    else if (intArray[i] == 24 || intArray[i] == 25) {
      strcpy(place, "Glottal");
      strcpy(subPlace, "");
    }
    // Out of range
    else {
      return ;
    }

    // Compare place of consonants
    if (i == 0) {
      strcpy(previousPlace, place);
      strcpy(previousSubPlace, subPlace);
    }
    else {
      // place and previousPlace are same
      if (strcmp(place, previousPlace) == 0) {
        strcpy(previousPlace, place);
        strcpy(previousSubPlace, "");
      }
      else if (strcmp(previousSubPlace, "") != 0 &&
               strcmp(subPlace, "") != 0) {
        // subPlace and previousSubPlace are same
        if (strcmp(subPlace, previousSubPlace) == 0) {
          strcpy(previousPlace, subPlace);
          strcpy(previousSubPlace, "");
        }
        else {
          return ;
        }
      }
      else if (strcmp(previousSubPlace, "") != 0) {
        // place and previousSubPlace are same
        if (strcmp(place, previousSubPlace) == 0) {
          strcpy(previousPlace, place);
          strcpy(previousSubPlace, "");
        }
        else {
          return ;
        }
      }
      else if (strcmp(subPlace, "") != 0) {
        // subPlace and previousPlace are same
        if (strcmp(subPlace, previousPlace) == 0) {
          strcpy(previousPlace, subPlace);
          strcpy(previousSubPlace, "");
        }
        else {
          return ;
        }
      }
      // Place of Articulation doesn't match
      else {
        return ;
      }
    }

    i++;
  }

  printf("The common place of articulation is: %s\n", previousPlace);
  return ;
}

void conMannerArticulation(int intArray[], int num) {
  char manner[20];
  char subManner[20] = "";
  char previousManner[20] = "";
  char previousSubManner[20] = "";
  int i = 0;

  while (i < num) {
    if (intArray[i] == 1 || intArray[i] == 2 ||
        intArray[i] == 8 || intArray[i] == 9 ||
        intArray[i] == 20 || intArray[i] == 21 || intArray[i] == 24) {
      strcpy(manner, "Stop");
      strcpy(subManner, "");
    }
    else if (intArray[i] == 3 || intArray[i] == 10 || intArray[i] == 22) {
      strcpy(manner, "Nasal");
      strcpy(subManner, "Stop");
    }
    else if (intArray[i] == 4 || intArray[i] == 5 || intArray[i] == 6 ||
             intArray[i] == 7 || intArray[i] == 11 || intArray[i] == 12 ||
             intArray[i] == 15 || intArray[i] == 16 || intArray[i] == 25) {
      strcpy(manner, "Fricative");
      strcpy(subManner, "");
    }
    else if (intArray[i] == 17 || intArray[i] == 18) {
      strcpy(manner, "Affricate");
      strcpy(subManner, "");
    }
    else if (intArray[i] == 13 || intArray[i] == 14) {
      strcpy(manner, "Liquid");
      strcpy(subManner, "");
    }
    else if (intArray[i] == 19 || intArray[i] == 23) {
      strcpy(manner, "Glide");
      strcpy(subManner, "");
    }
    // Out of range
    else {
      return ;
    }

    // Compare manner of consonants
    if (i == 0) {
      strcpy(previousManner, manner);
      strcpy(previousSubManner, subManner);
    }
    else {
      // Manner and previousManner are same
      if (strcmp(manner, previousManner) == 0) {
        strcpy(previousManner, manner);
        strcpy(previousSubManner, "");
      }
      else if (strcmp(previousSubManner, "") != 0 &&
               strcmp(subManner, "") != 0) {
        // subManner and previousSubManner are same
        if (strcmp(subManner, previousSubManner) == 0) {
          strcpy(previousManner, subManner);
          strcpy(previousSubManner, "");
        }
        else {
          return ;
        }
      }
      else if (strcmp(previousSubManner, "") != 0) {
        // Manner and previousSubManner are same
        if (strcmp(manner, previousSubManner) == 0) {
          strcpy(previousManner, manner);
          strcpy(previousSubManner, "");
        }
        else {
          return ;
        }
      }
      else if (strcmp(subManner, "") != 0) {
        // subManner and previousManner are same
        if (strcmp(subManner, previousManner) == 0) {
          strcpy(previousManner, subManner);
          strcpy(previousSubManner, "");
        }
        else {
          return ;
        }
      }
      // Manner of Articulation doesn't match
      else {
        return ;
      }
    }

    i++;
  }

  printf("The common manner of articulation is: %s\n", previousManner);
  return ;
}

void conVoicing(int intArray[], int num) {
  char voice[20];
  char previousVoice[20] = "";
  int i = 0;

  while (i < num) {
    if (intArray[i] == 1 || intArray[i] == 4 || intArray[i] == 6 ||
        intArray[i] == 8 || intArray[i] == 11 || intArray[i] == 15 ||
        intArray[i] == 17 || intArray[i] == 20 || intArray[i] == 24 ||
        intArray[i] == 25) {
      strcpy(voice, "Voiceless");
    }
    else if (intArray[i] == 2 || intArray[i] == 3 || intArray[i] == 5 ||
             intArray[i] == 7 || intArray[i] == 9 || intArray[i] == 10 ||
             intArray[i] == 12 || intArray[i] == 13 || intArray[i] == 14 ||
             intArray[i] == 16 || intArray[i] == 18 || intArray[i] == 19 ||
             intArray[i] == 21 || intArray[i] == 22 || intArray[i] == 23) {
      strcpy(voice, "Voiced");
    }
    // Out of range
    else {
      return ;
    }

    // Compare voicing of consonants
    if (i == 0) {
      strcpy(previousVoice, voice);
    }
    else {
      // voice and previousVoice are same
      if (strcmp(voice, previousVoice) == 0) {
        strcpy(previousVoice, voice);
      }
      // Voicing doesn't match
      else {
        return ;
      }
    }

    i++;
  }

  printf("The common voicing is: %s\n", previousVoice);
  return ;
}

//===================================================================//
//====================== Vowel Helper Function ======================//
//===================================================================//
void vowHeight(int intArray[], int num) {
  char height[20];
  char previousHeight[20] = "";
  int i = 0;

  while (i < num) {
    if (intArray[i] == 1 || intArray[i] == 2 ||
        intArray[i] == 3 || intArray[i] == 4) {
      strcpy(height, "High");
    }
    else if (intArray[i] == 5 || intArray[i] == 6 ||
             intArray[i] == 7 || intArray[i] == 8 ||
             intArray[i] == 9 || intArray[i] == 10 || intArray[i] == 11) {
      strcpy(height, "Mid");
    }
    else if (intArray[i] == 12 || intArray[i] == 13 ||
             intArray[i] == 14 || intArray[i] == 15) {
      strcpy(height, "Low");
    }
    // Out of range
    else {
      return ;
    }

    // Compare height of vowels
    if (i == 0) {
      strcpy(previousHeight, height);
    }
    else {
      // height and previousHeight are same
      if (strcmp(height, previousHeight) == 0) {
        strcpy(previousHeight, height);
      }
      // Height doesn't match
      else {
        return ;
      }
    }

    i++;
  }

  printf("The common height of the tongue is: %s\n", previousHeight);
  return ;
}

void vowBackness(int intArray[], int num) {
  char backness[20];
  char previousBackness[20] = "";
  int i = 0;

  while (i < num) {
    if (intArray[i] == 1 || intArray[i] == 2 ||
        intArray[i] == 5 || intArray[i] == 6 || intArray[i] == 12) {
      strcpy(backness, "Front");
    }
    else if (intArray[i] == 7 || intArray[i] == 8 ||
             intArray[i] == 13 || intArray[i] == 14) {
      strcpy(backness, "Central");
    }
    else if (intArray[i] == 3 || intArray[i] == 4 || intArray[i] == 9 ||
             intArray[i] == 10 || intArray[i] == 11 || intArray[i] == 15) {
      strcpy(backness, "Back");
    }
    // Out of range
    else {
      return ;
    }

    // Compare backness of vowels
    if (i == 0) {
      strcpy(previousBackness, backness);
    }
    else {
      // backness and previousBackness are same
      if (strcmp(backness, previousBackness) == 0) {
        strcpy(previousBackness, backness);
      }
      // Backness doesn't match
      else {
        return ;
      }
    }

    i++;
  }

  printf("The common backness of the tongue is: %s\n", previousBackness);
  return ;
}

void vowTenseness(int intArray[], int num) {
  char tenseness[20];
  char previousTenseness[20] = "";
  int i = 0;

  while (i < num) {
    if (intArray[i] == 1 || intArray[i] == 3 || intArray[i] == 5 ||
        intArray[i] == 9 || intArray[i] == 10 || intArray[i] == 13 ||
        intArray[i] == 14 || intArray[i] == 15) {
      strcpy(tenseness, "Tensed");
    }
    else if (intArray[i] == 2 || intArray[i] == 4 ||
             intArray[i] == 6 || intArray[i] == 7 ||
             intArray[i] == 8 || intArray[i] == 11 || intArray[i] == 12) {
      strcpy(tenseness, "Laxed");
    }
    // Out of range
    else {
      return ;
    }

    // Compare tenseness of vowels
    if (i == 0) {
      strcpy(previousTenseness, tenseness);
    }
    else {
      // tenseness and previousTenseness are same
      if (strcmp(tenseness, previousTenseness) == 0) {
        strcpy(previousTenseness, tenseness);
      }
      // Tenseness doesn't match
      else {
        return ;
      }
    }

    i++;
  }

  printf("The common tenseness of the vocal tract is: %s\n", previousTenseness);
  return ;
}

void vowRoundedness(int intArray[], int num) {
  char roundedness[20];
  char previousRoundedness[20] = "";
  int i = 0;

  while (i < num) {
    if (intArray[i] == 3 || intArray[i] == 4 ||
        intArray[i] == 9 || intArray[i] == 10 || intArray[i] == 11) {
      strcpy(roundedness, "Rounded");
    }
    else if (intArray[i] == 1 || intArray[i] == 2 || intArray[i] == 5 ||
             intArray[i] == 6 || intArray[i] == 7 || intArray[i] == 8 ||
             intArray[i] == 12 || intArray[i] == 13 || intArray[i] == 14 ||
             intArray[i] == 15) {
      strcpy(roundedness, "Unrounded");
    }
    // Out of range
    else {
      return ;
    }

    // Compare roundedness of vowels
    if (i == 0) {
      strcpy(previousRoundedness, roundedness);
    }
    else {
      // roundedness and previousRoundedness are same
      if (strcmp(roundedness, previousRoundedness) == 0) {
        strcpy(previousRoundedness, roundedness);
      }
      // Roundedness doesn't match
      else {
        return ;
      }
    }

    i++;
  }

  printf("The common roundedness of the lips is: %s\n", previousRoundedness);
  return ;
}

void vowDiphthong(int intArray[], int num) {
  char diphthong[20];
  char subDiphthong[20] = "";
  char previousDiphthong[20] = "";
  char previousSubDiphthong[20] = "";
  int i = 0;

  while (i < num) {
    if (intArray[i] == 1 || intArray[i] == 2 || intArray[i] == 3 ||
        intArray[i] == 4 || intArray[i] == 6 || intArray[i] == 7 ||
        intArray[i] == 8 || intArray[i] == 11 || intArray[i] == 12 ||
        intArray[i] == 15) {
      strcpy(diphthong, "Simple Vowel");
      strcpy(subDiphthong, "");
    }
    else if (intArray[i] == 10 || intArray[i] == 13 || intArray[i] == 14) {
      strcpy(diphthong, "Diphthong");
      strcpy(subDiphthong, "Major Diphthong");
    }
    else if (intArray[i] == 5 || intArray[i] == 9) {
      strcpy(diphthong, "Diphthong");
      strcpy(subDiphthong, "Minor Diphthong");
    }
    // Out of range
    else {
      return ;
    }

    // Compare diphthong of vowels
    if (i == 0) {
      strcpy(previousDiphthong, diphthong);
      strcpy(previousSubDiphthong, subDiphthong);
    }
    else {
      // diphthong and previousDiphthong are same
      if (strcmp(diphthong, previousDiphthong) == 0) {
        strcpy(previousDiphthong, diphthong);
        strcpy(previousSubDiphthong, "");
      }
      else if (strcmp(previousSubDiphthong, "") != 0 &&
               strcmp(subDiphthong, "") != 0) {
        // subDiphthong and previousSubDiphthong are same
        if (strcmp(subDiphthong, previousSubDiphthong) == 0) {
          strcpy(previousDiphthong, subDiphthong);
          strcpy(previousSubDiphthong, "");
        }
        else {
          return ;
        }
      }
      else if (strcmp(previousSubDiphthong, "") != 0) {
        // diphthong and previousSubDiphthong are same
        if (strcmp(diphthong, previousSubDiphthong) == 0) {
          strcpy(previousDiphthong, diphthong);
          strcpy(previousSubDiphthong, "");
        }
        else {
          return ;
        }
      }
      else if (strcmp(subDiphthong, "") != 0) {
        // subDiphthong and previousDiphthong are same
        if (strcmp(subDiphthong, previousDiphthong) == 0) {
          strcpy(previousDiphthong, subDiphthong);
          strcpy(previousSubDiphthong, "");
        }
        else {
          return ;
        }
      }
      // Simple/complex vowel doesn't match
      else {
        return ;
      }
    }

    i++;
  }

  printf("The common simple/complex vowel is: %s\n", previousDiphthong);
  return ;
}

//==================================================================//
//============================== Main ==============================//
//===================================================================//
int main() {
  int num;
  int intArray[7];
  int consonantVowel;

  // Number of consonants/vowels to compare
  printf("How many consonants/vowels?\n");
  scanf("%d", &num);

  // Create an array of consonants/vowels
  for (int i = 0; i < num; i++) {
    printf("Enter intArray[%d].\n", i);
    scanf("%d", &intArray[i]);
  }

  printf("Vowel or consonant? Enter 0 if consonant, 1 if vowel.\n");
  scanf("%d", &consonantVowel);

  // If input is consonant
  if (consonantVowel == 0) {
    conPlaceArticulation(intArray, num);
    conMannerArticulation(intArray, num);
    conVoicing(intArray, num);
  }
  // If input is vowel
  else if (consonantVowel == 1) {
    vowHeight(intArray, num);
    vowBackness(intArray, num);
    vowTenseness(intArray, num);
    vowRoundedness(intArray, num);
    vowDiphthong(intArray, num);
  }
  // Invalid input
  else {
    printf("Invalid Input\n");
    return 0;
  }

  printf("========END========\n");

  return 0;
}
