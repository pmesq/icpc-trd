/**
 * Author: Oscar Burga
 * Date: 2021-02-13
 * License: CC BY-SA
 * Source: https://cp-algorithms.com/geometry/halfplane-intersection.html
 * Description:\\
\begin{minipage}{75mm}
Computes the intersection of $n$ half-planes.
Each half-plane is represented as the region to the left side of a vector $\vec{ab}$.
If the half-planes are already given sorted by angle,
the sort in the first line of hpi can be removed, making the time $O(n)$.
\end{minipage}
\begin{minipage}{15mm}
\includegraphics[width=\textwidth]{content/geometry/HalfPlaneIntersection}
\end{minipage}
 * Time: O(n \log n)
 * Status: tested on ICPC WF 2020 Domes
 */
#pragma once

#include "Point.h"

typedef long double dbl;
typedef Point<dbl> P;
const dbl eps = 1e-9;
struct HP {
	P p, pq;
	dbl ang;
	HP() {}
	HP(const P& a, const P& b): p(a), pq(b - a) {
		ang = atan2l(pq.y, pq.x);
	}
	bool out(const P& r) { return pq.cross(r - p) < -eps; }
	bool operator<(const HP& e) const { return ang < e.ang; }
	friend P inter(const HP& s, const HP& t) {
		dbl alpha = (t.p-s.p).cross(t.pq) / s.pq.cross(t.pq);
		return s.p + (s.pq * alpha);
	}
};
vector<P> hpi(vector<HP>& H) {
	sort(all(H)); // can be removed if HPs are already sorted
	deque<HP> dq;
	int len = 0;
	rep(i, 0, sz(H)) {
		while (len > 1 && H[i].out(inter(dq[len-1], dq[len-2])))
			dq.pop_back(), --len;
		while (len > 1 && H[i].out(inter(dq[0], dq[1])))
			dq.pop_front(), --len;
		if (len > 0 && fabsl(H[i].pq.cross(dq[len-1].pq)) < eps) {
			if (H[i].pq.dot(dq[len-1].pq) < 0.0) return vector<P>();
			if (H[i].out(dq[len-1].p)) dq.pop_back(), --len;
			else continue;
		}
		dq.push_back(H[i]), ++len;
	}
	while (len > 2 && dq[0].out(inter(dq[len-1], dq[len-2])))
		dq.pop_back(), --len;
	while (len > 2 && dq[len-1].out(inter(dq[0], dq[1])))
		dq.pop_front(), --len;
	if (len < 3) return vector<P>();
	vector<P> ret(len);
	rep(i, 0, len-1) ret[i] = inter(dq[i], dq[i+1]);
	ret.back() = inter(dq[len-1], dq[0]);
	return ret;
}
