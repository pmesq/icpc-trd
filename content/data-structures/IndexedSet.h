/**
 * Author: Pedro Mesquita
 * Date: 2025-09-18
 * License: CC0
 * Source: kactl, Competitive Programmer’s Handbook
 * Description: Similar to OrderStatisticTree,
 * but uses a different library which may be more portable.
 */
#pragma once

#include <ext/pb_ds/assoc_container.hpp> /** keep-include */
using namespace __gnu_pbds;

template<class T>
using IndexedSet = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;
