// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "menu.h"

typedef void(__cdecl* Menu_PaintAll_t)(int localClientNum, void* dc);
Menu_PaintAll_t Menu_PaintAll = (Menu_PaintAll_t)addresses::Menu_PaintAllAddr;

void PlutoT5DrawHook(int localClientNum, void* dc)
{
    menu::Draw();
    Menu_PaintAll(localClientNum, dc);
}

void PlutoT5AttachHooks()
{
    LONG error;

    error = DetourTransactionBegin();
    if (error != NO_ERROR)
    {
        // TODO catch error
        return;
    }
    error = DetourUpdateThread(GetCurrentThread());
    if (error != NO_ERROR)
    {
        // TODO catch error
        return;
    }
    error = DetourAttach(&(PVOID&)Menu_PaintAll, PlutoT5DrawHook);
    if (error != NO_ERROR)
    {
        // TODO catch error 
        return;
    }
    error = DetourTransactionCommit();
    if (error != NO_ERROR)
    {
        // TODO catch error
        return;
    }
}

void PlutoT5DetachHooks()
{
    LONG error;

    error = DetourTransactionBegin();
    if (error != NO_ERROR)
    {
        // TODO catch error
        return;
    }
    error = DetourUpdateThread(GetCurrentThread());
    if (error != NO_ERROR)
    {
        // TODO catch error
        return;
    }
    error = DetourDetach(&(PVOID&)Menu_PaintAll, PlutoT5DrawHook);
    if (error != NO_ERROR)
    {
        // TODO catch error 
        return;
    }
    error = DetourTransactionCommit();
    if (error != NO_ERROR)
    {
        // TODO catch error
        return;
    }
}

void PlutoT5Thread(HMODULE hModule)
{
    OutputDebugString(L"Hello, world! :)");
    PlutoT5AttachHooks();

    bool thread_running = true;
    while (thread_running)
    {
        if (GetAsyncKeyState(VK_F1))
            thread_running = false;

        menu::Update();
    }

    PlutoT5DetachHooks();
    OutputDebugString(L"Goodbye, world! :(");
    Sleep(500); // Give the thread time to breathe before release 
    FreeLibraryAndExitThread(hModule, 0);
}

BOOL PlutoT5Attach(HMODULE hModule)
{
    HANDLE thread_handle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)PlutoT5Thread, hModule, 0, NULL);

    bool thread_created = (thread_handle != NULL);
    if (thread_created)
    {
        BOOL handle_closed = CloseHandle(thread_handle);
        if (!handle_closed)
        {
            DWORD error = GetLastError();
            // TODO catch thread handle closing errors 
            return FALSE;
        }
    }
    else
    {
        DWORD error = GetLastError();
        // TODO catch thread creation errors 
        return FALSE;
    }

    return TRUE;
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    BOOL process_attached = TRUE;

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        // TODO return the proper BOOL for DllMain()
        process_attached = PlutoT5Attach(hModule);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }

    // Make it easy to add && conditions later
    return (process_attached);
}

