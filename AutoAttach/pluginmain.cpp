#include "pluginmain.h"
#include "trash.hpp"

PLUG_EXPORT bool pluginit(PLUG_INITSTRUCT* initStruct)
{
    initStruct->pluginVersion = PLUGIN_VERSION;
    initStruct->sdkVersion = PLUG_SDKVERSION;

    strncpy_s(initStruct->pluginName, PLUGIN_NAME, _TRUNCATE);

    _plugin_registercommand(initStruct->pluginHandle, "AutoAttachStatus", cmd::status_command, false);
    _plugin_registercommand(initStruct->pluginHandle, "AutoAttachProcess", cmd::set_command, false);
    _plugin_registercommand(initStruct->pluginHandle, "AutoAttachSleep", cmd::sleep_command, false);

    std::thread([]() {
        while (true) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            if (!config::status || config::process.empty()) continue;

            WTS_PROCESS_INFO* process_info;
            DWORD count_process;

            if (!WTSEnumerateProcesses(WTS_CURRENT_SERVER_HANDLE, 0, 1, &process_info, &count_process)) return;

            for (DWORD i = 0; i < count_process; ++i) {
                if (!config::process.compare(process_info[i].pProcessName)) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(config::sleep));
                    PROCESS_INFORMATION* get_process_attach = TitanGetProcessInformation();
                    if (get_process_attach->dwProcessId != process_info[i].ProcessId) {
                        std::string command = std::format("AttachDebugger {:x}", process_info[i].ProcessId);
                        DbgCmdExecDirect(command.data());
                    }
                    break;
                }
            }

            WTSFreeMemory(process_info);
        }
    }).detach();
    return true;
}

BOOL WINAPI DllMain(_In_ HINSTANCE hinstDLL, _In_ DWORD fdwReason, _In_ LPVOID lpvReserved) {
    return TRUE;
}
