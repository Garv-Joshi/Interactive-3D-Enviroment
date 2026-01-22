#include "Externals/raylib/src/raylib.h"
#include "Externals/raylib/src/rcamera.h"

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE|FLAG_VSYNC_HINT);

    InitWindow(0, 0, "Interactable 3D Enviroment");
    ToggleFullscreen();
    SetTargetFPS(120);

    

    Vector3 pos = {0.0f, 0.0f, 0.0f};

    Model model = LoadModel("resources/City_1.glb");
    Camera camera = { 0 };
    camera.position = (Vector3){ 0.0f, 3.0f, 8.0f };
    camera.target = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    

    
    DisableCursor();

    while(!WindowShouldClose())
    {

        UpdateCamera(&camera, CAMERA_FIRST_PERSON);
        BeginDrawing();
        ClearBackground(SKYBLUE);
        BeginMode3D(camera);
        DrawModel(model, pos, 0.009f, WHITE);
        EndMode3D();
        DrawText("Press ESC to end", 1700, 1050, 24, GREEN);
        DrawFPS(10,10);
        EndDrawing();
    }

    UnloadModel(model);
    CloseWindow();
    return 0;
}