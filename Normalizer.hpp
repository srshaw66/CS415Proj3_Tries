#ifndef NORMALIZER_HPP
#define NORMALIZER_HPP

#include <string>
#include <vector>

// Returns the token lowercased with every non a-z character removed.
// Examples: "People," -> "people", "rest--along" -> "restalong".
// May return an empty string; callers should skip empty results.
std::string normalize(const std::string& token);

// Reads the file, splits on whitespace, normalizes each token,
// and returns the non-empty words in file order (duplicates kept).
std::vector<std::string> readWords(const std::string& filename);

#endif
