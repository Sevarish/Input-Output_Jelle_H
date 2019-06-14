int maxDistFreq = 50;
int maxDistVol = 30;
float frequencyMultiplier = 20;
float volumeMultiplier = 0.3;
enum notes{E3 = 165, F3 = 175, F3S = 185, G3 = 196, G3S = 208, Aa3 = 220, A3S = 233, B3 = 247, C4 = 262, C4S = 277, D4 = 294, D4S = 311, E4 = 330, F4 = 349, F4S = 370, G4 = 392, G4S = 415, Aa4 = 440, A4S = 466, B4 = 494, C5 = 523};

void MakeSound(float frequencyDistance, float volDistance){
  float frequency, volume;
  if (frequencyDistance < maxDistFreq) {
  frequency = frequencyDistance * frequencyMultiplier;
  }
  if (volDistance < maxDistVol) {
  volume = volDistance * volumeMultiplier;
  }
  Serial.print("Vol = "); Serial.print(volume); Serial.print("    Freq = "); Serial.print(frequency); Serial.print("     Note Correction: "); Serial.println(NoteCorrection(frequency)); 
  
  if (noteCorrection) {
    toneAC(NoteCorrection(frequency), volume);
  }
  else {
  toneAC(frequency, volume);
  }
}

float NoteCorrection(float freq) {
  float mapFreq = freq * 10; 
  if (mapFreq <= 400) {
   return notes(E3); //E3 Note  
  }
  else if (mapFreq > 400 && mapFreq <= 800) {
  return notes(F3); //F3 Note
  }
  else if (mapFreq > 800 && mapFreq <= 1200) {
  return notes(F3S); //F3# Note
  }
  else if (mapFreq > 1200 && mapFreq <= 1600) {
  return notes(G3);; //G3 Note
  }
  else if (mapFreq > 1600 && mapFreq <= 2000) {
  return notes(G3S); //G3# Note
  }
  else if (mapFreq > 2000 && mapFreq <= 2400) {
  return notes(Aa3); //A3 Note
  }
  else if (mapFreq > 2400 && mapFreq <= 2800) {
  return notes(A3S); //A3# Note
  }
  else if (mapFreq > 3200 && mapFreq <= 3600) {
  return notes(B3); //B3 Note
  }
  else if (mapFreq > 3600 && mapFreq <= 4000) {
  return notes(C4); //C4 Note
  }
  else if (mapFreq > 4400 && mapFreq <= 4800) {
  return notes(C4S); //C4# Note
  }
  else if (mapFreq > 5200 && mapFreq <= 5600) {
  return notes(D4); //D4 Note
  }
  else if (mapFreq > 6000 && mapFreq <= 6400) {
  return notes(D4S); //D4# Note
  }
  else if (mapFreq > 6400 && mapFreq <= 6800) {
  return notes(E4); //E4 Note
  }
  else if (mapFreq > 6800 && mapFreq <=  7200) {
  return notes(F4); //F4 Note
  }
  else if (mapFreq > 7200 && mapFreq <=  7600) {
  return notes(F4S); //F4# Note
  }
  else if (mapFreq > 7600 && mapFreq <=  8000) {
  return notes(G4); //G4 Note
  }
  else if (mapFreq > 8000 && mapFreq <=  8400) {
  return notes(G4S); //G4# Note
  }
  else if (mapFreq > 8400 && mapFreq <=  8800) {
  return notes(Aa4); //A4 Note
  }
  else if (mapFreq > 8800 && mapFreq <=  9200) {
  return notes(A4S); //A4# Note
  }
  else if (mapFreq > 9200 && mapFreq <=  9600) {
  return notes(B4); //B4 Note
  }
  else if (mapFreq > 9600){
  return notes(C5); //C5 Note
  }
  

  
}
