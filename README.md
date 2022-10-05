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
#include "cudaargs.h"
...

dim3 gridRes( ..., ..., ...);
dim3 blockRes( ..., ..., ...);

myKernel CUDA_ARGS(gridRes, blockRes) (args);  // OK
```

Extra:

```c
__syncthreads();  // false alarm

```

```c
// include this first
#include "cudaargs.h"
// then other cuda related includes ...
...
// __syncthreads will actually not cause errors anymore when "cudaargs.h" is properly (first) included,
// but if there is ever anything that causes false errors, you can use this
CUDA_HIDE_ERRORS(__syncthreads());  // OK
```

There is also a workaround that properly loads the functions like `__syncthread` mentioned above. To make it work properly make you sure the `#include "cudaargs.h"` is **before any cuda includes**.

```c
#include "cudaargs.h"
...

__syncthreads();  // OK
```
