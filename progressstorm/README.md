# progressstorm

Tiny header-only progress bar utility with a small library of styles. It is intended
for command-line tools that need to show progress on long-running tasks without
flooding the terminal (e.g., batch processing, downloads, or large loops).

If you're looking for a spinner to show when you don't know the final amount of work
to do, check out [spinnerstorm](https://github.com/Armchair-Software/spinnerstorm).

## Why this library

- Header-only and easy to drop into a project without build system changes.
- Compile-time style data: styles are `constexpr`, so bar components are known at
  compile time and there are no dynamic allocations.
- Cheap updates: uses simple arithmetic and minimizes output writes.

## Usage

Minimal (defaults to the ASCII equals style):

```cpp
#include "progressstorm/progress_bar.h"

int main() {
  progressstorm::progress_bar bar;
  bar.total = 100;
  // ... work ...
  bar.update(42); // progress is relative to total
}
```

## Template arguments

`progressstorm::progress_bar<T, Style, SummaryText>` parameters:

- `T`: numeric type for `current`/`total` (default `unsigned int`).
- `Style`: style struct with `start`, `end`, `fill`, `tip`, `empty` (default `styles::ascii_equals_pointed`).
- `SummaryText`: enable/disable the trailing percentage and `(current/total)` text (default `true`).

Example with floating point types:
```cpp
#include "progressstorm/progress_bar.h"

int main() {
  progressstorm::progress_bar<double> bar;
  bar.total = 1.0;
  // ... work ...
  bar.update(0.42);
```

## Members

- `display_width`: number of character cells used for the bar body (default `40`).
- `total`: total units of work.
- `current`: completed units of work.

Explicit style selection:

```cpp
#include "progressstorm/progress_bar.h"

int main() {
  progressstorm::progress_bar<unsigned int, progressstorm::styles::unicode_blocks, false> bar;
  bar.total = 100;
  bar.display_width = 80;
  // ... work ...
  bar.update(42);
}
```

### Example progress bar styles

```pre
[================>                                                               ] 20.16% (2016/10000)

▕▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▏

<▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▶·······························································> 20.01% (2001/10000)

┠──────────────────────────────────────────────╼                                 ┃ 58.23% (5823/10000)

╠══════════════════════════════════════════════════════════════════════━─────────╢
```


## Custom style

Define a style with `start`, `end`, `fill`, `tip`, and `empty`, then pass it to the
template:

```cpp
#include <string_view>
#include "progressstorm/progress_bar.h"

struct my_style {
  static constexpr std::string_view start{"{"};
  static constexpr std::string_view end{"}"};
  static constexpr std::string_view fill{"#"};
  static constexpr std::string_view tip{">"};
  static constexpr std::string_view empty{"."};
};

int main() {
  progressstorm::progress_bar<my_style> bar;
  bar.total = 100;
  // ... work ...
  bar.update(42);
}
```
