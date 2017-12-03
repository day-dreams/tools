#include <arpa/inet.h>
#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

int main(int argc, char **argv) {

  if (argc <= 1) {
    cout << "use: long2ip [int] [int] .." << endl;
  } else {
    char ipstr[16];
    for (int i = 1; i != argc; ++i) {
      unsigned int x = 0;
      for (int j = 0; argv[i][j] != '\0'; ++j) {
        if (argv[i][j] >= '0' && argv[i][j] <= '9') {
          x *= 10;
          x += argv[i][j] - '0';
        } else { // error
          goto error_input;
        }
      }
      x = htonl(x);
      inet_ntop(AF_INET, &x, ipstr, 16);
      cout << ipstr << endl;
    }
  }

  return 0;
error_input:
  cout << "wrong input" << endl;
  return -1;
}