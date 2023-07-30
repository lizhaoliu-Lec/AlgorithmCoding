#ifndef DIFFERENCE
#define DIFFERENCE
#include <iostream>
#include <vector>

using namespace std;

class Difference {
   private:
    vector<int> diff;

   public:
    Difference(vector<int> nums);
    ~Difference();

    void increment(int i, int j, int val);

    vector<int> result();
};

#endif  // DIFFERENCE