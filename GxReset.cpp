#include "GxIAPI.h"
#include <iostream>

int main(int argc, char** argv)
{
  if(argc < 2)
  {
    std::cerr << "Usage: " << argv[0] << " <MAC ADDRESS>" << std::endl;
    return 0;
  }

  GX_STATUS status = GXInitLib();
  if(status == GX_STATUS_SUCCESS)
  {
    status = GXGigEResetDevice(argv[1], GX_MANUFACTURER_SPECIFIC_RESET);
    if(status != GX_STATUS_SUCCESS)
    {
      std::cerr << "Can't reset camera " << argv[1] << ", status: " << status << std::endl;
      return -1;
    }
  }
  else
  {
    std::cerr << "Can't initialiaze Galaxy Library" << std::endl;
    return -1;
  }
  GXCloseLib();
  return 0;
}
