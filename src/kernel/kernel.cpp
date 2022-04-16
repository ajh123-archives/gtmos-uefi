#include "BasicRenderer.h"
#include "cstr.h"

extern "C" int kernel_Main(Framebuffer* framebuffer, PSF1_FONT* psf1_font)
{
    BasicRenderer newRenderer = BasicRenderer(framebuffer, psf1_font); 
    newRenderer.Colour = 0xffffffff;
    newRenderer.Print("Hello, world");   
    newRenderer.CursorPosition = {0, newRenderer.CursorPosition.Y + 16}; 

    newRenderer.Print(to_string((uint64_t)1234976));
    newRenderer.CursorPosition = {0, newRenderer.CursorPosition.Y + 16};
    newRenderer.Print(to_string((int64_t)-1234976));
    newRenderer.CursorPosition = {0, newRenderer.CursorPosition.Y + 16};
    newRenderer.Print(to_string((double)-13.14));
    newRenderer.CursorPosition = {0, newRenderer.CursorPosition.Y + 16};
    newRenderer.Print(to_hstring((uint64_t)0xF0));
    newRenderer.CursorPosition = {0, newRenderer.CursorPosition.Y + 16};
    newRenderer.Print(to_hstring((uint32_t)0xF0));
    newRenderer.CursorPosition = {0, newRenderer.CursorPosition.Y + 16};
    newRenderer.Print(to_hstring((uint16_t)0xF0));
    newRenderer.CursorPosition = {0, newRenderer.CursorPosition.Y + 16};
    newRenderer.Print(to_hstring((uint8_t)0xF0));

    return 0;
}