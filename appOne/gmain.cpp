#define _10
//123
#ifdef _123
#include"libOne.h"
class CHARACTER {
protected:   
    int Img = 0;
    float Px = 0, Py = 0, Angle = 0;
    float Vx = 0, Vy = 0, AngSpeed = 0;
public:
    void setImage(int img) {
        Img = img;
    }
    void init() {
        Px = width / 2;
        Py = height / 2;
        Angle = 0;
        Vx = 1;
        Vy = 1;
        AngSpeed = 0.01f;
    }
   virtual void move() {
        Angle += AngSpeed;
    }
    void draw() {
        rectMode(CENTER);
        image(Img, Px, Py, Angle);
    }
};
class PLAYER :public CHARACTER {
public:
    void move() {
        Px += Vx;
    }
};

class ENEMY :public CHARACTER {
public:
    void move() {
        Py += Vy;
    }
};

class ENEMY_BULLET :public CHARACTER{
};
void gmain() {
    window(1920, 1080, full);
    int playerImg = loadImage("assets\\player.png");
    int enemyImg = loadImage("assets\\enemy.png");
    int enemyBulletImg= loadImage("assets\\eBullet.png");


    PLAYER player;
    ENEMY enemy;
    ENEMY_BULLET eBullet;
    player.setImage(playerImg);
    enemy.setImage(enemyImg);
    eBullet.setImage(enemyBulletImg);

    const int num = 3;
    CHARACTER* chara[num];
    chara[0] = &player;
    chara[1]= &enemy;
    chara[2] = &eBullet;
    for (int i = 0; i < num; i++) {
        chara[i]->init();
    }
    while (notQuit) {
        for (int i = 0; i < num; i++) {
            chara[i]->move();
        }
        clear();
        for (int i = 0; i < num; i++) {
            chara[i]->draw();
        }
    }
}
#endif
//4
#ifdef _4
#include"libOne.h"
class ENEMY {
private:
    int Img;
    float Px, Py, Vx;
public:
    void setImage(int img) {
        Img = img;
    }
    void init() {
        Px = random() % (int)width;
        Py = random() % (int)height;
        Vx = random() % 5 + 1.0f;
    }
    void move() {
        Px += Vx;
    }
    void draw() {
        image(Img, Px, Py);
    }
};
void gmain() {
    window(1920, 1080, full);
    hideCursor();
    int enemyImg = loadImage("assets\\enemy.png");
    int num = 100;
    ENEMY* enemy = new ENEMY[num];
    for (int i = 0; i < num; i++) {
    enemy[i].setImage(enemyImg);
    enemy[i].init();
    }
    while (notQuit) {
        clear();
        for (int i = 0; i < num; i++) {
            enemy[i].move();
            enemy[i].draw();
        }
    }
    delete[] enemy;
}
#endif
//5
#ifdef _5
#include"libOne.h"
class BABY {
public:
    BABY() {
        textSize(200);
        text("Hello", 700, 300);
    }
    ~BABY() {
        textSize(200);
        text("GoodBye", 700, 600);
    }
};
void func() {
    BABY baby;
}
void gmain() {
    window(1920, 1080, full);
    BABY* baby = new BABY;
    delete baby;
    while (notQuit) {

    }
}
#endif
//6
#ifdef _6
#include"libOne.h"
#include"TAKO.h"
void gmain() {
    window(1920, 1080, full);
    int takoImg = loadImage("assets\\enemy.png");
    int num = 30;
    TAKO* tako = new TAKO[num];
    for (int i = 0; i < num; i++) {
        tako[i].setImage(takoImg);
        tako[i].init();
    }
    while (notQuit) {
        for (int i = 0; i < num; i++) {
        tako[i].move();
        tako[i].draw();
        }
    }
    delete[]tako;
}
#endif
//7
#ifdef _7
#include"libOne.h"
class FLOAT2 {
public:
    float x,y;
};
void set(FLOAT2& f2) {
    f2.x = 100;
    f2.y = 10;
}
void gmain() {
    window(1000, 1000,full);
    FLOAT2 pos;
    set(pos);

    printSize(200);
    print(pos.x);
    print(pos.y);
    while (notQuit) {

    }
}
#endif
//8
#ifdef _8
#include"libOne.h"
class FLOAT2 {
public:
    float x, y;
    FLOAT2(float x,float y) {
        this->x = x;
        this->y = y;
    }
};
void set(FLOAT2& f2) {
    f2.x = 100;
    f2.y = 10;
}
void gmain() {
    window(1000, 1000, full);
    FLOAT2 pos(100, 10);

    printSize(200);
    print(pos.x);
    print(pos.y);
    while (notQuit) {

    }
}
#endif
//9
#ifdef _9
#include"libOne.h"
class FLOAT2 {
public:
    float x=0, y=0;
    FLOAT2(){
    }
    FLOAT2(float x, float y) {
        this->x = x;
        this->y = y;
    }
};
void gmain() {
    window(1000, 1000, full);

    FLOAT2 pos[2] = {
         FLOAT2(100, 10),
         FLOAT2(200,20),
    };

    printSize(200);
    print(pos[1].x);
    print(pos[1].y);
    while (notQuit) {

    }
}
#endif
//10
#ifdef _10
#include"libOne.h"
class FLOAT2 {
public:
    float x = 0, y = 0;
    FLOAT2() {
    }
    FLOAT2(float x, float y) {
        this->x = x;
        this->y = y;
    }
    FLOAT2 operator- (FLOAT2& f2) {
        return FLOAT2(x - f2.x, y - f2.y);
    }
    FLOAT2 operator* (float f) {
        return FLOAT2(x * f, y * f);
    }
    void operator+=(const FLOAT2& f2) {
        x += f2.x;
        y += f2.y;
    }
    void normalize() {
        float mag = sqrt(x * x + y * y);
        x /= mag;
        y /= mag;
    }
};
void gmain() {
    window(1000, 1000, full);

    FLOAT2 pos(100, 10);
    FLOAT2 vec(200, 20);
    vec.normalize();
    pos += vec*5.0f;

    printSize(200);
    print(pos.x);
    print(pos.y);
    while (notQuit) {

    }
}
#endif