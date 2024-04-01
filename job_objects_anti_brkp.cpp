
#include <iostream>
#include <Windows.h>

void object_start()
{
    HANDLE job = CreateJobObject(nullptr, nullptr);
    if (job == nullptr) {
        return;
    }

    if (!AssignProcessToJobObject(job, GetCurrentProcess())) {
        CloseHandle(job);
        return;
    }

    JOBOBJECT_EXTENDED_LIMIT_INFORMATION limits = { 0 };
    limits.ProcessMemoryLimit = 0x1000;
    limits.BasicLimitInformation.LimitFlags = JOB_OBJECT_LIMIT_PROCESS_MEMORY;

    if (!SetInformationJobObject(job, JobObjectExtendedLimitInformation, &limits, sizeof(limits))) {
        CloseHandle(job);
        return ;
    }
}
int main()
{
    object_start();
}