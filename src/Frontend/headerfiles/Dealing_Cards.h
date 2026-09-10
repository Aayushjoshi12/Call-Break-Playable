#pragma once
#include "RendererInterface.h"
#include "../../Backend/headerfiles/entities.h"
#include <vector>

struct AnimatedCard
{
    float x, y;
    float targetX, targetY;
    float startX,  startY;
    float progress;
    bool  done;
    bool  faceUp;
    const Card* card;
};

class DealAnimation
{
public:
    DealAnimation();
    void start(const Card* hand, int count);
    void update(float dt);
    void draw(Renderer& r);
    bool isDone() const;
    int getDealtCount() const;

private:
    std::vector<AnimatedCard> animCards;
    Texture2D cardTextures[52];
    int   currentCard;
    float dealDelay;
    float dealInterval;
    bool  finished;

    void buildTargets(const Card* hand, int count);
};