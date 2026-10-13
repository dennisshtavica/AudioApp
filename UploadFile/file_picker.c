
#include <windows.h>
#include <commdlg.h>
#include <string.h>
#include "file_picker.h"

int OpenAudioFile(char *filePath, size_t bufferSize)
{
    OPENFILENAMEA ofn = {0};

    filePath[0] = '\0';

    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;

    ofn.lpstrFilter =
        "Audio Files (*.wav;*.mp3;*.m4a;*.ogg;*.flac)\0"
        "*.wav;*.mp3;*.m4a;*.ogg;*.flac\0"
        "All Files (*.*)\0"
        "*.*\0";

    ofn.nFilterIndex = 1;
    ofn.lpstrFile = filePath;
    ofn.nMaxFile = (DWORD)bufferSize;

    ofn.Flags = OFN_FILEMUSTEXIST |
                OFN_PATHMUSTEXIST |
                OFN_NOCHANGEDIR;

    if (GetOpenFileNameA(&ofn))
    {
        return 1;
    }

    return 0;
}
