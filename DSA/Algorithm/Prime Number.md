---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-27T09:02:00
tags:
  - Algorithm
  - Prime-Number
---

# Prime Number

- Generator
	- [X] [Sieve of Eratosthenes](#Sieve%20of%20Eratosthenes)
	- [ ] Sieve of Sundaram
	- [X] [Sieve of Atkin](#Sieve%20of%20Atkin)

- Checker
	- [X] [Naive Approach (Trial Division)](#1%20Naive%20Approach%20Trial%20Division)
	- [ ] [Sieve Methods](#2%20sieve%20methods%20for%20checking%20multiple%20numbers%20up%20to%20a%20limit)
		- [ ] [Sieve of Eratosthenes](#a%20sieve%20of%20eratosthenes)
		- [ ] [Sieve of Atkin](#b%20sieve%20of%20atkin%20more%20advanced)
	- [ ] [Probabilistic Primality Tests](#3%20probabilistic%20primality%20tests%20for%20very%20large%20numbers)
		- [ ] [Miller-Rabin Primality Test](#a%20miller%20rabin%20primality%20test)
	- [ ] [Deterministic Primality Tests](#4%20deterministic%20primality%20tests%20for%20very%20large%20numbers)
	- [ ] [AKS Primality Test](#a%20aks%20primality%20test)
## Generator

### Sieve of Eratosthenes:

To find primary numbers simply eliminate multiples of any primary numbers
you have already found, i.e.:

first eliminate any multiples of 2 ( 4, 6, 8, ... ),<br>then eliminate any multiples of 3 ( 6, 9, 12, ...),<br>then eliminate any multiples of 5 ( 10, 15, 20, ..) // 4 has already been eliminated and so on

![sieve of eratosthenes](sieve_of_eratosthenes.png)
- **Time Complexity:** $O(\log(\log n ))$.
```C++
inline std::vector<int> byEratosthenes(int limit) {
	
	if (limit < 2) return {};
	std::vector<bool> isPrime(limit + 1, true);
	isPrime[0] = isPrime[1] = false;
	
	int sqrtLimit = static_cast<int>(sqrt(limit));
		for (int i = 2; i <= sqrtLimit; ++i) {
			if (isPrime[i]) {
				for (int j = i * i; j <= limit; j += i) {
					isPrime[j] = false;	
			}
		}
	}
	
	std::vector<int> primes;
	primes.reserve(limit / 10); // Rough estimate for better performance
	for (int i = 2; i <= limit; ++i) {
		if (isPrime[i]) {
			primes.push_back(i);
		}
	}
	return primes;
}
```
### Sieve of Atkin
Sieve of Atkin speeds up (asymptotically) the process of generating prime numbers. However, it is more complicated than the others.
#### The filter or sieve in this algorithms works mainly 4 cases or layers:
- Case 1: If limit is greater than 2 or 3:
	* The algorithm treats 2, and 3 as special cases and just adds them to the set of primes to start with.
	- Let x and y be positive integers ranging from 1 up through √limit.

- Case 2: if 4x2+ y2 = n is odd and modulo-12 remainder is 1 or 5
	* If a number gives a remainder of one of {1, 13, 17, 29, 37, 41, 49, 53} when divided by 60, then it must give a remainder of either 1 or 5 when divided by 12 (Why? because 1 %12 = 1, 13 % 12 = 1, 17 % 12 = 1, 29 % 12 = 1, ..). Therefore, for this filter as well, we have to check if the number is 1 or 5 when taken modulo with 12.
	* Also, these numbers are prime if and only if the number of solutions to 4x2 + y2=n is odd and the number is square-free.
	* A square-free integer is one that is not divisible by any perfect square other than 1.

- Case 3: if 3x2+y2 = n is odd and modulo-6 remainder is 1
	* All numbers with modulo-60 remainder 7, 19, 31, or 43 have a modulo-6 remainder of 1.
	* These numbers are prime if and only if the number of solutions to 3x2 + y2 = n is odd and the number is square-free.

- Case 4: if 3x2-y2=n is odd and modulo-12 remainder is 11
	* All numbers with modulo-60 remainder 11, 23, 47, or 59 have a modulo-12 remainder of 11.	
	* These numbers are prime if and only if the number of solutions to 3x2 - y2 = n is odd and the number is square-free.

- Case 5: Filtering out all the residual primes which have not yet been found
	* Due to the filtering of the Sieve of Atkin algorithm, there might be some prime numbers who have been discarded or not found in the above cases.
	* So to find out those, select all non-primes within limit, and mark all their squares as non-primes.

At the end of all of the filters above, the positions in the Sieve with a true value will be the list of primes within limit.
- **Time Complexity:** $O(N / \log(\log N))$.
- **Space Complexity:** $O(N)$ bits (or $O(\sqrt(N))$ with segmentation).
```C++
inline std::vector<int> bySieveOfAtkin(int limit){
	if (limit < 2){
		return {}; // Return empty vector if limit is less than 2
	}
	
	// Initialize a boolean vector 'is_prime' with all values set to false.
	// The size is limit + 1 because we want to include 'limit' itself.
	std::vector<bool> is_prime(limit + 1, false);
	// 2 and 3 are prime, and are handled as special cases.
	if (limit >= 2){
		is_prime[2] = true;
	}
	if (limit >= 3){
		is_prime[3] = true;
	}
	  
	// Main part of the Sieve of Atkin:
	// Numbers n are prime if and only if one of the following is true:
	// 1. n = 4x^2 + y^2, n % 12 == 1 or n % 12 == 5
	// 2. n = 3x^2 + y^2, n % 12 == 7
	// 3. n = 3x^2 - y^2, x > y, n % 12 == 11
	// where x and y are positive integers.
	  
	int sqrt_limit = static_cast<int>(std::sqrt(limit)) + 1;
	  
	// Iterate through possible x and y values
	for (int x = 1; x < sqrt_limit; ++x){
		for (int y = 1; y < sqrt_limit; ++y){
			int n;
			  
			// Case 1: n = 4x^2 + y^2
			n = (4 * x * x) + (y * y);
			if (n <= limit && (n % 12 == 1 || n % 12 == 5)){
				is_prime[n] = !is_prime[n];
			}
			  
			// Case 2: n = 3x^2 + y^2
			n = (3 * x * x) + (y * y);
			if (n <= limit && (n % 12 == 7)){
				is_prime[n] = !is_prime[n];
			}
			  
			// Case 3: n = 3x^2 - y^2
			// Note: x must be greater than y for this case to avoid negative n or redundant calculations
			n = (3 * x * x) - (y * y);
			if (x > y && n <= limit && (n % 12 == 11)){
				is_prime[n] = !is_prime[n];
			}
		}
	}
	
	// Eliminate composites by sieving (removing multiples of squares of primes)
	// This step ensures that numbers that are multiples of prime squares
	// (e.g., 25, 49, etc.) are correctly marked as non-prime, as they
	// would have been flipped an even number of times by the quadratic forms.
	for (int r = 5; r * r <= limit; ++r){ // Only need to go up to sqrt(limit)
		if (is_prime[r])
		{ // If r is a prime found in the previous step
			// Mark all multiples of r*r as not prime
			for (int multiple = r * r; multiple <= limit; multiple += r * r)
			{
				is_prime[multiple] = false;
			}
		}
	}
	
	// Collect the prime numbers
	std::vector<int> primes;
	for (int i = 2; i <= limit; ++i)
	{
		if (is_prime[i])
		{
		primes.push_back(i);
		}
	}
	
	return primes;
}
```  
## Checker
Checking whether a given number is prime or not is a fundamental problem in number theory and computer science.
### 1. Naive Approach (Trial Division)
The most straightforward way is to try dividing the number by all integers from 2 up to its square root. If any of these divisions result in a remainder of 0, the number is not prime.

**Algorithm:**
1. If $n \le 1$, it's not prime.
2. If $n = 2$ or $n = 3$, it's prime.
3. If $n$ is divisible by 2 (i.e., $n \pmod 2 == 0$), it's not prime (unless $n=2$, which is handled in step 2).
4. Iterate from $i = 3$ up to $\sqrt{n}$ (inclusive), incrementing $i$ by 2 (to check only odd divisors).
5. If $n$ is divisible by $i$ (i.e., $n \pmod i == 0$), then $n$ is not prime.
6. If the loop completes without finding any divisors, $n$ is prime.

**Example (Python):**
```python
import math

def is_prime_naive(n):
	if n <= 1:
		return False
	if n == 2 or n == 3:
		return True
	if n % 2 == 0: # Check for even numbers
		return Fals
	
	# Only check odd divisors up to sqrt(n)
	i = 3
	while i * i <= n: # Same as i <= math.sqrt(n)
		if n % i == 0:
			return False
		i += 2
	return True

# Test cases
print(f"Is 7 prime? {is_prime_naive(7)}") # True
print(f"Is 10 prime? {is_prime_naive(10)}") # False
print(f"Is 2 prime? {is_prime_naive(2)}") # True
print(f"Is 1 prime? {is_prime_naive(1)}") # False
print(f"Is 0 prime? {is_prime_naive(0)}") # False
print(f"Is 97 prime? {is_prime_naive(97)}") # True
print(f"Is 99 prime? {is_prime_naive(99)}") # False
```
**Time Complexity:** $O(\sqrt{N})$ **Pros:** Simple to understand and implement. Efficient enough for small to moderately sized numbers.**Cons:** Can be slow for very large numbers.

### 2. Sieve Methods (for checking multiple numbers up to a limit)
If you need to check the primality of *many* numbers up to a certain limit (e.g., all numbers up to 1,000,000), using a sieve algorithm is far more efficient than checking each number individually.
#### a) Sieve of Eratosthenes
This algorithm efficiently finds all prime numbers up to a specified integer.

**Algorithm:**
1. Create a boolean list `is_prime` of size `limit + 1`, initialized to `True`.
2. Mark `0` and `1` as `False`.
3. Start with `p = 2`.
4. While $p^2 \le \text{limit}$: a. If `is_prime[p]` is `True`, then `p` is a prime number. Mark all multiples of `p` (starting from $p^2$) as `False` (e.g., $p^2$, $p^2+p$, $p^2+2p$, etc.). b. Increment `p` to the next number.
5. After the loop, all numbers `i` for which `is_prime[i]` is `True` are prime.

**Example (Python - how to use it for single number check after sieve):**
```python
def sieve_of_eratosthenes(limit):
	is_prime = [True] * (limit + 1)
	is_prime[0] = is_prime[1] = False
	
	for p in range(2, int(math.sqrt(limit)) + 1):
		if is_prime[p]:
			for multiple in range(p * p, limit + 1, p):
				is_prime[multiple] = False
	return is_prime

# To check if a single number 'num' is prime using the sieve:
MAX_LIMIT = 10**6 # Pre-calculate primes up to this limit
prime_lookup = sieve_of_eratosthenes(MAX_LIMIT)

def is_prime_sieve_lookup(num):
	if num <= MAX_LIMIT:
		return prime_lookup[num]
	else:
	# For numbers larger than MAX_LIMIT, fall back to trial division or a probabilistic test
	return is_prime_naive(num) # Or another method for larger numbers

# Test cases
print(f"Is 999983 prime? {is_prime_sieve_lookup(999983)}") # True (if MAX_LIMIT is large enough)
print(f"Is 1000000 prime? {is_prime_sieve_lookup(1000000)}") # False
print(f"Is 1000003 prime? {is_prime_sieve_lookup(1000003)}") # Requires naive if MAX_LIMIT < 1000003

```
**Time Complexity (for generating all primes up to N):** $O(N \log \log N)$ **Space Complexity:** $O(N)$ **Pros:** Extremely efficient for finding *all* primes up to a limit. Very fast lookup for primality of numbers within the pre-calculated range.

**Cons:** Requires significant memory for large limits. Not suitable if you only need to check one very large number.
#### b) Sieve of Atkin (more advanced)
As discussed in previous responses, it has a better asymptotic time complexity than Eratosthenes ($O(N / \log \log N)$), but is more complex to implement and often has higher constant factors, making it practically slower for many common use cases.
### 3. Probabilistic Primality Tests (for very large numbers)
For numbers that are too large for trial division or sieves (e.g., numbers with hundreds or thousands of digits), probabilistic primality tests are used. These tests don't *guarantee* primality but provide a very high probability that a number is prime.
#### a) Miller-Rabin Primality Test
This is the most widely used probabilistic test. It's based on Fermat's Little Theorem and properties of quadratic residues.

**Algorithm (Simplified Idea):**
1. Choose a random "base" `a`.
2. Perform a series of modular exponentiations and checks.
3. If the number fails any check, it's definitively composite.
4. If it passes all checks for a sufficient number of random bases, it's considered "probably prime" with a very low error probability.

**Key Idea:** If a number `n` is prime, then for any integer `a` such that `1 < a < n`, we have `a^(n-1) % n == 1`. The Miller-Rabin test adds more stringent conditions to rule out Carmichael numbers (composites that pass Fermat's Little Theorem).

**Example (Python - conceptual, usually part of a library):**
```python

import random

def miller_rabin_test(n, k=5):
	if n <= 1: return False
	if n == 2 or n == 3: return True
	if n % 2 == 0: return False
	
	# Write n-1 as 2^s * d where d is odd
	s = 0
	d = n - 1
	while d % 2 == 0:
		d //= 2
		s += 1
	
	# Witness loop (k is the number of rounds for accuracy)
	for _ in range(k):
		a = random.randint(2, n - 2)
		x = pow(a, d, n) # a^d % n
	
		if x == 1 or x == n - 1:
			continue
		
		for _ in range(s - 1):
			x = pow(x, 2, n) # x^2 % n
			if x == n - 1:
				break
			else: # If loop completed without x == n - 1
				return False # n is composite (a is a witness)
	return True # n is probably prime

# Test cases
print(f"Is 999983 prime (Miller-Rabin)? {miller_rabin_test(999983)}")
print(f"Is 1000000 prime (Miller-Rabin)? {miller_rabin_test(1000000)}")
print(f"Is 2^61 - 1 prime (Miller-Rabin)? {miller_rabin_test((2**61) - 1)}") # A Mersenne prime
print(f"Is 561 prime (Miller-Rabin)? {miller_rabin_test(561)}") # 561 is a Carmichael number (3*11*17), should be False

```

**Time Complexity:** $O(k \log^3 N)$ where `k` is the number of rounds (determines accuracy) and $\log N$ is the number of bits in $N$.
**Pros:** Can test very large numbers efficiently. With enough iterations, the probability of error is astronomically small (negligible for practical purposes).
**Cons:** Probabilistic (not 100% certain, though extremely reliable for practical purposes). More complex to implement.

### 4. Deterministic Primality Tests (for very large numbers)
For very large numbers where absolute certainty is required, there are deterministic primality tests.

#### a) AKS Primality Test
The AKS primality test (Agrawal-Kayal-Saxena) is a groundbreaking discovery (2002) because it's the first *deterministic* primality test that runs in polynomial time.

**Time Complexity:** $O(\log^{6} N)$ (original), improved to $O(\log^{10.5} N)$ for a simpler version or $O(\log^{7.5} N)$ with specific number theory conjectures.
**Pros:** Deterministic (always correct), polynomial time.
**Cons:** Extremely complex to implement and, despite its polynomial complexity, practically much slower than Miller-Rabin for numbers within typical computational limits. It's more of theoretical significance than practical use for most applications.

### Which Method to Choose?
* **For small numbers (up to a few millions):** The **Naive Trial Division** method is perfectly fine and easiest to implement.
* **For checking many numbers up to a limit (e.g., for competitive programming):** The **Sieve of Eratosthenes** is the way to go. Pre-calculate once, then O(1) lookup.
* **For large numbers (hundreds of digits):** Use the **Miller-Rabin Primality Test**. This is what cryptographic libraries use.
* **For extremely large numbers where absolute mathematical certainty is paramount (and performance is less critical):** The **AKS Primality Test** exists, but it's rarely implemented outside of research contexts.

Most programming languages have optimized libraries that include highly efficient primality tests. For example, in Python, you might use a library that leverages Miller-Rabin for large numbers.