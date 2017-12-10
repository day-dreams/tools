#include <string>

using std::string;

int main(int argc, char **argv) {
  auto command = string("python /usr/local/bin/_ipwhereis/ipwhereis.py ") +
                 string(argv[1]);
  return system(command.c_str());
}