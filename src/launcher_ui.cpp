#include "launcher_ui.h"

#include "ftxui/component/captured_mouse.hpp" // for ftxui
#include "ftxui/component/component.hpp"      // for Slider
#include <ftxui/dom/elements.hpp>  // for text, hbox, vbox, filler, gauge
#include <ftxui/screen/screen.hpp> // for Screen

using namespace ftxui;

Element uiDocument(AppState &state) {
  return vbox({
      hbox({
          uiSummary(state),
          uiPatchSummary(state) | flex,
      }),
      uiCurrentAction(state),
  });
}

Element uiSummary(AppState &state) {
  auto content = vbox({
      hbox({text(L"§ mods:   "), text(L"3") | bold}),
      hbox({text(L"§ active: "), text(L"2") | bold}),
      hbox({text(L"§ queue:  "), text(L"9") | bold}),
  });
  return window(text(L" Summary "), content);
}

Element uiPatchSummary(AppState &state) {
  auto content = vbox({
      hbox({text(L"§ patcher server:   "), text(L"pz.claldy.uk") | bold}),
      hbox({text(L"§ current patch: "), text(L"#2") | bold,
            text(L" (needs update)")}) |
          color(Color::RedLight),
      hbox({text(L"§ last patch:  "), text(L"#9") | bold}),
  });
  return window(text(L" Patch Summary "), content);
}

Element uiCurrentAction(AppState &state) {
  Element title = text("Awaiting action...");

  if (state.currentAction == CurrentAction_FetchingPatches)
    title = text("Fetching for new patches...");
  else if (state.currentAction == CurrentAction_DownloadingPatches)
    title = text("Downloading patches...");
  else if (state.currentAction == CurrentAction_AplyingPatches)
    title = text("Aplying patches...");

  auto content = vbox({
      title,
      gauge(state.downloadState),
      filler(),
  });
  return window(text(L" Current Action "), content);
}
