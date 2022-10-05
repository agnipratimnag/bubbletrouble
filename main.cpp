#include <simplecpp>
#include <stdio.h>
#include "shooter.h"
#include "bubble.h"


/* Simulation Vars */
const double STEP_TIME = 0.02;

/* Game Vars */
const int PLAY_Y_HEIGHT = 450;
const int LEFT_MARGIN = 70;
const int TOP_MARGIN = 20;
const int BOTTOM_MARGIN = (PLAY_Y_HEIGHT+TOP_MARGIN);

// Score is set to 0 by default
int score = 0;

// X-Coordinate of health bars
int health_x = 355;


void move_bullets(vector<Bullet> &bullets){
    // move all bullets
    for(unsigned int i=0; i<bullets.size(); i++){
        if(!bullets[i].nextStep(STEP_TIME)){
            bullets.erase(bullets.begin()+i);
        }
    }
}

void move_bubbles(vector<Bubble> &bubbles){
    // move all bubbles
    for (unsigned int i=0; i < bubbles.size(); i++)
    {
        bubbles[i].nextStep(STEP_TIME);
    }
}



// Function to check for collision between bubble and shooter
void shooter_collision(vector<Bubble> &bubbles, Shooter shooter, vector<Rectangle> &healthbar)
    {
    for (unsigned int i=0;i<bubbles.size();i++)
        {
        double bubble_x2=bubbles[i].get_center_x();
        double bubble_y2=bubbles[i].get_center_y();

        double shooter_x=shooter.get_head_center_x();
        double shooter_y=shooter.get_body_center_y() - shooter.get_body_height()/2;

        // Variable dist stores the "distance" between bubble and shooter

        double dist = sqrt( (bubble_x2-shooter_x)*(bubble_x2-shooter_x)  + (bubble_y2-shooter_y)*(bubble_y2-shooter_y));


        // Variable d  stores the minimum possible value of space between bubble and shooter for which it is not a collision
        double a = bubbles[i].get_radius();
        double b = shooter.get_body_height();
        double c = shooter.get_body_width();
        double d = sqrt(b*b + c*c) + a;

        if (dist < d/2)
            {
            if(healthbar.size()>1)
                {

                // Bubble is erased and health is decreased by one

                bubbles.push_back(Bubble(WINDOW_X/2.0, BUBBLE_START_Y, bubbles[i].get_radius(), bubbles[i].get_vx(), bubbles[i].get_vy(),bubbles[i].get_ay(), bubbles[i].get_color()));
                bubbles.erase(bubbles.begin()+i);
                healthbar.pop_back();

                }
            else if (healthbar.size()==1)
                {

                // When health is 0, the game ends.

                healthbar.pop_back();
                string gameover("GAME OVER");
                Text endgame(WINDOW_X/2.0, BOTTOM_MARGIN, gameover);
                wait(500);


                }
            }
        }
    }

// Level 1 bubble creation

vector<Bubble> create_bubbles()
{
    // create initial bubbles in the game
    vector<Bubble> bubbles;
    bubbles.push_back(Bubble(WINDOW_X/2.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, -BUBBLE_DEFAULT_VX, BUBBLE_DEFAULT_VY,BUBBLE_DEFAULT_AY, COLOR(255,155,180)));
    bubbles.push_back(Bubble(WINDOW_X/4.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, BUBBLE_DEFAULT_VX, BUBBLE_DEFAULT_VY,BUBBLE_DEFAULT_AY, COLOR(255,155,180)));
    bubbles.push_back(Bubble(WINDOW_X/3.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, -BUBBLE_DEFAULT_VX, BUBBLE_DEFAULT_VY,BUBBLE_DEFAULT_AY, COLOR(255,155,180)));
    bubbles.push_back(Bubble(WINDOW_X/8.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, BUBBLE_DEFAULT_VX, BUBBLE_DEFAULT_VY,BUBBLE_DEFAULT_AY, COLOR(255,155,180)));
    return bubbles;
}

// Level 2 bubble creation

vector<Bubble> create_bubbles2()
{

    vector<Bubble> bubbles;
    bubbles.push_back(Bubble(WINDOW_X/2.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, -BUBBLE_DEFAULT_VX*2.0, BUBBLE_DEFAULT_VY,BUBBLE_DEFAULT_AY, COLOR(255,105,250)));
    bubbles.push_back(Bubble(WINDOW_X/4.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, BUBBLE_DEFAULT_VX, BUBBLE_DEFAULT_VY*1.8,BUBBLE_DEFAULT_AY, COLOR(255,105,250)));
    bubbles.push_back(Bubble(WINDOW_X/3.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, -BUBBLE_DEFAULT_VX*2.0, BUBBLE_DEFAULT_VY,BUBBLE_DEFAULT_AY*2.0, COLOR(255,105,250)));
    bubbles.push_back(Bubble(WINDOW_X/8.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, BUBBLE_DEFAULT_VX, BUBBLE_DEFAULT_VY*1.5,BUBBLE_DEFAULT_AY, COLOR(255,105,250)));
    return bubbles;
}

// Level 3 bubble creation


vector<Bubble> create_bubbles3()
{

    vector<Bubble> bubbles;
    bubbles.push_back(Bubble(WINDOW_X/2.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, -BUBBLE_DEFAULT_VX*3.0, BUBBLE_DEFAULT_VY*3.0,BUBBLE_DEFAULT_AY, COLOR(255,105,100)));
    bubbles.push_back(Bubble(WINDOW_X/4.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, BUBBLE_DEFAULT_VX, BUBBLE_DEFAULT_VY,BUBBLE_DEFAULT_AY*3.0, COLOR(255,105,100)));
    bubbles.push_back(Bubble(WINDOW_X/3.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, -BUBBLE_DEFAULT_VX*2.7, BUBBLE_DEFAULT_VY,BUBBLE_DEFAULT_AY*3.0, COLOR(255,105,100)));
    bubbles.push_back(Bubble(WINDOW_X/8.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, BUBBLE_DEFAULT_VX, BUBBLE_DEFAULT_VY*5.0,BUBBLE_DEFAULT_AY, COLOR(255,105,100)));
    return bubbles;
}


vector<Bubble> create_bubbles4()
{
    vector<Bubble> bubbles;
    bubbles.push_back(Bubble(WINDOW_X/2.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, -BUBBLE_DEFAULT_VX*4.5, BUBBLE_DEFAULT_VY,BUBBLE_DEFAULT_AY, COLOR(155,105,180)));
    bubbles.push_back(Bubble(WINDOW_X/4.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, BUBBLE_DEFAULT_VX*2.0, BUBBLE_DEFAULT_VY,BUBBLE_DEFAULT_AY*5.6, COLOR(155,105,180)));
    bubbles.push_back(Bubble(WINDOW_X/3.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, -BUBBLE_DEFAULT_VX, BUBBLE_DEFAULT_VY*5.0,BUBBLE_DEFAULT_AY*4.9, COLOR(155,105,180)));
    bubbles.push_back(Bubble(WINDOW_X/8.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, BUBBLE_DEFAULT_VX, BUBBLE_DEFAULT_VY*3.2,BUBBLE_DEFAULT_AY*5.5, COLOR(155,105,180)));
    return bubbles;
}


vector<Bubble> create_bubbles5()
{
    vector<Bubble> bubbles;
    bubbles.push_back(Bubble(WINDOW_X/2.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, -BUBBLE_DEFAULT_VX*6.0, BUBBLE_DEFAULT_VY,BUBBLE_DEFAULT_AY, COLOR(255,195,180)));
    bubbles.push_back(Bubble(WINDOW_X/4.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, BUBBLE_DEFAULT_VX, BUBBLE_DEFAULT_VY,BUBBLE_DEFAULT_AY*7.0, COLOR(255,195,180)));
    bubbles.push_back(Bubble(WINDOW_X/3.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, -BUBBLE_DEFAULT_VX, BUBBLE_DEFAULT_VY*6.0,BUBBLE_DEFAULT_AY*5.0, COLOR(255,195,180)));
    bubbles.push_back(Bubble(WINDOW_X/8.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, BUBBLE_DEFAULT_VX*5.5, BUBBLE_DEFAULT_VY,BUBBLE_DEFAULT_AY*5.5, COLOR(255,195,180)));
    return bubbles;
}



// Bubble bullet collision checking function
void collision_check(vector<Bubble> &bubbles, vector<Bullet> &bullets, int &level, int&time, int &t0, vector<Rectangle> &healthbar)
    {
    for(unsigned int i=0;i<bullets.size();i++)
        {
        for(unsigned int j=0;j<bubbles.size();j++)
            {
            double bubble_x=bubbles[j].get_center_x();
            double bubble_y=bubbles[j].get_center_y();
            double bullet_x=bullets[i].get_center_x();
            double bullet_y=bullets[i].get_center_y();

            //find distance between centre of bullet and bubble

            double dist = sqrt( (bubble_x-bullet_x)*(bubble_x-bullet_x)  + (bubble_y-bullet_y)*(bubble_y-bullet_y));

            double a = bubbles[j].get_radius();
            double b = bullets[i].get_width();
            double c = bullets[i].get_height();
            double d = sqrt(b*b + c*c) + a;

            //check for overlap and delete both bullet and bubble if there is

            if (dist < d/2)
                {
                bullets.erase(bullets.begin()+i);
                bubbles.erase(bubbles.begin()+j);
                score++;
                }


            if (bubbles.size()==0)
                {
                level++;
                healthbar.push_back(Rectangle(healthbar[healthbar.size()-1].getX()+35,500,30,10));
                healthbar[healthbar.size()-1].setColor(COLOR(0, 255, 0));
                healthbar[healthbar.size()-1].setFill(true);
                //health_x+=35;


                if (level==2)
                    {
                    bubbles = create_bubbles2();
                    time=t0-30;
                    }

                else if(level==3)
                    {
                    bubbles = create_bubbles3();
                    time=t0-60;
                    }

                else if(level==4)
                    {
                    bubbles = create_bubbles4();
                    time=t0-75;
                    }

                else if(level==5)
                    {
                    bubbles = create_bubbles5();
                    time=t0-100;
                    }


                }


            }
        }
    }


int main()
{
    initCanvas("Bubble Trouble", WINDOW_X, WINDOW_Y);

    Line b1(0, PLAY_Y_HEIGHT, WINDOW_X, PLAY_Y_HEIGHT);
    b1.setColor(COLOR(0, 0, 255));

    string msg_cmd("Cmd: _");
    Text charPressed(LEFT_MARGIN, BOTTOM_MARGIN, msg_cmd);

    string healthtext("Health: ");
    Text healthT(200,500, healthtext);

    //vector for health rectangles

    vector<Rectangle> healthbar;
    healthbar.push_back(Rectangle(250,500,30,10));
    healthbar.push_back(Rectangle(285,500,30,10));
    healthbar.push_back(Rectangle(320,500,30,10));
    for(int i=0;i<3;i++)
        {
        healthbar[i].setColor(COLOR(0, 255, 0));
        healthbar[i].setFill(true);
        }



    // Intialize the shooter
    Shooter shooter(SHOOTER_START_X, SHOOTER_START_Y, SHOOTER_VX);

    // Initialize the bubbles
    vector<Bubble> bubbles = create_bubbles();

    // Initialize the bullets (empty)
    vector<Bullet> bullets;

    XEvent event;

    int level=1;

    int t0=600;

    int time=t0;

    // Main game loop
    while (true)
    {

        // Score text
        string scoretext("Score:  ");
        char score_buf[32];
        sprintf(score_buf, "%d", score);
        scoretext+= score_buf;
        //scoreT.setMessage(scoretext);
        Text scoreT(450, 470, scoretext);

        if(score==20)
            {
            string win("CONGRATULATIONS, YOU WIN!");
            Text endgame(WINDOW_X/2.0, BOTTOM_MARGIN, win);
            wait(500);
            return 0;
            }



        // Timer text
        string timer("Time left: ");
        char timer_buf[32];
        sprintf(timer_buf, "%d", time/10);
        timer+= timer_buf;
        Text Timer(250,550, timer);



        bool pendingEvent = checkEvent(event);
        if (pendingEvent)
        {
            // Get the key pressed
            char c = charFromEvent(event);
            msg_cmd[msg_cmd.length() - 1] = c;
            charPressed.setMessage(msg_cmd);

            // Update the shooter
            if(c == 'a')
                shooter.move(STEP_TIME, true);
            else if(c == 'd')
                shooter.move(STEP_TIME, false);
            else if(c == 'w')
                bullets.push_back(shooter.shoot());
            else if(c == 'q')
                return 0;
        }

        // Update the bubbles
        move_bubbles(bubbles);

        // Update the bullets
        move_bullets(bullets);

        // Check for bubble bullet collision
        collision_check(bubbles,bullets, level, time, t0, healthbar);

        // Check for bubble shooter collision
        shooter_collision(bubbles, shooter, healthbar);

        // Update value of time counter
        time-=50*STEP_TIME;

        if(time==0)
            {
            string gameover("GAME OVER");
            Text endgame(WINDOW_X/2.0, BOTTOM_MARGIN, gameover);
            wait(500);
            return 0;
            }





        wait(STEP_TIME);

        if(healthbar.size()==0) return 0;
    }

}

