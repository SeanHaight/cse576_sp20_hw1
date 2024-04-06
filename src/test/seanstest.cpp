#include "../image.h"
#include "../utils.h"

#include <string>

using namespace std;

void test_clamp_image()
    {
        Image im = load_image("data/dog.jpg");
        shift_image(im, 0, .4);
        shift_image(im, 1, .4);
        shift_image(im, 2, .4);
        clamp_image(im);
        im.save_image("output/clamp_result");
    }

void test_shift_image()
    {
        Image im = load_image("data/dog.jpg");
        shift_image(im, 0, .4);
        shift_image(im, 1, .4);
        shift_image(im, 2, .4);
        im.save_image("output/shift_result");
    }

void run_tests()
  {
  test_clamp_image();
  test_shift_image();
  }


int main(int argc, char **argv)
  {
  // Running example tests
  run_tests();
  
  return 0;
  }