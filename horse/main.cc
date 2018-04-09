#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  const uint64_t id = 410421301;
  srand(time(nullptr));

  uint64_t elapsed_time = 0;
  for (uint64_t i = 0; i < id * 2000; i += 1000) {
    int speed = rand() % 15 + 1; // Since the world's fastest can run almost 20 meters per second, our horse runs under 15 is reasonable.
    for (int j = 0; j < 1000 / speed; ++j) {
      ++elapsed_time;
      cout << "-";
    }
    elapsed_time += 1000 / speed;
    cout << endl;
  }

  cout << "Wow, it took my horse " << elapsed_time << " seconds to finish " << id << " * 2 = " << id * 2 << " meters." << endl;
  cin.ignore();
  cin.get();
  return 0;
}
