#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv) {

  if (argc <= 1) {
    cout << "use: ip2long [ipaddress] [ipaddress] .." << endl;
  } else {
    for (int i = 1; i != argc; ++i) {

      int a = 0, b = 0, c = 0, d = 0;
      string ip(argv[i]);
      int state = 0;

      for (auto ite = ip.begin(); ite != ip.end(); ++ite) {
        if (a > 255 | b > 255 | c > 255 | d > 255) { // error
          goto error_input;
        }

        switch (state) {
        case 0:
          if (*ite >= '0' & *ite <= '9') {
            a *= 10;
            a += *ite - '0';
            state = 1;
          } else { // error
            goto error_input;
          }
          break;

        case 1:
          if (*ite >= '0' & *ite <= '9') {
            a *= 10;
            a += *ite - '0';
          } else if (*ite == '.') { // finish first num
            state = 2;
          } else { // eror
            goto error_input;
          }
          break;

        case 2:
          if (*ite >= '0' & *ite <= '9') {
            b *= 10;
            b += *ite - '0';
          } else if (*ite == '.') { // finish second num
            state = 3;
          } else { // eror
            goto error_input;
          }

          break;
        case 3:
          if (*ite >= '0' & *ite <= '9') {
            c *= 10;
            c += *ite - '0';
          } else if (*ite == '.') { // finish third num
            state = 4;
          } else { // eror
            goto error_input;
          }

          break;
        case 4:

          if (*ite >= '0' & *ite <= '9') {
            d *= 10;
            d += *ite - '0';
          } else { // error
            goto error_input;
          }

          break;
        }
      }

      if (state != 4)
        goto error_input;
      else {
        cout << (unsigned int)(a * 256 * 256 * 256 + b * 256 * 256 + c * 256 +
                               d)
             << endl;
      }
    }
  }
  return 0;
error_input:
  cout << "wrong input!" << endl;
  return -1;
}