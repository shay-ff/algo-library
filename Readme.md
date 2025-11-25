
# Algo Library — Short Templates for Competitive Programming

This repository collects small, ready-to-use C++ templates for common contest algorithms and data structures.
They are designed to be clear, short, and easy to integrate into your solutions.

Why use this repo
- Quick access to concise, battle-tested snippets (graphs, strings, DP, trees, number theory, geometry, etc.).
- Most templates include a minimal `main()` so you can compile and test them immediately.
- Several string templates expose simple APIs (e.g. `KMP::find_all`, `ZFunction::build`, `RollingHash::get`).


Repository structure (what to look for)
- `templates/graph/` — MST, shortest paths, maxflow, SCC, bridges, and helpers.
- `templates/string/` — KMP, Z-function, Manacher, Rolling Hash, Suffix Automaton (struct APIs included).
- `templates/dp/` — LIS, knapsack, bitmask DP examples, Li Chao.
- `templates/tree/` — segment trees (lazy), HLD, persistent segtree, centroid decomposition.
- `templates/number-theory/` — Miller–Rabin, Pollard Rho, nCr, modular utilities.
- `templates/misc/` — binary search patterns, sliding window, Kadane, Mo's algorithm.
- `templates/geometry/` — convex hull and geometry helpers.


Quick start

- Compile & run a template:

```bash
g++ -std=c++17 -O2 templates/string/kmp.cpp -o /tmp/kmp
printf "pattern text" | /tmp/kmp
```

- Reuse a template inside your solution: copy the file contents (or `#include` a `templates/common.h` if you add one) and call the provided API.


Common APIs (examples)
- KMP — find occurrences of `pat` in `txt`:

```cpp
auto occ = KMP::find_all("pat", "...text..."); // vector<int> of 0-based indices
```

- Z-function — prefix matches starting at each position:

```cpp
auto z = ZFunction::build(s); // z[i] = longest match of prefix at s[i]
```

- Rolling Hash — get substring hash `[l,r)`:

```cpp
RollingHash rh(s);
auto h = rh.get(l, r); // use for substring equality checks
```

- Suffix Automaton — build and inspect states:

```cpp
auto sa = SuffixAutomaton::build_from(s);
// inspect sa.st or extend for queries
```


Formatting & build notes
- Recommended compile flags: `-std=c++17 -O2 -Wall -Wextra`.


## Vim Integration

To use `snippets.cpp` as code snippets in Vim:

1. Install the [UltiSnips](https://github.com/SirVer/ultisnips) plugin.
2. Locate your `.vim` folder.
3. Paste `snippets.cpp` into the appropriate UltiSnips directory.

## Purpose

This repo serves as a personal backup and quick-access resource for frequently used code and editor configurations in competitive programming.

