#ifndef COMMON_LIB_H
#define COMMON_LIB_H

#include <unistd.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <common/color.h>

#define progress_length 30

namespace common_lib {
  static void showProgress(float progress, std::string word = " ", std::string COLORFONT = CYAN, std::string COLORNUM = WHITE) {
    if (progress > 1) {
      progress = 1;
    }

    int pa = progress * progress_length;

    static bool start_print_flag = true;
    static std::string last_word = " ";
    if (word != last_word) {
      start_print_flag = true;
      last_word = word;
    }
    
    if (start_print_flag)
      start_print_flag = false;
    else
      std::cout << "\33[1A";

    int word_length = word.size();
    if (word_length < 25) {
      std::cout << COLORFONT << "[" + word + "]" + std::string(25 - 3 - word_length, ' ') << "["
                << std::string(pa, '|') + std::string(progress_length - pa, ' ') << " " << RESET
                << COLORNUM << std::setw(6) << std::fixed << std::setprecision(2) << progress * 100 << "%" << RESET
                << COLORFONT << "]" << RESET << std::endl;
    } else if (word_length < 30 ){
      std::cout << COLORFONT << "[" + word + "]" + std::string(30 - 3 - word_length, ' ') << "["
                << std::string(pa, '|') + std::string(progress_length - pa, ' ') << " " << RESET
                << COLORNUM << std::setw(6) << std::fixed << std::setprecision(2) << progress * 100 << "%" << RESET
                << COLORFONT << "]" << RESET << std::endl;
    } else if (word_length == 0 || word_length >= 30) {
      std::cout << COLORFONT << "[" + word + "] " << "["
                << std::string(pa, '|') + std::string(progress_length - pa, ' ') << " " << RESET
                << COLORNUM << std::setw(6) << std::fixed << std::setprecision(2) << progress * 100 << "%" << RESET
                << COLORFONT << "]" << RESET << std::endl; 
    }
    
    fflush(stdout);
  }
}

#endif
