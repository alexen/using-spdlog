#include <iostream>

int main()
{
     try
     {
     }
     catch( const std::exception& e )
     {
          std::cerr << "exception: " << e.what() << '\n';
          return 1;
     }
     return 0;
}
