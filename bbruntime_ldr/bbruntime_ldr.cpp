#pragma warning( disable:4786 )

#include "bbruntime_ldr.h"

Runtime* _cdecl runtimeGetRuntime();

extern "C" __declspec(dllimport) void __cdecl __MAIN();

int WINAPI WinMain(
  _In_ HINSTANCE hInstance,
  _In_opt_ HINSTANCE hPrevInstance,
  _In_ LPSTR lpCmdLine,
  _In_ int nShowCmd
)
{
  const auto runtime = runtimeGetRuntime();
  runtime->startup(hInstance);
  
  //get cmd_line and params
  std::string cmd = GetCommandLine(), params;
  while (!cmd.empty() && cmd[0] == ' ')
    cmd = cmd.substr(1);
  if (cmd.find('\"') == 0)
  {
    const auto n = cmd.find('\"', 1);
    if (n != std::string::npos)
    {
      params = cmd.substr(n + 1);
      cmd = cmd.substr(1, n - 1);
    }
  }
  else
  {
    const auto n = cmd.find(' ');
    if (n != std::string::npos)
    {
      params = cmd.substr(n + 1);
      cmd = cmd.substr(0, n);
    }
  }
  
  runtime->execute((void(*)())&__MAIN, params.c_str(), nullptr);
  runtime->shutdown();
  
  return 0;
}
