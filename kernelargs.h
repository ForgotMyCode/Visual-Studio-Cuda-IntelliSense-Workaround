#pragma once

#ifdef __INTELLISENSE__
  #define CUDA_ARGS(...)
#else
  #define CUDA_ARGS(...) <<< __VA_ARGS__ >>>
#endif
