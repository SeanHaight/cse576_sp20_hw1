#include "image.h"

// HW0 #1
// const Image& im: input image
// int x,y: pixel coordinates
// int ch: channel of interest
// returns the 0-based location of the pixel value in the data array
int pixel_address(const Image& im, int x, int y, int ch)
  {
  return im.h*im.w*ch + im.w*y + x;
  }

// HW0 #1
// const Image& im: input image
// int x,y,ch: pixel coordinates and channel of interest
// returns the value of the clamped pixel at channel ch
float get_clamped_pixel(const Image& im, int x, int y, int ch)
  {
  // TODO: clamp the coordinates and return the correct pixel value
  int clmp_x = min(max(x,0), im.w - 1);
  int clmp_y = min(max(y,0),im.h- 1);
  int clmp_ch = min(max(ch,0),im.c - 1);
  
  return im(clmp_x,clmp_y,clmp_ch);
  }


// HW0 #1
// Image& im: input image
// int x,y,ch: pixel coordinates and channel of interest
void set_pixel(Image& im, int x, int y, int c, float value)
  {
  // TODO: Only set the pixel to the value if it's inside the image
  int clmp_x = min(max(x,0), im.w);
  int clmp_y = min(max(y,0),im.h);
  int clmp_ch = min(max(c,0),im.c);

  if(x != clmp_x & y != clmp_y & c != clmp_ch) {
    return;
  }

  im(x,y,c) = value;
  
  }



// HW0 #2
// Copies an image
// Image& to: destination image
// const Image& from: source image
void copy_image(Image& to, const Image& from)
  {
  // allocating data for the new image
  to.data=(float*)calloc(from.w*from.h*from.c,sizeof(float));
  to.c=from.c;
  to.w = from.w;
  to.h = from.h;
  
  // TODO: populate the remaining fields in 'to' and copy the data
  // You might want to check how 'memcpy' function works
  memcpy(to.data, from.data, from.c*from.w*from.h*sizeof(float));
  return;
  }