const int max = $1;
int is_prime[max + 10];
void findPrimes(int max) {
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= max; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= max; j += i)
        is_prime[j] = false;
    }
  }
}