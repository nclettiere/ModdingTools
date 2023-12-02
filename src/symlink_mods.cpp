#ifdef _WIN32
#include <Windows.h>
#endif

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

#define LOG_COLOR (1)
#define LOG_LEVEL (7)

#include "utils.h"


void deleteFolders(const fs::path& directoryPath) {
    for (const auto& entry : fs::directory_iterator(directoryPath)) {
		try {
			if (fs::exists(entry) && fs::is_symlink(entry)) {
				fs::remove(entry);
			}
		} catch (const fs::filesystem_error& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
    }
}

int CreateSymbolicLinkInFolder(const std::string& targetDirectory, const std::string& linkDirectory) {
	fs::path sourceFolder = targetDirectory;
    fs::path targetFolder = linkDirectory;

	if(!fs::exists(sourceFolder))
	{
		errno = ENOENT;
		lwlog_crit_t("La ruta %s no existe.", targetDirectory.c_str());
		return errno;
	}

	if(!fs::exists(targetFolder))
	{
		errno = ENOENT;
		lwlog_crit_t("La ruta %s no existe.", linkDirectory.c_str());
		return errno;
	}
	
	deleteFolders(targetFolder);
	
	int count = 0;
	int fails = 0;
	
	int it_next_chance = 0;

    for (const auto& entry : fs::directory_iterator(sourceFolder)) {
        const auto& sourcePath = entry.path() / "mods";
		
		if(fs::exists(sourcePath)) {
			
			for (const auto& mod_entry : fs::directory_iterator(sourcePath)) {	
				it_next_chance++;
				
				auto targetPath = targetFolder / mod_entry.path().filename();
				
				std::string finalPath = targetPath.string();
				if(fs::exists(targetPath))
					finalPath = finalPath + "_" + std::to_string(it_next_chance);
				
				if(fs::exists(sourcePath)) {
					try {
						fs::create_directory_symlink( mod_entry.path(), finalPath);
						std::cout << "> Symbolic link created for directory " << targetPath << std::endl;
						count++;
					} catch (const std::exception& e) {
						lwlog_err("Error creating symbolic link for %s ?? %s\n", sourcePath.string().c_str(), e.what());
						fails++;
					}
				}
			}
		}
    }
	
	std::cout << "\n> TOTAL : " << count << " mods" << std::endl;
	std::cout << "> FALLOS: " << fails << " mods" << std::endl;
	
	return 0;
}


int main(int argc, char* argv[]) {
	printf(BANNER);
    
    if (argc != 3) {
		errno = EINVAL;
		lwlog_emerg("Argumentos invalidos.");
        printf("Usage: symlink.exe \"<source_folder>\" \"<destination_folder>\"\n");
        return 1;
    }

    std::string srcFolder = argv[1];
    std::string destFolder = argv[2];
	
	std::cout << "Se borraran todos los archivos en: " << destFolder << std::endl;
	
	std::string userName = "y";
    
    do {
        std::cout << "Desea continuar? [Y/n]: ";
        std::getline(std::cin, userName);

        if (userName == "n" || userName == "N") {
			lwlog_info("Aborted.");
            return 0;
		}

    } while (userName != "y" && userName != "Y" && userName != "");
	
	
	std::cout << std::endl;
	
	int res = CreateSymbolicLinkInFolder(srcFolder, destFolder);
    if(res > 0)
	{
		lwlog_emerg("Fallo monumental. Contacte al leche.");
		return res;
	}
	
	std::cout << std::endl;
	lwlog_info_t("Done.");
	lwlog_info_t("Usted fue atendidos por: Lord Lactoso");
	lwlog_info_t("\t \"gracias vuelva prontos.\"");
	std::cout << std::endl;
	
	system("pause");
	
#ifdef _WIN32
	std::ignore = ShellExecuteA(nullptr, "open", "explorer.exe", destFolder.c_str(), nullptr, SW_SHOWNORMAL);
#endif
    return 0;
}
