#include "raylib.h"

int main()
{   
    int speed{10};
    int direction{10};

    // windows dimensions
    int width{600};
    int height{400};
    InitWindow(width, height, "Axe Window");

    // circle coordinates
    int circle_X{100};
    int circle_y{200};
    int circle_radius{25};
    // circle edges
    int l_circle_x{circle_X - circle_radius};
    int r_circle_x{circle_X + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};

    // axe coordinates
    int axe_x{200};
    int axe_y{300};
    int axe_length{50};
    // axe edges
    int l_axe_X{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};

    bool collision_with_axe = 
                                (b_axe_y >= u_circle_y) && 
                                (u_axe_y <= b_circle_y) && 
                                (r_axe_x >= l_circle_x) && 
                                (l_axe_X <= r_circle_x);

    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        
        ClearBackground(WHITE);
        
        // game logic begins

        if (collision_with_axe)
        {
            DrawText("Game Over!", 400, 200, 20, BLACK);
        } else
        {   

            // update edges
            l_circle_x = circle_X - circle_radius;
            r_circle_x = circle_X + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;

            l_axe_X = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;

            // update collision with axe
            collision_with_axe = 
                                (b_axe_y >= u_circle_y) && 
                                (u_axe_y <= b_circle_y) && 
                                (r_axe_x >= l_circle_x) && 
                                (l_axe_X <= r_circle_x);
        
            DrawCircle(circle_X, circle_y, circle_radius, BLUE);
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, ORANGE);

            // move the axe
            axe_y += direction;
            if(axe_y > (height - axe_length) || axe_y < 0) {
                direction = -direction;
            }
            
            if(IsKeyDown(KEY_D) && circle_X < (width - circle_radius)) {
                circle_X += speed;
            }

            if(IsKeyDown(KEY_A) && circle_X > circle_radius) {
                circle_X -= speed;
            }
        }
        // game logic ends

        EndDrawing();
    }
    

}