/**
 * Author: Yury Semenov
 * Date: 2020-10-04
 * License: CC BY-SA
 * Source: https://cp-algorithms.com/geometry/minkowski.html
 * Description: Computes the Minkowski sum $C$ of two convex polygons $A$ and $B$.
 * It is proven that $C$ is a convex polygon with at most $|A| + |B|$ vertices.
 * Vertices of polygons $A$ and $B$ must be given in CCW order,
 * and vertices of $C$ will be returned in CCW order, similarly.
 * Time: O(|A| + |B|)
 * Status: tested on https://codeforces.com/contest/87/problem/E
 */
#pragma once

#include "Point.h"

typedef Point<ll> P;
void reorder_polygon(vector<P>& a) {
	int p = 0;
	rep(i, 1, sz(a)) {
		if (tie(a[i].y, a[i].x) < tie(a[p].y, a[p].x)) p = i;
	}
	rotate(a.begin(), a.begin() + p, a.end());
}
vector<P> minkowski(vector<P> a, vector<P> b) {
	reorder_polygon(a);
	reorder_polygon(b);
	a.push_back(a[0]); a.push_back(a[1]);
	b.push_back(b[0]); b.push_back(b[1]);
	vector<P> c;
	int i = 0, j = 0;
	while (i < sz(a) - 2 || j < sz(b) - 2){
		c.push_back(a[i] + b[j]);
		auto cross = (a[i + 1] - a[i]).cross(b[j + 1] - b[j]);
		if (cross >= 0 && i < sz(a) - 2) ++i;
		if (cross <= 0 && j < sz(b) - 2) ++j;
	}
	return c;
}
