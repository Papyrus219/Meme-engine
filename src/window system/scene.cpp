#include"scene.hpp"
#include"window_manager.hpp"

using namespace meme;

void Scene::Assign_window_manager ( Window_manager& window_manager )
{
    assign_windows_manager = &window_manager;
}

void Scene::Close()
{
    if(assigned_window != nullptr)
    {
        assign_windows_manager->Free_window(window_id);
    }

    assign_windows_manager = nullptr;
}
