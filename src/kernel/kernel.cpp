#include "kernelUtil.h"
#include "memory/heap.h"
#include "scheduling/pit/pit.h"

extern "C" void kernel_Main(BootInfo* bootInfo){

    KernelInfo kernelInfo = InitializeKernel(bootInfo);
    

    while(true){
        asm ("hlt");
    }

}