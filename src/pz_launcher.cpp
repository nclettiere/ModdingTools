#include "launcher_ui.h"

#include <ftxui/component/component.hpp>          // for Renderer, CatchEvent
#include <ftxui/component/screen_interactive.hpp> // for ScreenInteractive
#include <ftxui/screen/screen.hpp>                // for Screen

#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>

#include <curl/curl.h>

using namespace ftxui;

static AppState state;

void Logic(AppState &state, ScreenInteractive &screen);

int main() {
  printf(BANNER);
  printf("v1.0 (nosteam)\n\n");

  auto screen = ScreenInteractive::FitComponent();

  auto renderer = Renderer([&] {
    state.dt += 0.01;
    if (state.dt > 1.0)
      state.dt = 0.0;

    screen.PostEvent(Event::Custom);
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // 20 FPS

    return uiDocument(state);
  });

  std::thread t(Logic, std::ref(state), std::ref(screen));

  screen.Loop(renderer);
  state.terminate = true;

  t.join();

  return 0;
}

size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                     std::string *output) {
  size_t total_size = size * nmemb;
  output->append((char *)contents, total_size);

  state.downloadState = total_size;

  return total_size;
}

bool DownloadFile(const std::string &url, const std::string &outputFilePath) {
  CURL *curl;
  CURLcode res;

  curl_global_init(CURL_GLOBAL_DEFAULT);

  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    std::string response_string;
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);

    res = curl_easy_perform(curl);

    if (res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    curl_easy_cleanup(curl);

    std::ofstream outputFile(outputFilePath);
    if (outputFile.is_open()) {
      outputFile << response_string;
      outputFile.close();
    } else {
      return false;
    }
  }

  curl_global_cleanup();

  return true;
}

void Logic(AppState &state, ScreenInteractive &screen) {
  DownloadFile("https://github.com/nclettiere/ModdingTools/releases/download/0.1.5/pz_fetch-0.1.5",
               "C:\\Users\\Mosnye\\dev\\projects\\bob.zip");
  screen.PostEvent(Event::Custom);
  state.currentAction = CurrentAction_AplyingPatches;
}