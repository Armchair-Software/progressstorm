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
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wfloat-equal"
    if(total == 0) return;
    #pragma GCC diagnostic pop
    float const ratio{static_cast<float>(current) / static_cast<float>(total)};
    unsigned int const filled_length{static_cast<unsigned int>(ratio * static_cast<float>(display_width))};
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
      // if T is a floating point type, format with 2 decimal places
      if constexpr(std::is_floating_point_v<T>) {
        std::cout << Style::end
          << ' ' << std::format("{:.2f}%", (static_cast<float>(current) / static_cast<float>(total)) * 100.0f)
          << " (" << std::format("{:.2f}", static_cast<float>(current)) << "/" << std::format("{:.2f}", static_cast<float>(total)) << ")"
          << std::flush;
      } else {
        std::cout << Style::end
          << ' ' << std::format("{:.2f}%", (static_cast<float>(current) / static_cast<float>(total)) * 100.0f)
          << " (" << current << "/" << total << ")"
          << std::flush;
      }
    }
  }
};

} // namespace progressstorm
