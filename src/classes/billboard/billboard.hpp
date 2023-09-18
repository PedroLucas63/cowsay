#include <iostream>
#include <vector>
#include <string>
#include "fstring.hpp"

#ifndef BILLBOARD_HPP_
#define BILLBOARD_HPP_

class Billboard {
public:
Billboard(std::string text_, bool regular_, size_t column_size_, fos::align alignment_);
void draw();

private:
std::string text;
bool regular;
size_t column_size;
fos::align alignment;

void format();
};

#endif // BILLBOARD_HPP_