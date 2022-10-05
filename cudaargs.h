#pragma once

#ifdef __INTELLISENSE__
#define CUDA_ARGS(...)
#define CUDA_HIDE_ERRORS(CODE) {}
#else
#define CUDA_ARGS(...) <<< __VA_ARGS__ >>>
#define CUDA_HIDE_ERRORS(CODE) CODE
#endif
