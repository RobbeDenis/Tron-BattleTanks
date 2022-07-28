#if _DEBUG
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include <RodEngine.h>
#include <ResourceManager.h>
#include <InputManager.h>
#include <GameObject.h>
#include <SceneManager.h>
#include <Scene.h>

#include <SoundTest.h>
#include <TextComponent.h>
#include <RenderComponent.h>
#include <FPSCounter.h>

#include "TronCommands.h"

void LoadGame();

std::shared_ptr<dae::GameObject> CreateFPSCounter(const glm::vec3& pos, const SDL_Color& color);

int main(int, char* []) 
{
	dae::RodEngine engine;
	engine.Initialize();

	dae::ResourceManager::GetInstance().Init("../Data/");
	dae::InputManager::GetInstance().AddController(0);

	LoadGame();

	engine.Run();

	return 0;
}

void LoadGame()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Test"); scene;
	auto& input = dae::InputManager::GetInstance(); input;

	std::shared_ptr<dae::GameObject> go; go;

	scene.Add(CreateFPSCounter({ 7.f, 7.f, 0.f }, { 40, 215, 67 }));

	input.AddKeyboardCommand({ SDL_SCANCODE_DOWN, dae::ButtonState::Down }, std::make_unique<Move>(0.f, -1.f), scene.GetIndex());
	input.AddKeyboardCommand({ SDL_SCANCODE_UP, dae::ButtonState::Down }, std::make_unique<Move>(0.f, 1.f), scene.GetIndex());
	input.AddKeyboardCommand({ SDL_SCANCODE_RIGHT, dae::ButtonState::Down }, std::make_unique<Move>(1.f, 0.f), scene.GetIndex());
	input.AddKeyboardCommand({ SDL_SCANCODE_LEFT, dae::ButtonState::Down }, std::make_unique<Move>(-1.f, 0.f), scene.GetIndex());

	dae::SceneManager::GetInstance().SetScene("Test");
}

std::shared_ptr<dae::GameObject> CreateFPSCounter(const glm::vec3& pos, const SDL_Color& color)
{
	auto go = std::make_shared<dae::GameObject>();
	auto pTextComponent = go.get()->AddComponent<dae::TextComponent>();
	pTextComponent->SetFont(dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 13), false);
	pTextComponent->SetText("", false);
	pTextComponent->SetColor(color);
	go->AddComponent<dae::RenderComponent>();
	auto pFpsCounter = go->AddComponent<dae::FPSCounter>();
	pFpsCounter->UseSmoothing(true);
	go->SetWorldPosition(pos);

	return go;
}