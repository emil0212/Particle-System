#include "Engineoptions.h"

bool Engineopt::showWindow = false;

void Engineopt::RenderWindow() {
	if (!Engineopt::showWindow)
		return;

	static int page = 0;

	ImGui::SetNextWindowPos(ImVec2(12.0f, 30.0f));
	ImGui::SetNextWindowSize(ImVec2(310, 240));
	if (ImGui::Begin("Particle system", &Engineopt::showWindow, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove)) {

		const char* tabs[] = {
			"Particle settings", 
		};

		for (int i = 0; i < IM_ARRAYSIZE(tabs); i++) {

			if (ImGui::Button(tabs[i], ImVec2(ImGui::GetWindowSize().x / IM_ARRAYSIZE(tabs) - 11, 0)))
				page = i;

			if (i < IM_ARRAYSIZE(tabs) - 1)
				ImGui::SameLine();
		}

		ImGui::Separator();

		switch (page) {
		case 0:
			Particleoptions::RenderTab();
			break;
		}
		ImGui::End();
	}
}