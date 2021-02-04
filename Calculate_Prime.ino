int start_number = 1;
int end_number = 100000;
unsigned long start_time;
unsigned long end_time;
unsigned long final_time;

int primes[100000]; // 16383 max number for arduino 
int noPrimes = 0;

bool found_prime = true;

void setup() {
  Serial.begin(9600);
  start_time = millis();
  for (int candidate_number = 1; candidate_number < end_number; candidate_number++) {
    found_prime = true;
    for (int div_number = 2; div_number < candidate_number; div_number++) {
      if (candidate_number % div_number == 0) {
        found_prime = false;
        break;
      }
    }
    if (found_prime == true) {
      primes[candidate_number-1] = candidate_number;
      noPrimes++;
    }
  }
  end_time = millis();
  final_time = (end_time - start_time);
  Serial.println("Find all primes up to: " + String(end_number));
  Serial.println("Time elasped: " + String(final_time) + " milliseconds ");
  Serial.println("Number of primes found " + String(noPrimes));
}

void loop() {
  
}
