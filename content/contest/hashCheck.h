/**
 * Author: Pedro Mesquita
 * Date: 2025-09-18
 * License: CC0
 * Source: me
 * Description: Use this for checking the {\tt hash.sh}.
 * Status: tested on https://codeforces.com/gym/106073/problem/F
 */
#pragma once

#include "../number-theory/ModPow.h"

// Computes modular inverse. Assumes mod is a prime.
ll modinv(ll n) {
	return modpow(n, mod - 2);
}
