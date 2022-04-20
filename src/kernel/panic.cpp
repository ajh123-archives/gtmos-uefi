#include "panic.h"
#include "BasicRenderer.h"

void Panic(const char* panicMessage){
    GlobalRenderer->ClearColour = 0x00ff0000;
    GlobalRenderer->Clear();

    GlobalRenderer->CursorPosition = {0, 0};

    GlobalRenderer->Colour = 0x00ffffff;

    GlobalRenderer->Print("A problem has been detected and GTMOS has been shut down to prevent damage to your computer.");
    GlobalRenderer->Next();
    GlobalRenderer->Print("The problem seems to be caused by the following error");
    GlobalRenderer->Next();
    GlobalRenderer->Print(panicMessage);
    GlobalRenderer->Next();
    GlobalRenderer->Print("If this is the first time you've seen this Kernel Panic screen, restart your computer. If this screen appears again, follow these steps:");
    GlobalRenderer->Next();
    GlobalRenderer->Print("Check to make sure any new hardware software is properly installed.  If this is a new installation, ask your hardware or software manufacturer for any Windows updates you might need.");
    GlobalRenderer->Next();
    GlobalRenderer->Print("If problems continue, disable or remove any newly installed hardware or software. Disable BIOS memory options such as caching or shadowing. If you need to use safe mode to remove or disable components, restart your computer, press F8 to select Startup Options, and then select Safe Mode.");
}