
#include <curl/curl.h>

#ifdef _WIN32
#include <Windows.h>
#endif

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

#define LOG_COLOR (1)
#define LOG_LEVEL (7)

#include "utils.h"

constexpr const char *endpoint = "https://cloud.lactoservice.uk/index.php/s/zomboid_mod_default/download/default.txt";

int fetchDefaults(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    printf(BANNER);

    int result = fetchDefaults(argc, argv);

    if (result != 0)
    {
        lwlog_emerg("Fallo monumental; -> Contacte al leche.");
    }

    std::cout << std::endl;
    lwlog_info_t("Done.");
    lwlog_info_t("Usted fue atendidos por: Lord Lactoso");
    lwlog_info_t("\t \"gracias vuelva prontos.\"");
    std::cout << std::endl;

    system("pause");

    return result;
}

size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *output)
{
    size_t total_size = size * nmemb;
    output->append((char *)contents, total_size);
    return total_size;
}

bool DownloadFile(const std::string& url, const std::string& outputFilePath)
{
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        std::string response_string;
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        curl_easy_cleanup(curl);

		std::ofstream outputFile(outputFilePath);
		if (outputFile.is_open()) {
			outputFile << response_string;
			outputFile.close();
		} else {
			lwlog_crit("Unable to open the file for writing.");
			return false;
		}
    }

    curl_global_cleanup();

    return true;
}

int fetchDefaults(int argc, char *argv[])
{
    std::string destFolder;

    if (argc != 3)
    {
        auto homeFolder = fs::path(getHomeFolder());
        auto zomboidModsFolder = homeFolder / "Zomboid" / "mods";

        std::string def_destFolder = zomboidModsFolder.string();

        printf("Carpeta de mods PZ (%s) \n[ENTER] ", def_destFolder.c_str());
        std::getline(std::cin, destFolder);

        if (destFolder.empty())
            destFolder = def_destFolder;

        printf("\n");
    }

    fs::path defaultsFile = fs::path(destFolder) / "default.txt";

    if (fs::exists(defaultsFile))
    {
        lwlog_warning_t("Ya existe un archivo default.txt en la carpeta de mods.");
        fs::remove(defaultsFile);
        return 0;
    }

    if (!DownloadFile(endpoint, defaultsFile.string()))
    {
        lwlog_crit("El servidor del leche esta caido.");
        return 1;
    }

    return 0;
}