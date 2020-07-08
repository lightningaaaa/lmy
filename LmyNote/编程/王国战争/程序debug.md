1、设置断点
D:\MyCode_ShareVm\War-Of-Kingdom\kingdom-src\kingdom\kingdom\game.cpp 1799行
#if defined(__APPLE__) && !TARGET_OS_IPHONE
int SDL_main(int argc, char** argv)
#else
int main(int argc, char** argv)
#endif