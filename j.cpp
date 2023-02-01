#include <iostream>
#include <map>
#include <vector>
#include <random>

class Map {
 public:
  Map(int rows, int cols) : rows_(rows), cols_(cols) {
    // Initialize the map with empty spaces
    map_ = std::vector<std::vector<char>>(rows_, std::vector<char>(cols_, ' '));
  }

  // Populate the map with random elements
  void PopulateRandom() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        int random = dis(gen);
        map_[i][j] = (random == 0) ? 'X' : 'O';
      }
    }
  }

  // Display the map
  void Display() const {
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        std::cout << map_[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }

 private:
  int rows_;
  int cols_;
  std::vector<std::vector<char>> map_;
};

int main() {
  // Create a map with 5 rows and 7 columns
  Map game_map(5, 7);

  // Populate the map with random elements
  game_map.PopulateRandom();

  // Display the map
  game_map.Display();

  return 0;
}