*This project was created as part of the 42 curriculum by alvicent, joserome.*

# push_swap

## Description

`push_swap` sorts a list of integers using **two stacks** (`a` and `b`) and a
limited set of **11 operations** (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`,
`rr`, `rra`, `rrb`, `rrr`). The program does not just sort: it computes and
**prints the sequence of operations** that leaves stack `a` sorted in ascending
order using as few moves as possible.

The real goal of the project is **algorithmic complexity**. That is why the
binary implements four sorting strategies of different complexity classes and
picks one at runtime depending on how disordered the input is:

| Strategy | Flag | Complexity class (operation model) |
|----------|------|------------------------------------|
| Simple   | `--simple`   | O(n²) |
| Medium   | `--medium`   | O(n·√n) |
| Complex  | `--complex`  | O(n·log n) |
| Adaptive | `--adaptive` | selects one of the above from the disorder (default) |

Complexity is always measured in **number of push_swap operations produced**,
not in the theoretical complexity of the classic array algorithm.

## Instructions

### Build

```sh
make          # build push_swap (mandatory part)
make bonus    # build the checker (bonus part)
make clean    # remove object files
make fclean   # remove objects and binaries
make re       # fclean + make
```

The Makefile builds with `-Wall -Wextra -Werror` and compiles the
`printf`/`libft` library before the project, with no relink.

### Usage

Stack `a` is passed as arguments (the first argument ends up on top).
Optionally, a strategy selector **before** the numbers:

```sh
./push_swap 2 1 3 6 5 8             # adaptive strategy (default)
./push_swap --complex 4 67 3 87 23  # force the O(n·log n) strategy
./push_swap "5 4 3 2 1"            # also accepts a single space-separated argument
```

- With no arguments, it prints nothing and returns.
- On any invalid input (non-integer, value outside the `int` range,
  duplicates or an empty argument) it prints `Error\n` to standard error.

### Benchmark mode

The optional `--bench` flag prints to **stderr** (so it does not pollute the
pipe with operations): disorder index, chosen strategy and its complexity
class, total number of operations and a breakdown per operation type.

```sh
./push_swap --bench 4 67 3 87 23 2>bench.txt   # metrics to bench.txt, ops to stdout
```

### Checker (bonus)

The `checker` receives the stack as arguments and **reads the operations from
stdin**. After running them it prints `OK` if `a` is sorted and `b` empty, or
`KO` otherwise; `Error` to stderr if the input or an instruction is invalid.

```sh
ARG="4 67 3 87 23"
./push_swap --complex $ARG | ./checker $ARG    # -> OK
```

## Disorder index

Before moving anything, a number between 0 and 1 measures how far `a` is from
being sorted: it scans every pair `(i, j)` with `i < j` and counts the
**inversions** (each time a greater number appears before a smaller one). The
disorder is `inversions / total_pairs`. It is 0 when sorted and approaches 1 as
the input gets more disordered.

## Strategies and technical decisions

**Simple — O(n²).** Index-based extraction: each element (by its sorted index)
is brought to the top of `a` and pushed to `b`, then all are pushed back to
`a`. The linear search plus rotation per element gives the quadratic bound. It
is the baseline reference strategy.

**Medium — O(n·√n).** Chunk sort: the chunk size is `⌊√n⌋`. Elements whose
index falls inside the sliding window `index ≤ pushed + chunk` are pushed to
`b`, with a refinement rotation in `b` for those in the lower half; the rest
rotate in `a` until reached. Then the maximum of `b` is brought to the top
(choosing `rb` or `rrb` by its position relative to `size_b/2`) and pushed
back with `pa`, leaving `a` sorted.

**Complex — O(n·log n).** Binary radix (LSD) on each element's index: for each
bit, from least to most significant, an element is pushed to `b` if the bit is
0 or rotated in `a` if it is 1; at the end of each pass everything is pushed
back to `a`. With `⌈log₂ n⌉` linear passes it reaches the bound. It is the best
of the three for very disordered inputs.

**Adaptive.** Computes the disorder **before** moving and dispatches:

| Regime | Threshold | Strategy used | Declared class |
|--------|-----------|---------------|----------------|
| Low  | disorder < 0.2       | Simple  | O(n²) *(see note)* |
| Med  | 0.2 ≤ disorder < 0.5 | Medium  | O(n·√n) |
| High | disorder ≥ 0.5       | Complex | O(n·log n) |

### Threshold justification

A random permutation has an expected disorder of ≈ 0.5 (inversions are around
`n(n-1)/4` out of `n(n-1)/2` pairs), so the bulk of random inputs fall in the
**high regime** and are solved with the O(n·log n) radix, which scales best.
Below 0.5 the input keeps partial structure and the chunk partition (O(n·√n))
takes advantage of those almost-ordered blocks. The 0.2 cut isolates the
nearly sorted inputs, where the actual amount of work is small.

### Note on the low regime (the subject's O(n))

The subject requires the **disorder < 0.2 regime to run in O(n)**. That bound
is **unattainable in the worst case** within this model, and it is treated as
a **known erratum** of the subject. Why:

- disorder < 0.2 does **not** bound inversions to O(n): with disorder just
  below 0.2 there can be on the order of `0.1·n²` inversions, i.e. Θ(n²) pairs
  out of order.
- Counting lower bound: there exist permutations that freely shuffle within
  blocks of size 0.1n (2^Θ(n·log n) of them) with disorder ≤ 0.1 < 0.2. Since
  each operation multiplies the reachable states by 11, Ω(n·log n) operations
  are needed to distinguish them. Even O(n) is impossible.

For that reason the low regime uses the **Simple strategy, whose honest bound
is O(n²)**, which is exactly what `--bench` reports. We document the
discrepancy instead of claiming an O(n) the algorithm does not meet.

## Performance test

Measured with the default (adaptive) mode on random inputs:

- 100 numbers: ~1000–1100 operations (mandatory cutoff < 2000).
- 500 numbers: ~5800–6800 operations (mandatory cutoff < 12000).

Both under the cutoff in every run tested, verified with the `checker`. The
program has no memory leaks (valgrind clean, including the error paths).

## Resources

- Donald Knuth, *The Art of Computer Programming*, Vol. 3 (Sorting and
  Searching) — Big-O notation and sorting.
- Radix sort (LSD/MSD) — classic description of digit/bit-based sorting.
- 42 documentation and the project subject itself (`PS.pdf`).

### Use of AI

An AI tool was used as occasional support to: review the code for errors, generate the README and comment the code, as well as to fix minor errors and answer questions.

## Contributions

- **alvicent** — data structure and initialization (`init`, index and
  disorder), the four sorting strategies (`simple`, `medium`, `complex`,
  `algorithm_handler`) and the benchmark mode (`bench`).
- **joserome** — argument and flag parsing and validation (`parse_nums`,
  `parse_flags`, `errors`), stack utilities and operations (`stack_utils`,
  `moves/`) and the bonus **checker** program.