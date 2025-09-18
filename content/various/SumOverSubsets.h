/**
 * Author: Pedro Mesquita
 * Date: 2025-09-18
 * License: CC0
 * Source: https://usaco.guide/plat/dp-sos
 * Description: Given an array $a$ with $2^n$ elements,
 * computes $f(x)$ for all $i = 0, 1, 2, ..., 2^n - 1$.
 * Here, $f(x)$ represents the sum of values in array $a$ for all subsets $i$ of $x$.
 * That is, $f(x) = \sum_{i \subseteq x} a[i]$.
 * Time: O(2^n n)
 * Status: tested on https://codeforces.com/gym/106073/problem/D
 */
#pragma once

vector<ll> sos(vector<ll> a) {
	int n = __lg(sz(a));
	rep(i, 0, n) rep(x, 0, 1 << n) {
		if (x & (1 << i)) a[x] += a[x ^ (1 << i)];
	}
	return a;
}
