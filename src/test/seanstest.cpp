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

void test_HSV()
    {
        Image im2 = load_image("data/dog.jpg");
        rgb_to_hsv(im2);
        shift_image(im2, 1, .2);
        clamp_image(im2);
        hsv_to_rgb(im2);
        im2.save_image("output/colorspace_result");
    }

void test_scale()
    {
        Image im = load_image("data/dog.jpg");
        rgb_to_hsv(im);
        scale_image(im, 1, 2);
        clamp_image(im);
        hsv_to_rgb(im);
        im.save_image("output/dog_scale_saturated");
    }

void run_tests()
  {
  test_clamp_image();
  test_shift_image();
  test_HSV();
  test_scale();
  }


int main(int argc, char **argv)
  {
  // Running example tests
  run_tests();
  
  return 0;
  }