#pragma once

#include <iostream>
#include "styles.h"

namespace progressstorm {

template<typename T = unsigned int, typename Style = styles::ascii_equals_pointed, bool SummaryText = true>
class progress_bar {
public:
  unsigned int display_width{40};
  T total{};
  T current{};

  void update() {
    if(total == 0) return;
    T const filled_length{static_cast<T>((static_cast<double>(current) / static_cast<double>(total)) * static_cast<double>(display_width))};
    std::cout << '\r' << Style::start;
    for(unsigned int i{0}; i != display_width; ++i) {
      if(i < filled_length) {
        std::cout << Style::fill;
      } else if(i == filled_length) {
        std::cout << Style::tip;
      } else {
        std::cout << Style::empty;
      }
    }
    if constexpr(SummaryText) {
      std::cout << Style::end
                << ' ' << std::format("{:.2f}%", (static_cast<double>(current) / static_cast<double>(total)) * 100.0)
                << " (" << current << "/" << total << ")"
                << std::flush;
    }
  }
};

} // namespace progressstorm
