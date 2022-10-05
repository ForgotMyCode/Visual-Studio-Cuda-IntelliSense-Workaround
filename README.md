# Visual Studio Cuda IntelliSense False Error Workaround

Workaround to get rid of false errors in visual studio when calling cuda kernels.

Calling a cuda kernel in visual studio would produce an error:

```c
dim3 gridRes( ..., ..., ...);
dim3 blockRes( ..., ..., ...);

myKernel <<<gridRes, blockRes>>> (args);  // E0029 false alarm
```

Using this workaround, the cuda arguments don't exist from the point of view of IntelliSense. The compiled result is equivalent.

```c
#include "kernelargs.h"
...

dim3 gridRes( ..., ..., ...);
dim3 blockRes( ..., ..., ...);

myKernel CUDA_ARGS(gridRes, blockRes) (args);  // OK
```
