/*
 * Copyright (c) 2022 by yjz_lucky_boy, All Rights Reserved. 
 */
#include <common/common_lib.h>

int main(int argc, char** argv)
{
  // show progress sample
  for (int i = 0; i <= 100; i++)
  {
    float progress = i * 1.0 / 100;
    common_lib::showProgress(progress, std::string("test_print_1"), GREEN);
  }

  for (int i = 0; i <= 50; i++)
  {
    float progress = i * 1.0 / 50;
    common_lib::showProgress(progress, std::string("test_print_2"), YELLOW);
  }

  for (int i = 0; i <= 50; i++)
  {
    sleep(1);
    float progress = i * 1.0 / 50;
    common_lib::showProgress(progress, std::string("test_print_3"), BLUE);
  }

  return 0;
}