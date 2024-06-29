#pragma once

#include <memory>

constexpr const char *BANNER = R"V0G0N(
          _                        _
 _ __ ___| | __ _ _   _ _ __   ___| |__   ___ _ __
| '_ \_  / |/ _` | | | | '_ \ / __| '_ \ / _ \ '__|
| |_) / /| | (_| | |_| | | | | (__| | | |  __/ |
| .__/___|_|\__,_|\__,_|_| |_|\___|_| |_|\___|_|
|_| )V0G0N";

namespace ftxui {
class Node;
using Element = std::shared_ptr<Node>;
} // namespace ftxui

enum CurrentAction_ {
  CurrentAction_FetchingPatches,
  CurrentAction_DownloadingPatches,
  CurrentAction_AplyingPatches,
  CurrentAction_PatchError,
  CurrentAction_PatchSuccess,

  CurrentAction_LaunchingPz,

  CurrentAction_None
};

typedef CurrentAction_ CurrentAction;

struct AppState {
  CurrentAction currentAction = CurrentAction_None;
  float dt = 0.0f;

  float downloadState = 0.0f;

  bool terminate = false;
};

ftxui::Element uiDocument(AppState &state);

ftxui::Element uiSummary(AppState &state);
ftxui::Element uiPatchSummary(AppState &state);
ftxui::Element uiCurrentAction(AppState &state);