#include "ZipLib/ZipFile.h"
#include <iostream>
#include <sstream>

int main(){
    ZipArchive::Ptr archive = ZipFile::Open("archive.zip");
    ZipArchiveEntry::Ptr entry = archive->CreateEntry("file.txt");

    // if entry is nullptr, it means the file already exists in the archive
    assert(entry != nullptr);

    std::stringstream data;
    data << "this is some text";
    entry->SetCompressionStream(data);
    entry->SetPassword("password");

    ZipFile::SaveAndClose(archive, "archive.zip");
}
