#include "ZipLib/ZipFile.h"
#include <iostream>
#include <sstream>

int main(){
  ZipArchive::Ptr archive = ZipFile::Open("archive.zip");

  ZipArchiveEntry::Ptr entry = archive->GetEntry("file.txt");

  if (entry->IsPasswordProtected()){
    entry->SetPassword("password");
  }

  std::istream* decompressStream = entry->GetDecompressionStream();
  std::string line;
  std::getline(*decompressStream, line);

  printf("First line of a file: '%s'\n", line.c_str());
}
