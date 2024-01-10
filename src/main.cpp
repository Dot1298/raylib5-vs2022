#include "raylib.h"
#include "Math.h"

class Table
{
    //By default, all class variables are private and must be manually changed to public
public:
    float x, y;
    float width, height;
    float weight;
    float legWidth;
    float legHeight;
    int legs;
    Color color;
//Convert from function to method by removing the table parameter and refering to property
    void Draw()
    {
        //Top
        DrawRectangle(x, y, width, height, color);
        float spacing = width / legs;
        float legX = x;

        //Legs
        for (int i = 0; i < legs; i++)
        {
            DrawRectangle(legX, y, legWidth, legHeight, color);
            legX += spacing;

        }
    }

};

//Basically the start function in Unity
int main()
{
    Table woodTable;
    woodTable.color = DARKBROWN;

    const int screenWidth = 1280;
    const int screenHeight = 720;

    woodTable.height = 60.0f;
    woodTable.width = 200.0f;
    woodTable.x = screenWidth * 0.5f - woodTable.width * 0.5f;
    woodTable.y = screenHeight * 0.75 - woodTable.height;
    woodTable.legs = 4;
    woodTable.legWidth = 10.0f;
    woodTable.legHeight = woodTable.height * 3.0f;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);

    const char* sentence = "Cool stuff";

    //Basically the update function in Unity
    while (!WindowShouldClose()) //While window is still open, execute code
    {
        BeginDrawing();
        ClearBackground(VIOLET);
        DrawText(sentence, screenWidth * 0.5f, screenHeight * 0.5f, 20, WHITE);
        woodTable.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
