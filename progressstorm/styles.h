#pragma once

#include <string_view>

namespace progressstorm::styles {

struct ascii_equals{
  static constexpr std::string_view start{"["};
  static constexpr std::string_view end{"]"};
  static constexpr std::string_view fill{"="};
  static constexpr std::string_view tip{fill};
  static constexpr std::string_view empty{" "};
};

struct ascii_equals_pointed{
  static constexpr std::string_view start{"["};
  static constexpr std::string_view end{"]"};
  static constexpr std::string_view fill{"="};
  static constexpr std::string_view tip{">"};
  static constexpr std::string_view empty{" "};
};

struct ascii_hash{
  static constexpr std::string_view start{"["};
  static constexpr std::string_view end{"]"};
  static constexpr std::string_view fill{"#"};
  static constexpr std::string_view tip{fill};
  static constexpr std::string_view empty{" "};
};

struct ascii_arrow{
  static constexpr std::string_view start{"["};
  static constexpr std::string_view end{"]"};
  static constexpr std::string_view fill{"-"};
  static constexpr std::string_view tip{">"};
  static constexpr std::string_view empty{" "};
};

struct pipe_blocks{
  static constexpr std::string_view start{"|"};
  static constexpr std::string_view end{"|"};
  static constexpr std::string_view fill{"█"};
  static constexpr std::string_view tip{fill};
  static constexpr std::string_view empty{" "};
};

struct unicode_blocks{
  static constexpr std::string_view start{"["};
  static constexpr std::string_view end{"]"};
  static constexpr std::string_view fill{"█"};
  static constexpr std::string_view tip{fill};
  static constexpr std::string_view empty{"░"};
};

struct unicode_shade{
  static constexpr std::string_view start{"▕"};
  static constexpr std::string_view end{"▏"};
  static constexpr std::string_view fill{"▓"};
  static constexpr std::string_view tip{"█"};
  static constexpr std::string_view empty{"░"};
};

struct dot_track{
  static constexpr std::string_view start{"("};
  static constexpr std::string_view end{")"};
  static constexpr std::string_view fill{"•"};
  static constexpr std::string_view tip{fill};
  static constexpr std::string_view empty{"·"};
};

struct triangle_tip{
  static constexpr std::string_view start{"<"};
  static constexpr std::string_view end{">"};
  static constexpr std::string_view fill{"▲"};
  static constexpr std::string_view tip{"▶"};
  static constexpr std::string_view empty{"·"};
};

struct double_line{
  static constexpr std::string_view start{"⟦"};
  static constexpr std::string_view end{"⟧"};
  static constexpr std::string_view fill{"═"};
  static constexpr std::string_view tip{fill};
  static constexpr std::string_view empty{"·"};
};

struct angle_line{
  static constexpr std::string_view start{"⟪"};
  static constexpr std::string_view end{"⟫"};
  static constexpr std::string_view fill{"-"};
  static constexpr std::string_view tip{"="};
  static constexpr std::string_view empty{" "};
};

struct box_line_double{
  static constexpr std::string_view start{"╞"};
  static constexpr std::string_view end{"│"};
  static constexpr std::string_view fill{"═"};
  static constexpr std::string_view tip{"╡"};
  static constexpr std::string_view empty{" "};
};

struct box_line_single{
  static constexpr std::string_view start{"┠"};
  static constexpr std::string_view end{"┃"};
  static constexpr std::string_view fill{"─"};
  static constexpr std::string_view tip{"╼"};
  static constexpr std::string_view empty{" "};
};

struct box_line_double_single{
  static constexpr std::string_view start{"╠"};
  static constexpr std::string_view end{"╢"};
  static constexpr std::string_view fill{"═"};
  static constexpr std::string_view tip{"━"};
  static constexpr std::string_view empty{"─"};
};

} // namespace progressstorm::styles
